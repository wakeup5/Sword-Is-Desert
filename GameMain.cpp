#include "stdafx.h"
#include "GameMain.h"
#include "TestScene.h"
#include "Opening.h"
#include "MapToolScene.h"
#include "LoadingScene.h"
#include "MainScene.h"
#include "CharacterSelect.h"

GameMain::GameMain()
{
	SetRandomSeed();
}


GameMain::~GameMain()
{
}

HRESULT GameMain::Setup()
{

	TIME_MGR->Setup();
	LOG_MGR->Setup(LOG_WINDOW, hWnd, "Dump");

	DEVICEMANAGER->Setup();
	DXFONT_MGR->Setup(DEVICE);
	GIZMO_MGR->Setup(DEVICE);

	TEXTURE_MGR->Setup(DEVICE);
	SPRITE_MGR->Setup(DEVICE);
	CAMERA;
	EFFECT_MGR->Setup();

	GAMECONFIG;

	SCENE_MGR->Add("Opening", new Opening());
	SCENE_MGR->Add("CharacterSelect", new CharacterSelect());
	SCENE_MGR->Add("loading", new LoadingScene("T"));
	SCENE_MGR->Add("mapTool", new MapToolScene);
	SCENE_MGR->Add("MainScene", new MainScene);
	SCENE_MGR->Add("T", new TestScene);
	SCENE_MGR->Change("MainScene");

	return S_OK;
}

void GameMain::Release()
{
	//GIZMO_MGR->Release();
	GizmoManager::ReleaseInstance();
	//TIME_MGR->Release();
	TimeMgr::ReleaseInstance();
	//KEY_MGR->Release();
	KeyMgr::ReleaseInstance();
	//LOG_MGR->Release();
	LogMgr::ReleaseInstance();
	//DXFONT_MGR->Release();
	DXFontManager::ReleaseInstance();
	//DEVICEMANAGER->Release();
	Device::ReleaseInstance();

	SpriteManager::ReleaseInstance();

	SceneManager::ReleaseInstance();

	//�ɸŴ���
	//MonsterManager::GetInstance()->Release();
	//MonsterManager::ReleaseInstance();
	//NPCManager::GetInstance()->Release();
	//NPCManager::ReleaseInstance();

	UIWindow::GetRoot()->Release();

	GameConfig::ReleaseInstance();
	EffectManager::ReleaseInstance();

	cResourceMgr_XStaticMesh::GetInstance()->ClearResource();
	cResourceMgr_XStaticMesh::ReleaseInstance();
	cResourceMgr_XSkinnedMesh::GetInstance()->ClearResource();
	cResourceMgr_XSkinnedMesh::ReleaseInstance();
	cResourceMgr_Texture::GetInstance()->ClearResource();
	cResourceMgr_Texture::ReleaseInstance();
	cResourceMgr_ShaderFX::GetInstance()->ClearResource();
	cResourceMgr_ShaderFX::ReleaseInstance();
}

void GameMain::Update()
{
	//Ÿ�ӸŴ��� ������Ʈ
	TIME_MGR->UpdateTime(60.0f);

	//�������� ���� �ð�
	double timeDelta = TIME_MGR->GetFrameDeltaSec();

	TIME_MGR->Update(timeDelta);
	CAMERA->Update(timeDelta);
	SPRITE_MGR->Update(timeDelta);
	SCENE_MGR->Update(timeDelta);
	//EFFECT_MGR->Update(timeDelta);

	//UIWindow::GetRoot()->Update();
	//CAMERA->DefaultControl(timeDelta);

	//if (KEY_MGR->IsOnceDown('N'))
	//{
	//	SCENE_MGR->Change("test");
	//}

	//if (KEY_MGR->IsOnceDown('M'))
	//{
	//	SCENE_MGR->Change("mapTool");
	//}

	GAMECONFIG->Update();
}

void GameMain::Render()
{
	cXMesh_Static::SetCamera(CAMERA);
	cXMesh_Skinned::SetCamera(CAMERA);
	cTerrain::SetCamera(CAMERA);

	cXMesh_Skinned::SetTechniqueName("Base");
	//���۸� û���Ѵ�
	HRESULT result = DEVICE->Clear(
		0,							//û���� ������ D3DRECT �迭 ����		( ��ü Ŭ���� 0 )
		NULL,						//û���� ������ D3DRECT �迭 ������		( ��ü Ŭ���� NULL )
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,		//û�ҵ� ���� �÷��� ( D3DCLEAR_TARGET �÷�����, D3DCLEAR_ZBUFFER ���̹���, D3DCLEAR_STENCIL ���ٽǹ���
		0xff202020,					//�÷����۸� û���ϰ� ä���� ����( 0xAARRGGBB )
		1.0f,						//���̹��۸� û���Ұ� ( 0 ~ 1, 0 �� ī�޶󿡼� ���ϰ���� 1 �� ī�޶󿡼� ���� �� )
			0						//���ٽ� ���۸� ä�ﰪ
		);

	//���� û�Ұ� �����ߴٸ�.......
	if (SUCCEEDED(result))
	{
		//����̽� ������ ���� ���
		DEVICE->BeginScene();

		//������ ���

		//������
		SCENE_MGR->Render();
		
		
		
//#ifdef _DEBUG		//����� ��忡���� ����
		//����̽� ������ ���� ���
		//���� �׸���
		//GIZMO_MGR->WorldGrid(1, 10);

		//Ÿ������ ���
		//TIME_MGR->DrawTimeInfo();
//#endif
		//UIWindow::GetRoot()->Render(SPRITE);
		SPRITE_MGR->Render();

		DEVICE->EndScene();

		////////////////////////////////

		////////////////////////////////
		//DEVICE->StretchRect(_sur, NULL, defaultSur, NULL, D3DTEXF_NONE);
		
		//�������� ���۳����� ȭ�鿡 ����
		DEVICE->Present(0, 0, 0, 0);
	}
}

LRESULT GameMain::WndProc(HWND h, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		break;
	}
	
	CAMERA->WndProc(h, iMessage, wParam, lParam);

	if (SCENE_MGR->GetCurrent()) return SCENE_MGR->GetCurrent()->WndProc(h, iMessage, wParam, lParam);

	//

	return DefWindowProc(h, iMessage, wParam, lParam);
}
