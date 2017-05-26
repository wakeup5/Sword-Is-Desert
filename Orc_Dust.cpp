#include "stdafx.h"
#include "Orc_Dust.h"


Orc_Dust::Orc_Dust()
{
}


Orc_Dust::~Orc_Dust()
{
}

void Orc_Dust::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(0.0f);
	scales.push_back(1.0f);
	scales.push_back(1.0f);
	scales.push_back(1.0f);
	scales.push_back(0.2f);

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/dust.png");

	//��ƼŬ ������ ����
	cPartcleEmitter::Init(
		1000,				//�ִ� ��ƼŬ ��
		100,				//�ʴ� ��ƼŬ �߻� ��
		0.4,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		0.5,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		D3DXVECTOR3(-6, 0, -6),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(6, 1, 6),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(3, 0, 3),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(5, 0, 5), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		1.2f,				//����ũ�� �ּҰ�
		1.5f,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	//	StartEmission();

}

