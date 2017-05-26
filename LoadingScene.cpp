#include "stdafx.h"
#include "LoadingScene.h"
#include "MapDataSaveLoad.h"

std::recursive_mutex mtx;

LoadingScene::LoadingScene(const char* next)
	: _nextScene(next)
{

}


LoadingScene::~LoadingScene()
{
}

HRESULT LoadingScene::Setup()
{
	CAMERA_MGR->SetMapView();
	CAMERA->SetFov(RAD(65), RAD(65), 0);
	//기본 매니저 로딩
	MonsterManager::LoadMonsters();
	NPCManager::LoadNPC();

	LOG_MGR->AddLog("LoadingScene - 로드");

	MONSTER_MGR->Setup();
	NPC_MGR->Setup();
	TERRAIN_MGR->Setup();
	PLAYER_MGR->Setup();

	LOG_MGR->AddLog("LoadingScene - 매니저 셋업");

	_loading = new Loading;
	_loading->Setup();
	
	LoadList();

	LOG_MGR->AddLog("LoadingScene - 로딩 생성");

	TerrainManager::GetInstance()->Create(
		"worldMap",
		"../Resources/Map/asd.bmp",
		"../Resources/map/road.jpg",
		"../Resources/map/grass2.jpg",
		"../Resources/map/sahara.jpg",
		"../Resources/map/grass1.jpg",
		"../Resources/Map/split1.png",
		3, 350, 10, 200
		);

	LOG_MGR->AddLog("LoadingScene - 지형 생성");


	//로딩 쓰레드 실행
	tagLoadingSceneThreadParameter param{ _loading, _nextScene };

	loadingThread = std::thread([](tagLoadingSceneThreadParameter param)
	{
		std::lock_guard<std::recursive_mutex> lg(mtx);
		LOG_MGR->AddLog("로딩 쓰레드 시작");
		while (param.loading->LoadNext());// { Sleep(10); }
		Sleep(5000);
		SCENE_MGR->Change(param.nextScene);
		LOG_MGR->AddLog("로딩 쓰레드 끝");

	}, param);

	LOG_MGR->AddLog("LoadingScene - 로딩 쓰레드 생성, 실행");
	
	//_playerPos = D3DXVECTOR3(200, 100, 200);
	_viewPos = D3DXVECTOR3(0, 0, 0);
	_camPos = D3DXVECTOR3(0, 1000, -666);
	CAMERA->SetLook(_viewPos);
	CAMERA->SetPos(D3DXVECTOR3(_camPos));

	LOG_MGR->AddLog("LoadingScene - 카메라 셋팅");

	_map.Setup();
	_map._smallCircle.Setup(100, 50);
	_map._smallCircle.SetAlpha(1);
	_map._bigCircle.Setup(100, 100);
	_map._bigCircle.SetAlpha(1);
	_map._dayCircle.Setup(100, 100);
	_map._dayCircle.SetAlpha(1);

	return S_OK;
}

void LoadingScene::Release()
{
	LOG_MGR->AddLog("LoadingScene - 릴리즈");

	_loading->Release();
	delete _loading;

	LOG_MGR->AddLog("LoadingScene - 완료");
}

void LoadingScene::Update(float timeDelta)
{
	//if (!_loading->LoadNext())
	//{
	//	SCENE_MGR->Change(_nextScene);
	//	return;
	//}

	float percent = _loading->GetPercent();

	static D3DXVECTOR3 pPos2 = _camPos;
	static D3DXVECTOR3 camTemp;

	_camPos = MyUtil::VecLerp(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(-400, 100, 400), _loading->GetPercent());
	pPos2 = pPos2 + (_camPos - pPos2) / 100;

	camTemp = camTemp + (MyUtil::VecLerp(D3DXVECTOR3(0, 600, -400), D3DXVECTOR3(0, 200, -150), _loading->GetPercent()) - camTemp) / 100;

	//CAMERA->SetLook(_viewPos);
	CAMERA->SetPos(D3DXVECTOR3(pPos2 + camTemp));
	CAMERA->SetLook(pPos2);


	//원들 그림
	D3DXVECTOR3 pPos = pPos2;
	pPos.y = 200;

	_map._smallCircle.pTransform.SetWorldPosition(pPos.x, 200, pPos.z);
	_map._bigCircle.pTransform.SetWorldPosition(pPos.x, 200, pPos.z);
	_map._dayCircle.pTransform.SetWorldPosition(pPos.x, 200, pPos.z);

	//햇빛 달빛 설정
	D3DXVECTOR3 dayPos = D3DXVECTOR3(0, 0, -300), nightPos = D3DXVECTOR3(0, 0, -300);

	static float angle = 30;

	D3DXMATRIXA16 total, rx, ry, rz;
	D3DXMatrixRotationX(&rx, RAD(angle += 0.1));
	D3DXMatrixRotationY(&ry, RAD(60));
	D3DXMatrixRotationZ(&rz, 0);
	total = rx * ry * rz;
	D3DXVec3TransformCoord(&dayPos, &dayPos, &total);
	_map._dayLight.SetPosition(pPos + dayPos);

	D3DXMatrixRotationX(&rx, RAD(180) + RAD(angle));
	total = rx * ry * rz;
	D3DXVec3TransformCoord(&nightPos, &nightPos, &total);
	_map._nightLight.SetPosition(pPos + nightPos);
}

