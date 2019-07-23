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
	// COM ��ü���� Release() �Լ� ȣ���Ͽ� �޸� ���� !!!!
	// �׸���, Texture ���� ��, ��ġ�� ���� ������ �����ؼ� �����ϱ� ������
	// Reference Count ���� !!!!
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
	ZeroMemory(m_pTextureInfo, sizeof(TEXTURE_INFO)); // Texture�� "0" �ʱ�ȭ �ϳ�?!

	HRESULT hr = 0;

	// D3DXGetImageInfoFromFile() - ����� �̹����� ������ ���Ϸκ��� ������ �Լ�.
	// TCHAR ���ڿ� ���(wstring::c_str(), �̹��� ���� ����ü�� ������(D3DXIMAGE_INFO)
	hr = D3DXGetImageInfoFromFile(
		wstrFilePath.c_str(), &(m_pTextureInfo->tImageInfo)
	);
	FAILED_CHECK_MSG_RETURN(hr, L"D3DXGetImageInfoFromFile Failed, SingleTexture::LoadTexture()", E_FAIL);

	// D3DXCreateTextureFromFileEx() - Texture�� �����ϴ� �۾�
	hr = D3DXCreateTextureFromFileEx(
		DeviceManager::getInstance()->getDevice(),	// �׷��� ��ġ
		wstrFilePath.c_str(),						// �̹��� ���� ���(TCHAR ���ڿ�)
		m_pTextureInfo->tImageInfo.Width,			// �̹����� �ʺ�(���� ����)
		m_pTextureInfo->tImageInfo.Height,			// �̹����� ����(���� ���� - 2D �̹���)
		m_pTextureInfo->tImageInfo.MipLevels,		// Mip Levels
		0, // ?!
		m_pTextureInfo->tImageInfo.Format,			// �̹����� �ȼ� ����?!
		D3DPOOL_MANAGED,							// �޸� ��� ���
		D3DX_DEFAULT,								// �̹��� Filter
		D3DX_DEFAULT,								// Mip Filter
		0,											// ������ ������ "color key"
		nullptr,									// D3DIMAGE_INFO ����ü�� ������(�̹��� ������ ���Ϸκ��� ������ �ʿ� ����)
		nullptr,									// �ȷ�Ʈ
		&m_pTextureInfo->pTexture					// LPDIRECT3DTEXTURE9 (Texture) COM ��ü�� �ּ�
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
