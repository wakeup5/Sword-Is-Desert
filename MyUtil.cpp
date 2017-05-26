#include "StdAfx.h"
#include "MyUtil.h"
#include <functional>
#include <random>
#include <ctime>
#include <iostream>
namespace MyUtil
{
	//���콺��ġ
	POINT GetMousePos()
	{
		POINT mousePos;
		GetCursorPos(&mousePos);	//���콺 Screen ���� ��ġ�� ����ش�.

		//Screen ���� ��ġ�� Client ������ ������ �ٲ۴�.
		ScreenToClient(hWnd, &mousePos);

		return mousePos;
	}

	//���콺��ġ ����
	void SetMousePos(int x, int y)
	{
		POINT setMousePos;
		setMousePos.x = x;
		setMousePos.y = y;

		//Client ���� ��ġ�� Screen ������ ������ �ٲ۴�.
		ClientToScreen(hWnd, &setMousePos);

		//SetCursorPos ��   Screen ���� ��ġ�� �����ؾ��Ѵ�.
		SetCursorPos(setMousePos.x, setMousePos.y);
	}

	//value ���� min max ���̷� ������
	float Clamp(float value, float min, float max)
	{
		if (value < min)
			return min;
		else if (value > max)
			return max;

		return value;

	}

	//value �� 0 ~ 1 ���Ϸ� ����
	float Clamp01(float value)
	{
		if (value < 0.0f)
			return 0.0f;
		else if (value > 1.0f)
			return 1.0f;

		return value;
	}

	float ClampMinusOnePlusOne(float value)
	{
		if (value < -1.0f)
			return -1.0f;
		else if (value > 1.0f)
			return 1.0f;

		return value;
	}

	//float ���� ���� 
	//( t �� 0 ~ 1 ������ ���� �޴µ�...)
	//( t �� 0 �ϼ��� from ����� ���� ���ϵǰ� )
	//( t �� 1 �ϼ��� to ����� ���� ���ϵȴ� )
	float Lerp(float from, float to, float t)
	{
		t = Clamp01(t);

		float delta = to - from;

		return (delta * t) + from;
	}

	//float ���� ���� �ݴ�
	//value ���� head �� rear ���̿� ������� ��ġ�� �ִ���
	//0~1 ������ ������ �����Ѵ�.
	//						 5			 9			7 
	float InverseLerp(float head, float rear, float value)
	{
		float delta = rear - head;			// 4
		float inValue = value - head;		// 2

		if (inValue < 0)
			inValue = 0;

		return inValue / delta;
	}

	//���� ���� ����
	D3DXVECTOR3 VecLerp(const D3DXVECTOR3& from, const D3DXVECTOR3& to, float t)
	{
		D3DXVECTOR3 result(
			Lerp(from.x, to.x, t),
			Lerp(from.y, to.y, t),
			Lerp(from.z, to.z, t));

		return result;
	}

	//Random
	void SetRandomSeed()
	{
		srand(GetTickCount());
	}

	float RandomFloatRange(float min, float max)
	{
		//0 ~ 99999
		// 0 ~ 1 ������ �Ǽ�

		float factor = (rand() % 1001) * 0.001f;

		float delta = (max - min);

		float result = (delta * factor) + min;

		return result;

	}
	int RandomIntRange(int min, int max)
	{
		int delta = max - min;
		mt19937 engine((unsigned int)time(NULL));                    // MT19937 ���� ����
		uniform_int_distribution<int> distribution(min, max);       // ���� ����
		auto generator = bind(distribution, engine);
		return generator();
	}

	//������ �븻�� ������ִ� �Լ�
	void ComputeNormal(
		D3DXVECTOR3* pNorams,			//����� ���� �븻���� �迭 ������ ( �븻������ �迭�� ���� ���� �迭�� ���� ���� )
		const D3DXVECTOR3* pVertices,	//��꿡 ���� ������ġ �迭 ������
		int verticesNum,				//���� ����
		const DWORD* pIndices,			//�ε��� �迭������ ( �ϴ� �ε����� DWORD �� �뵿�ܰ� )
		int indicesNum					//�ε��� �迭������ ����
		)
	{
		//�븻 ��� �а� ����
		ZeroMemory(pNorams, sizeof(D3DXVECTOR3) * verticesNum);


		//�ﰢ�� ����
		DWORD triNum = indicesNum / 3;
		for (DWORD i = 0; i < triNum; i++)
		{
			//�ش� �ﰢ���� ���� �ε���
			DWORD i0 = pIndices[(i * 3) + 0];
			DWORD i1 = pIndices[(i * 3) + 1];
			DWORD i2 = pIndices[(i * 3) + 2];

			//���� 3��
			D3DXVECTOR3 v0 = pVertices[i0];
			D3DXVECTOR3 v1 = pVertices[i1];
			D3DXVECTOR3 v2 = pVertices[i2];

			//Edge
			D3DXVECTOR3 edge1 = v1 - v0;
			D3DXVECTOR3 edge2 = v2 - v0;

			//Cross
			D3DXVECTOR3 cross;
			D3DXVec3Cross(&cross, &edge1, &edge2);

			//Normal
			D3DXVECTOR3 normal;
			D3DXVec3Normalize(&normal, &cross);

			//���� ��Ų��.
			pNorams[i0] += normal;
			pNorams[i1] += normal;
			pNorams[i2] += normal;
		}

		//���� ������ Normalvector ����ȭ�Ѵ�.
		for (DWORD i = 0; i < verticesNum; i++)
		{
			D3DXVec3Normalize(&pNorams[i], &pNorams[i]);
		}
	}

