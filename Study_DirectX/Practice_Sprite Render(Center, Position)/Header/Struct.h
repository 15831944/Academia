#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;	// ��ġ ����?!(��ǥ ����)
	D3DXVECTOR3 vDir;	// ���� ����(�����̸鼭 ������.)
	D3DXVECTOR3 vDirOrigin; // ���� ���� ó�� ����(����)
	D3DXVECTOR3 vSize;	// ũ��(����)

	D3DXMATRIX matScale;	// ũ�� ���
	D3DXMATRIX matRotZ;		// Rotaion Z-Axis(Z�� ����, ȸ�� ���)
	D3DXMATRIX matTrans;	// �̵� ���
	D3DXMATRIX matRevZ;
	D3DXMATRIX matWorld;	// ���� ���
} INFO;

typedef struct tagTextureInfo
{
	LPDIRECT3DTEXTURE9	pTexture;	// Texture COM ��ü(Texture ����)
	D3DXIMAGE_INFO		tImageInfo;	// Texture�� ���� �̹��� ����
} TEXTURE_INFO;

#endif