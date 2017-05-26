#include "stdafx.h"
#include "Dust.h"


Dust::Dust()

{
	
}


Dust::~Dust()
{
}
void Dust::Setup()
{

	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.01f));

	VEC_SCALE scales;
	scales.push_back(1.0f);
	scales.push_back(0.5f);


	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/dust.png");
	
	cPartcleEmitter::Init(
		1000,				//�ִ� ��ƼŬ ��
		5,				//�ʴ� ��ƼŬ �߻� ��
		0.5,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		0.6,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		D3DXVECTOR3(0.0, 0.0, 0),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.7, 0.0),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.0, 0),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0.0, 0.5, 0), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		1.5,				//����ũ�� �ּҰ�
		1.7,				//�ִ밪
		pTex,				//�ؽ���
		false);
	

	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	//StartEmission();
}


