#include "stdafx.h"
#include "Effect_03.h"


Effect_03::Effect_03()
{
}


Effect_03::~Effect_03()
{
}

void Effect_03::Setup()
{
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));


	VEC_SCALE scales;
	scales.push_back(1);
	scales.push_back(8);

	//cParticleQuad::GetParticleVertex(
	//	)

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/ring.jpg");

	cQuadParticleEmitter::Init(1, 100, 0.3,
		0.3,				//���̺� Ÿ��
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
		



}
