#pragma once
#ifndef _DEVICE_MANAGER_H_
#define _DEVICE_MANAGER_H_

class DeviceManager
{
	DECLARE_SINGLETON(DeviceManager);

private:
	DeviceManager();
	~DeviceManager();

public:
	enum SCREEN_MODE {
		FULLSCREEN,
		WINDOWED
	};

public:
	void Release();

public:
	HRESULT InitDevice(
		HWND hWnd,
		const DWORD &dwWinWidth, const DWORD &dwWinHeight,
		SCREEN_MODE eScreenMode
	);

	void RenderBegin();
	void RenderEnd();

public:
	LPDIRECT3DDEVICE9 getDevice() const { return m_pGraphicDev; }
	LPD3DXSPRITE getSprite() const { return m_pSprite; }
	LPD3DXLINE getLine() const { return m_pLine; }

private:
	// ###############################################################################################################
	// ### Direct3D
	// - 3D 가속 하드웨어를 이용하여, 3D 공간을 표현할 수 있도록 해주는 저수준 그래픽 API(Application Programming Interface)

	// Application -> Direct3D -> HAL -> Graphic Device

	// Direct3D의 기능이 모든 그래픽 하드웨어에서 지원할 것이라는 생각은 No !!!!
	// So, Direct3D와 그래픽 장치 사이에 HAL(Hardware Abstraction Layer - 하드웨어 추상 계층)이 존재한다.
	// - 제조사가 다른 그래픽 카드들은 다양한 방법으로 동작하기 때문에, Direct3D가 직접 그래픽 장치를 제어할 수 없다.
	//  제조사에게 HAL(최소한의 공통된 기능)을 구현하도록 요구한다.
	// So, Direct3D가 각 장치의 세부적인 부분을 제어할 필요가 없어지고, (하드웨어에 독립적)일 수가 있다 !!!!

	// REF(Reference Rasterizer) 장치
	// - 그래픽 장치가 지원하지는 않지만, Direct3D에서 제공하는 기능을 이용해야 할 때 !!!!
	//  Direct3D API의 모든 기능을 소프트웨어로 수행할 수 있는 장치?!

	// D3DDEVTYPE 열거형 (장치 생성 시 반드시 필요하며, 장치의 타입 설정하는 enum 멤버)
	// - HAL 장치는 D3DDEVTYPE_HAL 로 지정됨.
	// - REF 장치는 D3DDEVTYPE_REF 로 지정됨.

	// COM(Component Object Model)
	// - DirectX를 (프로그래밍 언어에 독립적)이고, 하위 호환성을 갖출 수 있게 하는 기술 !!!!
	// - COM 객체를 인터페이스라고 부른다.
	// - 다른 COM 인터페이스의 메소드나 특수한 함수를 통해 COM 인터페이스의 포인터를 얻는다 ?!
	// - new 키워드로 인터페이스를 만드는 것이 아니며, 사용이 끝나면 반드시 인터페이스의 Release() 메소드를 호출.
	// So, COM 객체는 자신의 메모리 관리를 스스로 수행한다 !!!!

	// 표면(Surface)
	// - 2D 이미지 데이터를 보관하는 데 이용되는 픽셀(Surface의 요소)의 행렬
	// - 선형 배열에 보관된다.
	// - Surface의 너비와 높이는 (픽셀 단위)로 계산.
	// - 피치는 바이트로 계산되며 너비보다 길 수도 있다 !!!!
	// - IDirect3DSurface9 인터페이스로 표면을 이용할 수 있다.
	// 함수함수함수들...

	// 멀티 샘플링(MultiSampling)
	// - Pixel Matrix로 이미지를 표현할 때, 거친 이미지를 부드럽게 만드는 데 이용되는 기술.
	// 전화면 Anti-Aliasing을 위한 표면 멀티 샘플링이 있다.
	// - D3DMULTISAMPLE_TYPE 열거형 - 멀티 샘플링 레벨 지정 (D3DMULTISAMPLE_NONE, 부하가 심하기 때문에 !!!!)
	// - 멀티 샘플링 타입과 연결된 품질 레벨 (DWORD - "0")

	// 픽셀 포맷(Pixel Format)
	// Surface나 Texture를 만들기 위해서 Pixel Format을 지정해야 한다.
	// D3DFORMAT 열거형 멤버 - D3DFMT_A8R8G8B8 (32 비트 픽셀 포맷, 8비트씩 알파,레드,그린,블루)
	// 열거형 멤버멤버멤버멤버...

	// 메모리 풀(Memory Pool)
	// - 포면이나 그 밖의 다양한 Direct3D 자원들은 Memory Pool에 보관된다.
	// 열거형 멤버멤버멤버멤버...

	// 스왑 체인(Swap Chain)과 페이지 플리핑(Page Flipping)
	// - (보통 2~ 3개의 Surface를 하나의 컬렉션)으로 관리한다. (스왑 체인이라고 부름?!)
	// IDirect3DSwapChain9 인터페이스를 통해 이용할 수 있지만, 대부분의 작업은 Direct3D가 직접 관리.
	// - Frame 간의 부드러운 애니메이션을 제공하기 위해 Swap Chain, Page Flipping 기술이 쓰인다.
	// ex. 2개의 Surface 사이의 Swap Chain
	// Surface 1 - 전면 버퍼 (현재 모니터에서 버퍼의 내용이 보여지고 있는 버퍼)
	// Surface 2 - 후면 버퍼 (현재 처리중인 프레임이 보관되는 버퍼

