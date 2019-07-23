#pragma once
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

class Texture
{
public:
	Texture();
	virtual ~Texture();

public:
	virtual void Release() PURE; // ���� �����Լ� "= 0"�� ��ũ��

public:
	// Single Texture : �̹����� �ְ�, �ִϸ��̼� ����.
	// MultiTexture   : �ִϸ��̼� ����.

	// MultiTexture�� "������Ʈ Ű"�� "���� Ű" �� �� ���ϴ�.
	// ex. ������Ʈ Ű - Player, Effect, Terrain ��
	// ex. ���� Ű - Idle, Attack, Dash ��

	virtual HRESULT LoadTexture(
		const wstring &wstrFilePath,		// �̹��� ���� ���
		const wstring &wstrStateKey = L"",	// ���� Ű
		const int &imageCount = 0			// �̹��� ����
	) PURE;

public:
	virtual const TEXTURE_INFO* getTextureInfo(
		const wstring &wstrStateKey = L"",	// ���� Ű(Single �ؽ��Ĵ� ���� ����.)
		const int &imageIndex = 0			// �̹��� �ε���(Single �ؽ��Ĵ� ���� ����.)
	) PURE;

};

#endif