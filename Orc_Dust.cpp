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
	//배열을 2 개이상 
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

	//파티클 랜더러 셋팅
	cPartcleEmitter::Init(
		1000,				//최대 파티클 수
		100,				//초당 파티클 발생 량
		0.4,					//하나의 파티클 입자 라이프 최대값
		0.5,					//하나의 파티클 입자 라이프 최소값
		D3DXVECTOR3(-6, 0, -6),	//파티클 입자 속도 최소값 ( 로컬기준 )
		D3DXVECTOR3(6, 1, 6),	//파티클 입자 속도 최대값 ( 로컬기준 )
		D3DXVECTOR3(3, 0, 3),	//파티클 입자 가속 최소값 ( 로컬기준 )
		D3DXVECTOR3(5, 0, 5), //파티클 입자 가속 최대값 ( 로컬기준 )
		colors,				//컬러 배열
		scales,				//스케일 배열
		1.2f,				//입자크기 최소값
		1.5f,				//최대값
		pTex,				//텍스쳐
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	//	StartEmission();

}

