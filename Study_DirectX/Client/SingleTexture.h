#pragma once
#ifndef _SINGLE_TEXTURE_H_
#define _SINGLE_TEXTURE_H_

#include "Texture.h"

class SingleTexture : public Texture
{
public:
	SingleTexture();
	virtual ~SingleTexture();

public:
	// Texture��(��) ���� ��ӵ�
	virtual void Release() override;

public:
	virtual HRESULT LoadTexture(
		const wstring &wstrFilePath,
		const wstring &wstrStateKey = L"",
		const int &imageCount = 0
	) override;

public:
	virtual const TEXTURE_INFO* getTextureInfo(
		const wstring &wstrStateKey = L"",
		const int &imageIndex = 0
	) override;

private:
	TEXTURE_INFO *m_pTextureInfo;

};


#endif