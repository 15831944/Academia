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
	// Texture을(를) 통해 상속됨
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