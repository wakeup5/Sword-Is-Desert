#include "stdafx.h"
#include "Storm.h"


Storm::Storm()
{
}


Storm::~Storm()
{
}

void Storm::Setup()
{
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(0.0);
	scales.push_back(2.5);

	//cParticleQuad::GetParticleVertex(
	//	)

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/FireRing.png");

	cQuadParticleEmitter::Init(
	100,
		30,
		1.5f,
		2.0f,
		D3DXVECTOR3(-1, 1, -1),
		D3DXVECTOR3(1, 2, 1),
		D3DXVECTOR3(0, 2, 0),
		D3DXVECTOR3(0, 3, 0),
		D3DXVECTOR3(-90 * ONE_RAD, 0, 0),		//�ʱ���۽� ȸ��Min
		D3DXVECTOR3(-90 * ONE_RAD, 0, 0),     //�ʱ���۽� ȸ��Max
		D3DXVECTOR3(0, 0, 3),				//�ʴ� ȸ���� ȸ�� �� Min
		D3DXVECTOR3(0, 0, 4),				//�ʴ� ȸ���� ȭ�� �� Max
		D3DXVECTOR3(0, 0, 4),				//�ʴ� ȸ�� ���� Min
		D3DXVECTOR3(0, 0, 5),				//�ʴ� ȸ�� ���� Max
		colors, scales,
		2.5f, 2.5f,
		pTex,
		true);
}