void LoadingScene::Render()
{
	cTerrain* terrain = TERRAIN_MGR->GetTerrain("worldMap");

	if (terrain) 
		terrain->Render(CAMERA);

	//std::lock_guard<std::recursive_mutex> lg(mtx);
	_loading->Render();


	for (int i = 0; i < _mapObj.size(); i++)
	{
		_mapObj[i]->Render();
	}

	_map.Render();
}

void LoadingScene::LoadList()
{
	//플레이어 로딩
	_loading->LoadXMeshSkinned(RESOURCE("meshes/player/MAINCHARACTER.x"));
	_loading->LoadXMeshSkinned(RESOURCE("meshes/vehicle/vehicle_Lion.x"));

	//몬스터 로드
	MonsterManager::LoadMonsters();
	for (auto i = MonsterManager::MapMonster.begin(); i != MonsterManager::MapMonster.end(); ++i)
	{
		_loading->LoadXMeshSkinned(i->second.ResourcePath);
	}

	//NPC 로드
	NPCManager::LoadNPC();
	for (auto i = NPCManager::MapNPC.begin(); i != NPCManager::MapNPC.end(); ++i)
	{
		_loading->LoadXMeshSkinned(i->second.ResourcePath);
	}

	//텍스쳐
	_loading->LoadTexture(TEXTURE("UI/ui_background_small.png"));

	//오브젝트
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/tree/tree1.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/tree/tree1.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Altor.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Article.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Barricade.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Campfire.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Castle.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Fence.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Gate.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Giant_Statue.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Giant_Wall.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Lamp.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Lamp02.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Macha.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Plane.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Plane02.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Plant.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Simbol.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Skull_Stack.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Stone.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Stone02.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Tent.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Tent02.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/tomb.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Tower.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/TreasureBox.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Wall_01.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Wall_02.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Well_02.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Wood_Box.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/BigHouse1.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/BigHouse2.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/BigHouse3.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/SideHouse.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/StonStairs.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Veranda1.x"));
	_loading->LoadXMeshStatic(RESOURCE("map/meshes/Object/Veranda2.x"));
}

void Loading::Setup()
{
	_progress = new UIProgress;

	_progress->Setup();
	_progress
		->SetSize(WINSIZE_X - 100, 25)
		->SetPosition(50, WINSIZE_Y - 75);

	_progress->SetBarTexture(
		TEXTURE("bar/exp_bar.png"),
		TEXTURE("bar/exp_back.png")
		);

	_textBox = new UITextBox;
	_textBox->Setup();
	_textBox
		->SetSize(WINSIZE_X, 25)
		->SetPosition(0, WINSIZE_Y - 75);
	_textBox->SetFontFormat(DT_CENTER | DT_VCENTER | DT_WORDBREAK);

	_textBox->SetColor(0xff5555ff);

	_current = 0;
}

void Loading::Release()
{
	_progress->Release();
	delete _progress;

	_textBox->Release();
	delete _textBox;
}

void Loading::Render()
{
	_progress->Render(SPRITE);
	_textBox->Render(SPRITE);
}

void Loading::LoadTexture(std::string resourcePath)
{
	_vLoading.push_back(make_pair(LT_TEXTURE, resourcePath));
}

void Loading::LoadXMeshStatic(std::string resourcePath)
{
	_vLoading.push_back(make_pair(LT_XMESH_STATIC, resourcePath));
}

void Loading::LoadXMeshSkinned(std::string resourcePath)
{
	_vLoading.push_back(make_pair(LT_XMESH_SKINNED, resourcePath));
}

bool Loading::LoadNext()
{
	_progress->SetMax(_vLoading.size());
	if (_vLoading.size() <= _current)
	{
		_textBox->SetText("게임 준비중...");
		return false;
	}

	LOG_MGR->AddLog("Loading : %s", _vLoading[_current].second);

	std::string text = "";
	text += " [ " + std::to_string(_current + 1) + " / ";
	text += std::to_string(_vLoading.size()) + " ] ";
	text += _vLoading[_current].second;
	_textBox->SetText(text);

	switch (_vLoading[_current].first)
	{
	case LT_TEXTURE:
		RESOURCE_TEXTURE->GetResource(_vLoading[_current].second);
		break;
	case LT_XMESH_SKINNED:
		RESOURCE_SKINNEDXMESH->GetResource(_vLoading[_current].second);
		break;
	case LT_XMESH_STATIC:
		RESOURCE_STATICXMESH->GetResource(_vLoading[_current].second);
		break;
	}

	_progress->SetCurrent(++_current);

	return true;
}
