#pragma once
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

class Texture
{
public:
	Texture();
	virtual ~Texture();

public:
	virtual void Release() PURE; // 순수 가상함수 "= 0"의 매크로

public:
	// Single Texture : 이미지만 있고, 애니메이션 없음.
	// MultiTexture   : 애니메이션 존재.

	// MultiTexture는 "오브젝트 키"와 "상태 키" 둘 다 씁니다.
	// ex. 오브젝트 키 - Player, Effect, Terrain 등
	// ex. 상태 키 - Idle, Attack, Dash 등

	virtual HRESULT LoadTexture(
		const wstring &wstrFilePath,		// 이미지 파일 경로
		const wstring &wstrStateKey = L"",	// 상태 키
		const int &imageCount = 0			// 이미지 개수
	) PURE;

public:
	virtual const TEXTURE_INFO* getTextureInfo(
		const wstring &wstrStateKey = L"",	// 상태 키(Single 텍스쳐는 쓰지 않음.)
		const int &imageIndex = 0			// 이미지 인덱스(Single 텍스쳐는 쓰지 않음.)
	) PURE;

};

#endif