#pragma once


#define	FEPSILON		0.00001f

#define	ABS(a)					( ((a) < 0) ? (a) * -1 : (a) )
#define	FLOATEQUAL( a, b )		( ABS((a) - (b) ) < FEPSILON )
#define	FLOATZERO(a)			( ABS((a)) < FEPSILON )
#define	VECTORZERO(v)			( FLOATZERO((v).x) && FLOATZERO((v).y) && FLOATZERO((v).z) )

#define	ONE_RAD			(D3DX_PI / 180)
#define RAD(dgree)		(ONE_RAD * (dgree))

#define	RS(a,b)			DEVICE->SetRenderState((a),(b))		


//������ ����ü 
typedef struct tagRay {
	D3DXVECTOR3 origin;			//������ ���� ��ġ
	D3DXVECTOR3 direction;		//������ ���� ( ����ȭ �Ǿ��־�� �� )
}Ray, *LPRay;

typedef struct tagWindowSize
{
	float width;
	float height;

	tagWindowSize() {}
	tagWindowSize(float x, float y)
	{
		width = x;
		height = y;
	}
}WindowSize, *LPWindowSize;


namespace MyUtil
{
	POINT GetMousePos();						//���콺��ġ
	void SetMousePos(int x, int y);			//���콺��ġ ����

	float Clamp(float value, float min, float max);	//value ���� min max ���̷� ������
	float Clamp01(float value);						//value �� 0 ~ 1 ���Ϸ� ����
	float ClampMinusOnePlusOne(float value);			//value �� -1 ~ 1 ���Ϸ� ����

	//float ���� ���� 
	//( t �� 0 ~ 1 ������ ���� �޴µ�...)
	//( t �� 0 �ϼ��� from ����� ���� ���ϵǰ� )
	//( t �� 1 �ϼ��� to ����� ���� ���ϵȴ� )
	float Lerp(float from, float to, float t);

	//float ���� ���� �ݴ�
	//value ���� head �� rear ���̿� ������� ��ġ�� �ִ���
	//0~1 ������ ������ �����Ѵ�.
	float InverseLerp(float head, float rear, float value);

	//���� ���� ����
	D3DXVECTOR3 VecLerp(const D3DXVECTOR3& from, const D3DXVECTOR3& to, float t);

	//Random
	void SetRandomSeed();
	float RandomFloatRange(float min, float max);
	int RandomIntRange(int min, int max);

	//������ �븻�� ������ִ� �Լ�
	void ComputeNormal(
		D3DXVECTOR3* pNorams,			//����� ���� �븻���� �迭 ������ ( �븻������ �迭�� ���� ���� �迭�� ���� ���� )
		const D3DXVECTOR3* pVertices,	//��꿡 ���� ������ġ �迭 ������
		int verticesNum,				//���� ����
		const DWORD* pIndices,			//�ε��� �迭������ ( �ϴ� �ε����� DWORD �� �뵿�ܰ� )
		int indicesNum					//�ε��� �迭������ ����
		);

	float GetDistance(const D3DXVECTOR3 &p1, const D3DXVECTOR3 &p2);

	/*
	bool IntersectSphere(Ray r, Sphere &s);
	*/
	Ray GetRayByMousePos(float x, float y);

	bool IntersectPolygon(Ray r, D3DXVECTOR3 *arrVector, D3DXVECTOR3 *colisPos = NULL//���� ���� �浹�� ��ġ�� ���� ����
		);

	//ź��Ʈ�� ���̳븻 ���
	void ComputeTangentAngBinormal(
		D3DXVECTOR3* outTangets,			//��� Tangent �迭
		D3DXVECTOR3* outBinormals,			//��� Binormal �迭
		const D3DXVECTOR3* pPositions,		//���� ��ġ �迭
		const D3DXVECTOR3* pNormals,		//���� �븻 �迭
		const D3DXVECTOR2* pUVs,			//������ UV �迭
		const DWORD* pIndices,				//�ε��� �迭
		DWORD NumTris,						//�ﰢ�� ����		
		DWORD NumVertices 					//���� ����
		);


	//�÷��� ��Ʈ���� �ս����� ����ü DWORD ������ ��ȯ
	DWORD FloatToDWORD(float f);

	//�귯���� �ð� �� ������ �ð��� �� ��� true ����
	bool IsTimeMoment(float runningTime, float momentTime, float epsilon);
}