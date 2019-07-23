#include "stdafx.h"
#include "DeviceManager.h"

IMPLEMENT_SINGLETON(DeviceManager);

DeviceManager::DeviceManager()
	: m_pSDK(nullptr), m_pGraphicDev(nullptr)
{

}

DeviceManager::~DeviceManager()
{
	Release();
}

void DeviceManager::Release()
{
	// IDirect3DDevice9
	// IDirect3D9		 둘 다, IUnknown을 상속 받는다.
	// 그렇기 떄문에 COM 객체가 할당되면, Reference Count를 가지고 있다.
	// 포인터 변수가 해당 COM 객체를 참조할 때마다...
	// AddRef() 함수가 호출되어 값이 증가 함.
	// Release() 함수는 값을 감소 시킨다.
	// 물론, 두 함수 모두 Reference Count를 반환 한다. (디버깅 용도로 쓰일 수 있음)
	// So, 카운트 값이 "0"이 되면 자동으로 COM 객체의 메모리가 해제된다 !!!!
	// 절대 임의로 Delete 해주면 안된다 !!!!
	// (new 키워드로 동적 할당 해주는 객체들이 아니니까 !!!!)


	// m_pSprite COM 객체 생성 시, m_pGraphicDev를 참조하기 때문에, 먼저 Release() 함수 호출한다.
	if (m_pSprite->Release())
	{
		ERR_MSG(L"m_pSprite Release Failed, DeviceManager::Release()");
	}

	// m_pGraphicDev COM 객체 생성 시, mp_SDK를 참조해서 만들기 때문에, 먼저 Release() 함수 호출한다.
	if (m_pGraphicDev->Release())
	{
		ERR_MSG(L"m_pGraphicDev Release Failed, DeviceManager::Release()");
	}

	if (m_pSDK->Release())
	{
		ERR_MSG(L"m_pSDK Release Failed, DeviceManager::Release()");
	}
}