	float GetDistance(const D3DXVECTOR3 &p1, const D3DXVECTOR3 &p2)
	{
		D3DXVECTOR3 temp = p2 - p1;
		return sqrt((temp.x * temp.x) + (temp.y * temp.y) + (temp.z * temp.z));
	}

	/*
	bool IntersectSphere(Ray r, Sphere &s)
	{
		D3DXMATRIXA16 matPos, matPosInv;
		D3DXMatrixTranslation(&matPos, s.x, s.y, s.z);

		D3DXMatrixInverse(&matPosInv, NULL, &matPos);

		D3DXVec3TransformCoord(&r.origin, &r.origin, &matPosInv);
		D3DXVec3TransformCoord(&r.origin, &r.origin, &matPosInv);

		float b = D3DXVec3Dot(&r.origin, &r.direction);
		float a = D3DXVec3Dot(&r.direction, &r.direction);
		float c = (r.origin.x * r.origin.x + r.origin.y * r.origin.y + r.origin.z * r.origin.z) - (s.radius * s.radius);

		if (b * b - a * c >= 0) return true;

		return false;
	}
	*/

	Ray GetRayByMousePos(float x, float y)
	{
		Ray result;
		float px, py;

		D3DVIEWPORT9 vp;
		D3DXMATRIXA16 proj, view, viewInv;
		//����Ʈ�� ���� ������ �̿��ؼ� ī�޶� ��ǥ�� ��´�.
		DEVICE->GetViewport(&vp);
		DEVICE->GetTransform(D3DTS_PROJECTION, &proj);

		px = (((2.0f * x) / vp.Width) - 1.0f) / proj._11;
		py = (((-2.0f * y) / vp.Height) + 1.0f) / proj._22;

		result.origin = D3DXVECTOR3(0, 0, 0);
		result.direction = D3DXVECTOR3(px, py, 1);
		//ī�޶� ��ǥ�� ���� ��ǥ��� �̵�

		DEVICE->GetTransform(D3DTS_VIEW, &view);
		D3DXMatrixInverse(&viewInv, NULL, &view);

		D3DXVec3TransformCoord(&result.origin, &result.origin, &viewInv);
		D3DXVec3TransformNormal(&result.direction, &result.direction, &viewInv);
		D3DXVec3Normalize(&result.direction, &result.direction);

		return result;
	}

