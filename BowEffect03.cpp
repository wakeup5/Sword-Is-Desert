#include "stdafx.h"
#include "BowEffect03.h"


BowEffect03::BowEffect03()
{
}


BowEffect03::~BowEffect03()
{
}

void BowEffect03::Setup()
{
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));


	VEC_SCALE scales;
	scales.push_back(0);
	scales.push_back(2);
	//cParticleQuad::GetParticleVertex(
	//	)

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/BowEffect03.png");

	cQuadParticleEmitter::Init(1, 1, 0.2,
		0.2,				//���̺� Ÿ��
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

	StartEmission();
}