HRESULT DeviceManager::InitDevice(
	HWND hWnd,
	const DWORD &dwWinWidth, const DWORD &dwWinHeight,
	SCREEN_MODE eScreenMode)
{
	// ################
	// 장치 초기화 과정
	// ################
	HRESULT hr = 0;

	// ##################################################################################################
	// step 1. IDirect3D9 생성

	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION); // 이것도 "0" 초기화 !!!!
											  // Application이 올바른 헤더 파일로 만들어졌는지 확인하는 과정

											  // ##################################################################################################
											  // 2. 장치 검증
											  // - 현재 사용할 그래픽 장치가 어느정도까지의 기능을 지원하는지...
											  // - 기능, 디스플레이 모드, 포맷 등과 같이 시스템의 그래픽 장치가 제공하는 특성에 대한 정보를 얻는 과정.
											  // - IDirect3DDevice9 객체를 만들기 위해서, 물리 장치가 지원하는 디스플레이 모드와 포맷을 이용해야 하며...
											  //  IDirect3D9 열거형 메소드를 이용하여 정보를 얻을 수 있다.

	D3DCAPS9	DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// HAL (Hardware Abstraction Layer - 하드웨어 추상 계층)
	hr = m_pSDK->GetDeviceCaps(
		D3DADAPTER_DEFAULT,	// Adapter - 특성을 얻고자 하는 물리 디스플레이 어댑터 (예제는 기본 디스플레이 어댑터. 즉, 윈도우를 띄우고 있는 그래픽 카드)
		D3DDEVTYPE_HAL,		// 장치 타입 - D3DDEVTYPE_HAL 하드웨어, DD3DDEVTYPE_REF 소프트웨어
		&DeviceCaps			// 기본 디스플레이 어댑터의 특성으로 초기화된 D3DCAPS9 구조체 얻어냄.
	);
	FAILED_CHECK_MSG_RETURN(hr, L"GetDeviceCpas Failed, DeviceManager::InitDevice()", E_FAIL);


	// Vertex Processing 지원 여부 검사.(현재 그래픽 카드)
	// - 정점변환(Vertex Shader) + 조명연산(Pixel Shader) !!!!
	DWORD vp = 0;

	// Default Display Adapter와 대응되는 IDirect3DDevice9 객체를 생성할 때,
	// Vertex Processing 모드를 반드시 지정해야 합니다 !!!!
	// So, DWORD 자료형 변수로 값을 기억해서 나중에 쓴다.

	// ###############################
	// Flag(플래그 연산 !!!! - bitwise(특성 값을 이진수로 "&
	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}


	// ###############################################################################
	// step 3. IDirect3DDevice9 생성

	// D3DPRESENT_PARAMETERS 구조체의 정보 채우기
	// - 만들고자 하는 IDirect3DDevice9 객체의 성격을 결정함.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS)); // 이것도 "0" 초기화 !!!!

	d3dpp.BackBufferWidth = dwWinWidth;				// (픽셀 단위)의 후면 버퍼 너비
	d3dpp.BackBufferHeight = dwWinHeight;			// (픽셀 단위)의 후면 버퍼 높이
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;		// 후면 버퍼 픽셀 포맷?!
	d3dpp.BackBufferCount = 1;						// 후면 버퍼 개수

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;	// 후면 버퍼에 이용할 멀티 샘플링의 타입
	d3dpp.MultiSampleQuality = 0;					// 멀티 샘플링의 레벨

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// SwapChain 방식
	d3dpp.hDeviceWindow = hWnd;						// 드로잉의 대상이 될 애플리케이션 윈도우
	d3dpp.Windowed = eScreenMode; 					// (TRUE 창모드), (FALSE 전체 화면 모드)
	d3dpp.EnableAutoDepthStencil = TRUE;			// Direct3D가 자동으로 깊이/스텐실 버퍼를 만들고 관리하길 원하는가.
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;	// 깊이/스텐실 버퍼의 포맷

													//d3dpp.Flags = 0;	// 후면 버퍼를 잠글 수 있게 지정, 후면버퍼 시연한 뒤에 깊이/스텐실 버퍼를 버릴건지

													/* FullScreen_RefreshRateInHz must be zero for Windowed mode */
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;	// 재생율
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// 시연 간격 조절


																// ################################################################
																// 초기화된 D3DPRESENT_PARAMETERS 구조체를 이용하여...
																// 실질적으로 IDirect3DDevice9 객체 만들기
	hr = m_pSDK->CreateDevice(
		D3DADAPTER_DEFAULT,	// Physical Display Adapter
		D3DDEVTYPE_HAL,		// Device Type
		hWnd,				// 장치가 드로잉을 수행할 윈도우. (d3dpp.hDeviceWindow = hWnd; 이것과 같다 !!!!)
		vp,					// Vertex Processing 종류
		&d3dpp,				// 장치의 특성 중 일부를 초기화한 D3DPRESENT_PARAMETERS 구조체의 포인터
		&m_pGraphicDev		// 생성된 장치를 반환 받을 IDirect3DDevice9 더블 포인터 !!!!
	);

	FAILED_CHECK_MSG_RETURN(hr, L"CreateDevice Failed, DeviceManager::InitDevice()", E_FAIL);

	// ################################################################
	// 이제 장치를 만들었으니 Sprite도 만들어줘야 합니다.

	hr = D3DXCreateSprite(m_pGraphicDev, &m_pSprite);
	FAILED_CHECK_MSG_RETURN(hr, L"D3DXCreateSprite Failed, DeviceManager::InitDevice()", E_FAIL);

	return S_OK;
}

void DeviceManager::RenderBegin()
{
	// #############################
	// Rendering Process(렌더링 과정)
	// #############################

	// step 1. 후면 버퍼를 비운다.
	m_pGraphicDev->Clear(
		0, nullptr,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
		D3DCOLOR_ARGB(255, 0, 0, 255), 1.0f, 0
	);

	// step 2. 후면 버퍼에 그림을 그리기 시작한다.
	m_pGraphicDev->BeginScene();

	// Sprite도 그림을 그리기 위해서 Begin()이 필요합니다.
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); // 알파 블렌드 !!!!
}

void DeviceManager::RenderEnd()
{
	// step 3. 후면 버퍼에 그림 그리기를 끝낸다.
	// 그전에, Sprite 그리기를 먼저 멈춥니다.
	m_pSprite->End();

	m_pGraphicDev->EndScene();


	// step 4. 후면 버퍼를 전면 버퍼로 전환하고, 그려진 장면을 보여준다.
	m_pGraphicDev->Present(nullptr, nullptr, nullptr, nullptr);

	// ####################################################################
	// 세번째 인자 Window Handle을 통해 그려줄 윈도우를 지정할 수 있는 부분
	// ####################################################################

}
