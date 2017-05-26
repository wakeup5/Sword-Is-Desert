#include "stdafx.h"
#include "BowEffect02.h"


BowEffect02::BowEffect02()
{
}


BowEffect02::~BowEffect02()
{

}
void BowEffect02::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.01f));

	VEC_SCALE scales;
	scales.push_back(0.5f);
	scales.push_back(0.1f);


	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/Sword2.png");

	cPartcleEmitter::Init(
		5000,				//�ִ� ��ƼŬ ��
		1000,				//�ʴ� ��ƼŬ �߻� ��
		0.3,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		0.6,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		D3DXVECTOR3(0,0,0),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0, 0, 0),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(0, 0, 0),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0, 0, 0), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		0.1,				//����ũ�� �ּҰ�
		0.2,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	StartEmission();
}
