#include "stdafx.h"
#include "BowEffect.h"


BowEffect::BowEffect()
{
}


BowEffect::~BowEffect()
{
}

void BowEffect::Setup()
{
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.7f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(3.5);
	scales.push_back(2);

	//cParticleQuad::GetParticleVertex(
	//	)

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/BowEffect02.png");

	cQuadParticleEmitter::Init(1, 0.5, 0.4,
		0.4,				//���̺� Ÿ��
		D3DXVECTOR3(0.0, 0.0, 0),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0.0),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0),	//�ʴ� ȸ�� ��
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		colors,
		scales,
		//�ʴ� ȸ�� ������
		1, 1,
		pTex,
		true
		);

	cQuadParticleEmitter::SetUVLength(6, 1, false);
}