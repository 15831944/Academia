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
	// IDirect3D9		 �� ��, IUnknown�� ��� �޴´�.
	// �׷��� ������ COM ��ü�� �Ҵ�Ǹ�, Reference Count�� ������ �ִ�.
	// ������ ������ �ش� COM ��ü�� ������ ������...
	// AddRef() �Լ��� ȣ��Ǿ� ���� ���� ��.
	// Release() �Լ��� ���� ���� ��Ų��.
	// ����, �� �Լ� ��� Reference Count�� ��ȯ �Ѵ�. (����� �뵵�� ���� �� ����)
	// So, ī��Ʈ ���� "0"�� �Ǹ� �ڵ����� COM ��ü�� �޸𸮰� �����ȴ� !!!!
	// ���� ���Ƿ� Delete ���ָ� �ȵȴ� !!!!
	// (new Ű����� ���� �Ҵ� ���ִ� ��ü���� �ƴϴϱ� !!!!)

	// m_pLine COM ��ü ���� ��, m_pGraphicDev�� �����ϱ� ������, ���� Release() �Լ� ȣ���Ѵ�.
	if (m_pLine->Release())
	{
		ERR_MSG(L"m_pLine Release Failed, DeviceManager::Release()");
	}

	// m_pSprite COM ��ü ���� ��, m_pGraphicDev�� �����ϱ� ������, ���� Release() �Լ� ȣ���Ѵ�.
	if (m_pSprite->Release())
	{
		ERR_MSG(L"m_pSprite Release Failed, DeviceManager::Release()");
	}

	// m_pGraphicDev COM ��ü ���� ��, mp_SDK�� �����ؼ� ����� ������, ���� Release() �Լ� ȣ���Ѵ�.
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
	// ��ġ �ʱ�ȭ ����
	// ################
	HRESULT hr = 0;

	// ##################################################################################################
	// step 1. IDirect3D9 ����

	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION); // �̰͵� "0" �ʱ�ȭ !!!!
											  // Application�� �ùٸ� ��� ���Ϸ� ����������� Ȯ���ϴ� ����

											  // ##################################################################################################
											  // 2. ��ġ ����
											  // - ���� ����� �׷��� ��ġ�� ������������� ����� �����ϴ���...
											  // - ���, ���÷��� ���, ���� ��� ���� �ý����� �׷��� ��ġ�� �����ϴ� Ư���� ���� ������ ��� ����.
											  // - IDirect3DDevice9 ��ü�� ����� ���ؼ�, ���� ��ġ�� �����ϴ� ���÷��� ���� ������ �̿��ؾ� �ϸ�...
											  //  IDirect3D9 ������ �޼ҵ带 �̿��Ͽ� ������ ���� �� �ִ�.

	D3DCAPS9	DeviceCaps;
	ZeroMemory(&DeviceCaps, sizeof(D3DCAPS9));

	// HAL (Hardware Abstraction Layer - �ϵ���� �߻� ����)
	hr = m_pSDK->GetDeviceCaps(
		D3DADAPTER_DEFAULT,	// Adapter - Ư���� ����� �ϴ� ���� ���÷��� ����� (������ �⺻ ���÷��� �����. ��, �����츦 ���� �ִ� �׷��� ī��)
		D3DDEVTYPE_HAL,		// ��ġ Ÿ�� - D3DDEVTYPE_HAL �ϵ����, DD3DDEVTYPE_REF ����Ʈ����
		&DeviceCaps			// �⺻ ���÷��� ������� Ư������ �ʱ�ȭ�� D3DCAPS9 ����ü ��.
	);
	FAILED_CHECK_MSG_RETURN(hr, L"GetDeviceCpas Failed, DeviceManager::InitDevice()", E_FAIL);


	// Vertex Processing ���� ���� �˻�.(���� �׷��� ī��)
	// - ������ȯ(Vertex Shader) + ������(Pixel Shader) !!!!
	DWORD vp = 0;

	// Default Display Adapter�� �����Ǵ� IDirect3DDevice9 ��ü�� ������ ��,
	// Vertex Processing ��带 �ݵ�� �����ؾ� �մϴ� !!!!
	// So, DWORD �ڷ��� ������ ���� ����ؼ� ���߿� ����.

	// ###############################
	// Flag(�÷��� ���� !!!! - bitwise(Ư�� ���� �������� "&
	if (DeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vp |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		vp |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}


	// ###############################################################################
	// step 3. IDirect3DDevice9 ����

	// D3DPRESENT_PARAMETERS ����ü�� ���� ä���
	// - ������� �ϴ� IDirect3DDevice9 ��ü�� ������ ������.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS)); // �̰͵� "0" �ʱ�ȭ !!!!

	d3dpp.BackBufferWidth = dwWinWidth;				// (�ȼ� ����)�� �ĸ� ���� �ʺ�
	d3dpp.BackBufferHeight = dwWinHeight;			// (�ȼ� ����)�� �ĸ� ���� ����
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;		// �ĸ� ���� �ȼ� ����?!
	d3dpp.BackBufferCount = 1;						// �ĸ� ���� ����

	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;	// �ĸ� ���ۿ� �̿��� ��Ƽ ���ø��� Ÿ��
	d3dpp.MultiSampleQuality = 0;					// ��Ƽ ���ø��� ����

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// SwapChain ���
	d3dpp.hDeviceWindow = hWnd;						// ������� ����� �� ���ø����̼� ������
	d3dpp.Windowed = eScreenMode; 					// (TRUE â���), (FALSE ��ü ȭ�� ���)
	d3dpp.EnableAutoDepthStencil = TRUE;			// Direct3D�� �ڵ����� ����/���ٽ� ���۸� ����� �����ϱ� ���ϴ°�.
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;	// ����/���ٽ� ������ ����

													//d3dpp.Flags = 0;	// �ĸ� ���۸� ��� �� �ְ� ����, �ĸ���� �ÿ��� �ڿ� ����/���ٽ� ���۸� ��������

													/* FullScreen_RefreshRateInHz must be zero for Windowed mode */
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;	// �����
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// �ÿ� ���� ����


																// ################################################################
																// �ʱ�ȭ�� D3DPRESENT_PARAMETERS ����ü�� �̿��Ͽ�...
																// ���������� IDirect3DDevice9 ��ü �����
	hr = m_pSDK->CreateDevice(
		D3DADAPTER_DEFAULT,	// Physical Display Adapter
		D3DDEVTYPE_HAL,		// Device Type
		hWnd,				// ��ġ�� ������� ������ ������. (d3dpp.hDeviceWindow = hWnd; �̰Ͱ� ���� !!!!)
		vp,					// Vertex Processing ����
		&d3dpp,				// ��ġ�� Ư�� �� �Ϻθ� �ʱ�ȭ�� D3DPRESENT_PARAMETERS ����ü�� ������
		&m_pGraphicDev		// ������ ��ġ�� ��ȯ ���� IDirect3DDevice9 ���� ������ !!!!
	);

	FAILED_CHECK_MSG_RETURN(hr, L"CreateDevice Failed, DeviceManager::InitDevice()", E_FAIL);

	// ################################################################
	// ���� ��ġ�� ��������� Sprite�� �������� �մϴ�.

	hr = D3DXCreateSprite(m_pGraphicDev, &m_pSprite);
	FAILED_CHECK_MSG_RETURN(hr, L"D3DXCreateSprite Failed, DeviceManager::InitDevice()", E_FAIL);

	hr = D3DXCreateLine(m_pGraphicDev, &m_pLine);
	FAILED_CHECK_MSG_RETURN(hr, L"D3DXCreateLine Failed, DeviceManager::InitDevice()", E_FAIL);

	return S_OK;
}

void DeviceManager::RenderBegin()
{
	// #############################
	// Rendering Process(������ ����)
	// #############################

	// step 1. �ĸ� ���۸� ����.
	m_pGraphicDev->Clear(
		0, nullptr,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
		D3DCOLOR_ARGB(255, 0, 0, 255), 1.0f, 0
	);

	// step 2. �ĸ� ���ۿ� �׸��� �׸��� �����Ѵ�.
	m_pGraphicDev->BeginScene();

	// Sprite�� �׸��� �׸��� ���ؼ� Begin()�� �ʿ��մϴ�.
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); // ���� ���� !!!!
}

void DeviceManager::RenderEnd()
{
	// step 3. �ĸ� ���ۿ� �׸� �׸��⸦ ������.
	// ������, Sprite �׸��⸦ ���� ����ϴ�.
	m_pSprite->End();

	m_pGraphicDev->EndScene();


	// step 4. �ĸ� ���۸� ���� ���۷� ��ȯ�ϰ�, �׷��� ����� �����ش�.
	m_pGraphicDev->Present(nullptr, nullptr, nullptr, nullptr);

	// ####################################################################
	// ����° ���� Window Handle�� ���� �׷��� �����츦 ������ �� �ִ� �κ�
	// ####################################################################

}