	bool IntersectPolygon(Ray r, D3DXVECTOR3 * arrVector, D3DXVECTOR3 *colisPos)
	{
		bool result;
		D3DXVECTOR3 temp;
		float u, v;

		result = D3DXIntersectTri(
			&arrVector[0],
			&arrVector[1],
			&arrVector[2],
			&r.origin,
			&r.direction,
			&u, &v, NULL);

		//�浹�� ���� ���ϱ�

		temp = arrVector[0] + u * (arrVector[1] - arrVector[0]) + v * (arrVector[2] - arrVector[0]);

		if (colisPos) *colisPos = temp;

		return result;
	}


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
		)
	{
		//ź��Ʈ ���̳븻 �ϴ�
		ZeroMemory(outTangets, sizeof(D3DXVECTOR3) * NumVertices);
		ZeroMemory(outBinormals, sizeof(D3DXVECTOR3) * NumVertices);

		//�ӽ� Tangent Binormal �迭
		D3DXVECTOR3* pTangents = new D3DXVECTOR3[NumVertices];
		D3DXVECTOR3* pBinormals = new D3DXVECTOR3[NumVertices];

		//�ӽ� Tangent Binormal �迭 �ϴ�
		ZeroMemory(pTangents, sizeof(D3DXVECTOR3) * NumVertices);
		ZeroMemory(pBinormals, sizeof(D3DXVECTOR3) * NumVertices);

		//�ϴ� �ﰢ�� �����....
		for (DWORD a = 0; a < NumTris; a++)
		{
			//�ش� �ﰢ���� �ε���
			DWORD i0 = pIndices[a * 3 + 0];
			DWORD i1 = pIndices[a * 3 + 1];
			DWORD i2 = pIndices[a * 3 + 2];

			//�ش� �ﰢ���� ������ġ
			D3DXVECTOR3 p0 = pPositions[i0];
			D3DXVECTOR3 p1 = pPositions[i1];
			D3DXVECTOR3 p2 = pPositions[i2];

			//�ش� �ﰢ���� UV
			D3DXVECTOR2 uv0 = pUVs[i0];
			D3DXVECTOR2 uv1 = pUVs[i1];
			D3DXVECTOR2 uv2 = pUVs[i2];

			//������ Edge
			D3DXVECTOR3 edge1 = p1 - p0;
			D3DXVECTOR3 edge2 = p2 - p0;

			//UV Edge
			D3DXVECTOR2 uvEdge1 = uv1 - uv0;
			D3DXVECTOR2 uvEdge2 = uv2 - uv0;

			// ���� ������ ������ ���� ������ ����
			// edge1 = ( uvEdge1.x ) * Tangent + ( uvEdge1.y ) * Binormal;
			// edge2 = ( uvEdge2.x ) * Tangent + ( uvEdge2.y ) * Binormal;

			// ������ ���� ġȯ
			// E1 = edge1;
			// E2 = edge2;
			// U1 = uvEdge1.x;
			// V1 = uvEdge1.y;
			// U2 = uvEdge2.x;
			// V2 = uvEdge2.y;
			// T = Tangent;
			// B = Binormal;

			// E1 = U1 * T + V1 * B;
			// E2 = U2 * T + V2 * B;

			// | E1 |   | U1 , V1 | | T |
			// |    | = |         | |   |
			// | E2 |   | U2 , V2 | | B |

			// | T |          1        |  V2 , -V1 | | E1 |
			// |   | = --------------- |           | |    |
			// | B |    U1*V2 - V1*U2  | -U2 ,  U1 | | E2 |

			// R = 1 / U1*V2 - V1*U2;

			// T = ( ( E1 * V2 ) + ( E2 * -V1 ) ) * R
			// B = ( ( E1 * -U2 ) + ( E2 * U1 ) ) * R

			float r =
				1.0f / ((uvEdge1.x * uvEdge2.y) - (uvEdge1.y * uvEdge2.x));

			//Tangent
			D3DXVECTOR3 t = ((edge1 * uvEdge2.y) + (edge2 * -uvEdge1.y)) * r;
			D3DXVec3Normalize(&t, &t);

			//Binormal 
			D3DXVECTOR3 b = ((edge1 * -uvEdge2.x) + (edge2 * uvEdge1.x)) * r;
			D3DXVec3Normalize(&b, &b);

			//ź��Ʈ ���̳븻 �ӽ� �迭�� �߰�
			pTangents[i0] += t;
			pTangents[i1] += t;
			pTangents[i2] += t;
			pBinormals[i0] += b;
			pBinormals[i1] += b;
			pBinormals[i2] += b;
		}



		//Binormal Tangent �븻�� ����ȭ
		for (int i = 0; i < NumVertices; i++) {

			D3DXVECTOR3 n = pNormals[i];

			//Tangent �׶�����Ʈ ����
			D3DXVECTOR3 t = pTangents[i] -
				(D3DXVec3Dot(&pTangents[i], &n) * n);
			D3DXVec3Normalize(&t, &t);

			//�븻�� ����ȭ�� T �� �����Ͽ� B
			D3DXVECTOR3 b;
			D3DXVec3Cross(&b, &n, &t);
			D3DXVec3Normalize(&b, &b);

			outTangets[i] = t;
			outBinormals[i] = b;
		}

		//�ӽ� �迭 ����
		SAFE_DELETE_ARR(pTangents);
		SAFE_DELETE_ARR(pBinormals);



	}



	//�÷��� ��Ʈ���� �ս����� ����ü DWORD ������ ��ȯ
	DWORD FloatToDWORD(float f)
	{
		float* pFloat = &f;

		DWORD* pDword = (DWORD*)pFloat;

		return *pDword;
	}


	bool IsTimeMoment(float runningTime, float momentTime, float epsilon)
	{
		return (runningTime > momentTime && runningTime < momentTime + epsilon);
	}
}