	// - 모니터가 전면 버퍼의 이미지를 즉각적으로 보여줄 수 있는 것은 아니며,
	// 60Hz의 재생률의 모니터는 1/60초 정도의시간이 필요하다.
	// - Application의 프레임율과 모니터의 재생율이 동기화 되지 않는 경우,(Application의 프레임 렌더링이 더 빠를 수...)
	// 현재 프레임을 완전히 디스플레이 하지 못한 상태에서 애니메이션의 다음 프레임으로 갱신하는 것은 X...
	// 그렇다고 전면 버퍼의 디스플레이를 마칠 때까지 렌더링을 멈추는 것도 X...
	//  So, 화면 밖의 Surface(후면 버퍼)에 렌더링을 수행하고, 전면 버퍼 Surface의 디스플레이가 완료되면,
	// Swap Chain의 끝으로 돌아가 후면 버퍼를 전면 버퍼로 전환하는 방법을 이용하여 해결합니다 !!!!
	// 이 과정을 "Presenting - 시연"이라고 합니다.
	// 또한, 후면 버퍼가 전면 버퍼가 되고, 전면 버퍼가 후면 버퍼가 되는 한 cycle을 "Page Flipping - 페이지 플리핑"이라고 합니다.
	// ##################################
	// So, Swap Chain과 Page Flipping과정
	// ##################################
	// 후면 버퍼 렌더링 - 후면 버퍼 시연(전면 버퍼가 된다) - 스왑 체인의 뒷부분으로 넘어간다.


	// 깊이 버퍼(Depth Buffer)
	// - 이미지 데이터가 아닌 특정 픽셀의 깊이 정보를 포함하는 Surface를 말합니다.
	// - 최종 렌더링된 이미지의 각 픽셀에 해당하는 항목을 포함합니다.
	// - Direct3D는 물체의 픽셀이 다른 픽셀을 가리는지 여부를 위해, "깊이 버퍼링(Depth Buffering), Z-Buffering"을 사용합니다.

	// 깊이 버퍼링(Depth Buffering, Z-Buffering)
	// - 각 픽셀의 깊이 값을 계산하고, 깊이 테스트를 수행합니다.
	// 이 과정에서는 특정 픽셀의 위치에서 경쟁하는 픽셀의 깊이를 비교합니다.
	// - (카메라와 가장 가까운 깊이 값)을 가지는 픽셀이 이미지에 그려집니다 !!!!
	// - 깊이 값은 최소 "0"~ 최대 "1"까지 부동소수점 수로 변경 됩니다...(초기화는 무조건 1.0f)
	// - 깊이 버퍼의 포맷은 깊이 테스트의 정확도를 의미합니다. (Direct3D는 32비트 깊이 버퍼를 제공하지만...)
	//  D3dFMT_D24S8을 주로 사용합니다. (24bits 깊이 버퍼, 8bits Stencil 버퍼)

	// Vertex Processing
	// - Vertex는 3D 기하 물체를 구성하는 기본 단위입니다.
	// 처리 방식은 하드웨어 또는 소프트웨어의 방법...
	// - 그래픽 카드가 Hardware Vertex Processing을 지원한다는 말은...
	//  변환(Transformation)과 조명 계산(Lighting)을 하드웨어적으로 처리할 수 있다는 의미.

	// 장치 특성
	// - Direct3D의 모든 기능들은 D3DCAPS9 구조체의 데이터 멤버에 대응됩니다.
	// So, 장착하고 있는 하드웨어의 특성에 따라 D3DCAPS9 인스턴스의 멤버를 초기화 해서,
	// Application은 D3DCAPS9 인스턴스의 데이터를 확인하여 장치가 특정 기능을 제공하는지 알 수 있습니다.

	// ex. Hardware Vertex Processing 지원 여부 판단
	// - D3DCAPS9::DevCaps의 데이터 멤버에서 D3DDEVCAPS_HWTRANSFORMANDLIGHT 비트를 찾으면 된다.

	// cf) DevCaps ( Device Capabilities)

	// ###############################################################################################################

	// Direct3D 초기화 과정
	// step 01. IDirect3D9 인터페이스의 포인터 얻는다.

	// step 02. "Default Display Adapter"가 Hardware Vertex Processing을 지원하는지, D3DCAPS9 구조체를 확인한다.

	// step 03. D3DPRESENT_PARAMETERS 구조체 인스턴스를 초기화한다. (만들고자 하는 IDirect3DDevice9 인스턴스의 특성 지정)

	// step 04. IDirect3DDevice9 객체를 만든다. (초기화된 D3DPRESENT_PARAMETERS에 따라서...)

	// ###############################################################################################################


	// IDirect3D9	- 장치검증(시스템의 하드웨어에 대항 정보, 기능을 지원하는지 여부 확인)
	//				- IDirect3DDevice9 COM 객체를 생성하는 COM 객체.
	LPDIRECT3D9				m_pSDK;

	// IDirect3DDevice9 - 그래픽 장치를 제어하는 COM 객체.
	//					- 3D 그래픽을 디스플레이하는 데 이용될 물리 하드웨어 장치.
	LPDIRECT3DDEVICE9		m_pGraphicDev;

	// ID3DXSprite	- Direct에서 2D 이미지 렌더링에 필요한 COM 객체
	LPD3DXSPRITE			m_pSprite;

	// ID3DXLine - Line 렌더링에 필요한 COM 객체
	LPD3DXLINE				m_pLine;

	// COM (Component Object Model) - 모든 것은 COM 객체?!
};

#endif