#include "stdafx.h"
#include "effect_02.h"


effect_02::effect_02()
{
}


effect_02::~effect_02()
{
}

void effect_02::Setup()
{
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.3f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.1f));
	VEC_SCALE scales;
	scales.push_back(10);
	scales.push_back(10);

	//cParticleQuad::GetParticleVertex(
	//	)

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/EarthQuake.png");

	cQuadParticleEmitter::Init(50,50, 2,
		2,				//���̺� Ÿ��
		D3DXVECTOR3(0.0, 0.0, 0),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0.0),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0),	//�ʴ� ȸ�� ��
		D3DXVECTOR3(4.7, 0, 0),
		D3DXVECTOR3(4.7, 0, 0),
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

	//cQuadParticleEmitter::SetUVLength(7, 1, false);
	//StartEmission();

}
