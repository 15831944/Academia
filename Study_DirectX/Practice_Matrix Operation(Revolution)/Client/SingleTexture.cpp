#include "stdafx.h"
#include "SingleTexture.h"


SingleTexture::SingleTexture()
{
}


SingleTexture::~SingleTexture()
{
	Release();
}

void SingleTexture::Release()
{
	// ####################################################
	// COM 객체부터 Release() 함수 호출하여 메모리 해제 !!!!
	// 그리고, Texture 생성 시, 장치에 대한 변수를 참조해서 생성하기 때문에
	// Reference Count 증가 !!!!
	// ####################################################

	if (m_pTextureInfo->pTexture->Release())
	{
		ERR_MSG(L"LPDIRECT3DTEXTURE9 Release Failed, SingleTexture::Release()");
	}

	SafeDelete(m_pTextureInfo);
}

HRESULT SingleTexture::LoadTexture(
	const wstring &wstrFilePath,
	const wstring &wstrStateKey /*= L""*/,
	const int &imageCount /*= 0*/)
{
	m_pTextureInfo = new TEXTURE_INFO;
	ZeroMemory(m_pTextureInfo, sizeof(TEXTURE_INFO)); // Texture는 "0" 초기화 하네?!

	HRESULT hr = 0;

	// D3DXGetImageInfoFromFile() - 사용할 이미지의 정보를 파일로부터 얻어오는 함수.
	// TCHAR 문자열 경로(wstring::c_str(), 이미지 정보 구조체의 포인터(D3DXIMAGE_INFO)
	hr = D3DXGetImageInfoFromFile(
		wstrFilePath.c_str(), &(m_pTextureInfo->tImageInfo)
	);
	FAILED_CHECK_MSG_RETURN(hr, L"D3DXGetImageInfoFromFile Failed, SingleTexture::LoadTexture()", E_FAIL);

	// D3DXCreateTextureFromFileEx() - Texture를 생성하는 작업
	hr = D3DXCreateTextureFromFileEx(
		DeviceManager::getInstance()->getDevice(),	// 그래픽 장치
		wstrFilePath.c_str(),						// 이미지 파일 경로(TCHAR 문자열)
		m_pTextureInfo->tImageInfo.Width,			// 이미지의 너비(가로 길이)
		m_pTextureInfo->tImageInfo.Height,			// 이미지의 높이(세로 길이 - 2D 이미지)
		m_pTextureInfo->tImageInfo.MipLevels,		// Mip Levels
		0, // ?!
		m_pTextureInfo->tImageInfo.Format,			// 이미지의 픽셀 포맷?!
		D3DPOOL_MANAGED,							// 메모리 사용 방식
		D3DX_DEFAULT,								// 이미지 Filter
		D3DX_DEFAULT,								// Mip Filter
		0,											// 제거할 색상의 "color key"
		nullptr,									// D3DIMAGE_INFO 구조체의 포인터(이미지 정보는 파일로부터 얻어오니 필요 없음)
		nullptr,									// 팔레트
		&m_pTextureInfo->pTexture					// LPDIRECT3DTEXTURE9 (Texture) COM 객체의 주소
	);
	FAILED_CHECK_MSG_RETURN(hr, L"D3DXCreateTextureFromFileEx Failed, SingleTexture::LoadTexture()", E_FAIL);


	return S_OK;
}

const TEXTURE_INFO* SingleTexture::getTextureInfo(
	const wstring &wstrStateKey /*= L""*/,
	const int &imageIndex /*= 0*/)
{
	return m_pTextureInfo;
}
