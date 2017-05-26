// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
//DirectX Header Include
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

//include
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <thread>
//#include <future>
#include <mutex>
#include <queue>

//common header
#include "MyUtil.h"
#include "Singleton.h"
#include "Device.h"

#include "DXFontManager.h"
#include "GizmoManager.h"
#include "TimeMgr.h"
#include "LogMgr.h"
#include "KeyMgr.h"
#include "TextureManager.h"
#include "cPhysicManager.h"

#include "cResourceMgr.h"
#include "cResourceMgr_ShaderFX.h"
#include "cResourceMgr_Texture.h"
#include "cResourceMgr_XSkinnedMesh.h"
#include "cResourceMgr_XStaticMesh.h"

#include "cBaseObject.h"
#include "cXMesh.h"
#include "cXMesh_Skinned.h"
#include "cXMesh_Static.h"

#include "SoundManager.h"
#include "EffectManager.h"
#include "MyCamera.h"

#include "SkillManager.h"
#include "MonsterManager.h"
#include "NPCManager.h"
#include "SpriteManager.h"
#include "TerrainManager.h"
#include "QuestManager.h"
#include "PlayerManager.h"
#include "ItemManager.h"

#include "GameConfig.h"

//����
#define SAFE_DELETE(p)		{ if(p){ delete (p); (p) = NULL; } }
#define SAFE_DELETE_ARR(p)	{ if(p){ delete[] (p); (p) = NULL; } }
#define SAFE_RELEASE(p)		{ if(p){ (p)->Release(); (p) = NULL; } }

#define SAFE_ADDREF(p) { if(p) (p)->AddRef(); }

#define WINSIZE_X	1280		//�ʱ� ������ ���� ũ��
#define WINSIZE_Y	800			//�ʱ� ������ ���� ũ��
#define WINPOS_X	0			//�ʱ� ������ ���� ��ġ X
#define WINPOS_Y	0			//�ʱ� ������ ���� ��ġ Y
#define WIN_CLASS	"Windows Exam"		//������ Ŭ���� �̸�
#define WIN_TITLE	"Windows Exam"		//������ Ÿ��Ʋ �̸�
#define WIN_STYLE	WS_CAPTION | WS_SYSMENU | WS_BORDER	//������ ����

//���ҽ� �н�
#define RESOURCE_PATH			"../""Resources/"
#define TEXTURE_PATH			RESOURCE_PATH "Textures/"

#define RESOURCE(fileName)		RESOURCE_PATH "" fileName
#define TEXTURE(fileName)		TEXTURE_PATH "" fileName


//vertex
typedef struct tagPC_VERTEX
{
	D3DXVECTOR3 p = { 0, 0, 0 };
	DWORD		c = 0;
	static enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };

	tagPC_VERTEX()
	{

	}
	tagPC_VERTEX(D3DXVECTOR3 pos)
	{
		p = pos;
		c = 0;
	}
	tagPC_VERTEX(float x, float y, float z)
	{
		p = D3DXVECTOR3(x, y, z);
		c = 0;
	}
	tagPC_VERTEX(D3DXVECTOR3 pos, D3DCOLOR color)
	{
		p = pos;
		c = color;
	}
	tagPC_VERTEX(float x, float y, float z, D3DCOLOR color)
	{
		p = D3DXVECTOR3(x, y, z);
		c = color;
	}
} PC_VERTEX, FAR *LPPC_VEREX;

typedef struct tagPT_VERTEX
{
	D3DXVECTOR3 p = { 0, 0, 0 };
	D3DXVECTOR2	t = { 0, 0 };
	static enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };

	tagPT_VERTEX()
	{

	}
	tagPT_VERTEX(D3DXVECTOR3 &pos)
	{
		p = pos;
	}
	tagPT_VERTEX(float x, float y, float z)
	{
		p = D3DXVECTOR3(x, y, z);
	}
	tagPT_VERTEX(D3DXVECTOR3 &pos, D3DXVECTOR2 &tex)
	{
		p = pos;
		t = tex;
	}
	tagPT_VERTEX(float x, float y, float z, float u, float v)
	{
		p = D3DXVECTOR3(x, y, z);
		t = D3DXVECTOR2(u, v);
	}
} PT_VERTEX, FAR *LPPT_VEREX;

typedef struct tagPNT_VERTEX
{
	D3DXVECTOR3 p = { 0, 0, 0 };
	D3DXVECTOR3	n = { 0, 0, 0 };
	D3DXVECTOR2 t = { 0, 0 };
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };

	tagPNT_VERTEX()
	{

	}
	tagPNT_VERTEX(float x, float y, float z)
	{
		p = D3DXVECTOR3(x, y, z);
	}
	tagPNT_VERTEX(D3DXVECTOR3 pos)
	{
		p = pos;
	}
	tagPNT_VERTEX(float x, float y, float z, float nx, float ny, float nz)
	{
		p = D3DXVECTOR3(x, y, z);
		n = D3DXVECTOR3(nx, ny, nz);
	}
	tagPNT_VERTEX(D3DXVECTOR3 pos, D3DXVECTOR3 nor)
	{
		p = pos;
		n = nor;
	}
	tagPNT_VERTEX(float x, float y, float z, float nx, float ny, float nz, float u, float v)
	{
		p = D3DXVECTOR3(x, y, z);
		n = D3DXVECTOR3(nx, ny, nz);
		t = D3DXVECTOR2(u, v);
	}
	tagPNT_VERTEX(D3DXVECTOR3 pos, D3DXVECTOR3 nor, D3DXVECTOR2 tex)
	{
		p = pos;
		n = nor;
		t = tex;
	}

} PNT_VERTEX, FAR *LPPNT_VERTEX;

typedef struct tagPNC_VERTEX
{
	D3DXVECTOR3 p = { 0, 0, 0 };
	D3DXVECTOR3	n = { 0, 0, 0 };
	DWORD c = 0;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE };

	tagPNC_VERTEX()
	{

	}
	tagPNC_VERTEX(float x, float y, float z)
	{
		p = D3DXVECTOR3(x, y, z);
	}
	tagPNC_VERTEX(D3DXVECTOR3 pos)
	{
		p = pos;
	}
	tagPNC_VERTEX(float x, float y, float z, float nx, float ny, float nz)
	{
		p = D3DXVECTOR3(x, y, z);
		n = D3DXVECTOR3(nx, ny, nz);
	}
	tagPNC_VERTEX(D3DXVECTOR3 pos, D3DXVECTOR3 nor)
	{
		p = pos;
		n = nor;
	}
	tagPNC_VERTEX(float x, float y, float z, float nx, float ny, float nz, D3DXCOLOR color)
	{
		p = D3DXVECTOR3(x, y, z);
		n = D3DXVECTOR3(nx, ny, nz);
		c = color;
	}
	tagPNC_VERTEX(D3DXVECTOR3 pos, D3DXVECTOR3 nor, D3DXCOLOR color)
	{
		p = pos;
		n = nor;
		c = color;
	}

} PNC_VERTEX, FAR *LPPNC_VERTEX;

typedef struct tagRHWC_VERTEX
{
	D3DXVECTOR4 p;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE };
} RHWC_VERTEX, FAR *LPRHWC_VERTEX;


//�������� ����
extern HWND hWnd;
extern bool isInitDialog; // ���̾�α� â �ʱ�ȭ ����
extern bool isSellMode; // ���� �Ǹ� ��
extern int playerLevel;
extern HCURSOR customCursor;
extern WNDCLASSEX wcex;
using namespace MyUtil;

