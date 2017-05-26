#include "stdafx.h"
#include "PC_UFX.h"


PC_UFX::PC_UFX()
{
}


PC_UFX::~PC_UFX()
{
}

void PC_UFX::Setup()
{
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	
	VEC_SCALE scales;
	scales.push_back(0.5);
	scales.push_back(3);

	//cParticleQuad::GetParticleVertex(
	//	)

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/FireRing.png");

	cQuadParticleEmitter::Init(
		200,
		200,
		0.4f,
		0.6f,
		D3DXVECTOR3(-1, 1.5, -1),
		D3DXVECTOR3(1, 8, 1),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(-90 * ONE_RAD, 0,0),		//�ʱ���۽� ȸ��Min
		D3DXVECTOR3(-90 * ONE_RAD, 0, 0),     //�ʱ���۽� ȸ��Max
		D3DXVECTOR3(0, 0, 4),				//�ʴ� ȸ���� ȸ�� �� Min
		D3DXVECTOR3(0, 0, 5),				//�ʴ� ȸ���� ȭ�� �� Max
		D3DXVECTOR3(0, 0, 5),				//�ʴ� ȸ�� ���� Min
		D3DXVECTOR3(0, 0, 6),				//�ʴ� ȸ�� ���� Max
		colors, scales,
		3.0f, 3.0f,
		pTex,
		true);

}