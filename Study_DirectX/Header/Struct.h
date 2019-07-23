#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct tagInfo
{
	D3DXVECTOR3 vPos;	// 위치 벡터?!(좌표 개념)
	D3DXVECTOR3 vDir;	// 방향 벡터(움직이면서 변동함.)
	D3DXVECTOR3 vDirOrigin; // 방향 벡터 처음 상태(기준)
	D3DXVECTOR3 vSize;	// 크기(배율)

	D3DXMATRIX matScale;	// 크기 행렬
	D3DXMATRIX matRotZ;		// Rotaion Z-Axis(Z축 자전, 회전 행렬)
	D3DXMATRIX matTrans;	// 이동 행렬
	D3DXMATRIX matRevZ;
	D3DXMATRIX matWorld;	// 월드 행렬
} INFO;

typedef struct tagTextureInfo
{
	LPDIRECT3DTEXTURE9	pTexture;	// Texture COM 객체(Texture 제어)
	D3DXIMAGE_INFO		tImageInfo;	// Texture의 실제 이미지 정보
} TEXTURE_INFO;

#endif