#include "stdafx.h"
#include "NPCManager.h"
#include "UIDialog.h"

std::map<std::string, NpcInfo> NPCManager::MapNPC;

bool npcSort(NPC* a, NPC* b)
{
	float distA, distB;
	distA = D3DXVec3Length(&(a->pTransform->GetWorldPosition() - a->PlayerTrans->GetWorldPosition()));
	distB = D3DXVec3Length(&(b->pTransform->GetWorldPosition() - b->PlayerTrans->GetWorldPosition()));

	return distA < distB;
}

NPCManager::NPCManager()
{
}


NPCManager::~NPCManager()
{
}

void NPCManager::Setup()
{
	_data.clear();

	_pCircle.Setup(60, 1.5f);
	_nCircle.Setup(60, 1.5f);
	_nBigCircle.Setup(90, 2.5f);
	//_line.Setup();

	_nametag = new NameTag;

	_nametag->SetTexture(RESOURCE("Textures/icon/quest.png"));
	_nametag->SetPosition(0, 0, 0);
	_nametag->SetRotate(0, 0, 0);
	_nametag->SetScale(0.2, 0.2, 0.2);

	//NPC ��ġ
	_npcPos.SetTexture(RESOURCE("Textures/Icon/npc.png"));
}

void NPCManager::Release()
{
	for (NPC* n : _data)
	{
		n->Release();
		delete n;
	}

	if(_nametag) _nametag->Release();
	SAFE_DELETE(_nametag);
}

void NPCManager::Update(float timeDelta)
{
	if (_data.size() <= 0 || _player == NULL) return;

	std::sort(_data.begin(), _data.end(), npcSort);

	for (NPC* n : _data)
	{
		n->Update(timeDelta);
	}

	D3DXVECTOR3 pPos = _player->pTransform->GetWorldPosition();
	D3DXVECTOR3 nPos = _data[0]->pTransform->GetWorldPosition();
	if (D3DXVec3Length(&(pPos - nPos)) < 3)
	{
		if (KEY_MGR->IsOnceDown('R'))
		{
			_ui->SetNPC(_data[0]);
		}
	}
	nPos.y += 2.5f;
	_nametag->SetPosition(nPos);
	_nametag->Look(CAMERA->GetForward(), CAMERA->GetUp());

	//_line.SetStart(pPos);
	//_line.SetEnd(nPos);
}

void NPCManager::Render()
{
	if (_data.size() <= 0 || _player == NULL) return;

	for (NPC* n : _data)
	{
		n->Render();
	}
}

void NPCManager::MapRender()
{
	if (_data.size() <= 0 || _player == NULL) return;

	for (NPC* n : _data)
	{
		_npcPos.SetPosition(n->pTransform->GetWorldPosition());
		_npcPos.RenderToSprite(SPRITE, CAMERA);
	}
}

void NPCManager::RenderNameTag()
{
	if (_ui->IsExistNPC()) return;

	float dist = D3DXVec3Length(&(_player->pTransform->GetWorldPosition() - _data[0]->pTransform->GetWorldPosition()));

	_nBigCircle.SetAlpha(1 - dist / 6);
	_pCircle.SetAlpha(1 - dist / 6);
	_nCircle.SetAlpha(1 - dist / 6);

	if (dist < 3)
	{
		D3DXVECTOR3 nPos = _data[0]->pTransform->GetWorldPosition();
		D3DXVECTOR3 pPos = _player->pTransform->GetWorldPosition();
		D3DXVECTOR3 bPos = (nPos + pPos) / 2;

		Figure::Begin();
		_nBigCircle.pTransform.SetWorldPosition(bPos.x, bPos.y + 1, bPos.z);
		_nBigCircle.Render();
		Figure::End();

		_nametag->Render();
	}
	else if (dist < 6)
	{
		D3DXVECTOR3 nPos = _data[0]->pTransform->GetWorldPosition();
		_nCircle.pTransform.SetWorldPosition(nPos.x, nPos.y + 1, nPos.z);

		D3DXVECTOR3 pPos = _player->pTransform->GetWorldPosition();
		_pCircle.pTransform.SetWorldPosition(pPos.x, pPos.y + 1, pPos.z);

		Figure::Begin();
		_nCircle.Render();
		_pCircle.Render();
		Figure::End();
	}
}

void NPCManager::AddNPC(NpcInfo & info)
{
	NPC* n = new NPC;

	n->Setup(info);
	n->SetActive(true);

	_data.push_back(n);

	D3DXVECTOR3 pos = n->pTransform->GetWorldPosition();
	n->pTransform->SetWorldPosition(pos.x, _terrain->GetHeight(pos.x, pos.z), pos.z);

	n->pTransform->LookDirection(info.Forward);
	n->pTransform->SetScale(info.Scale);
}

void NPCManager::LoadNPC()
{
	MapNPC.clear();

	NpcInfo info;

	NpcInfo::quest quest;
	
	

	info = NpcInfo(RESOURCE("Meshes/NPC/NPC01.X"), "Tom", "�ȳ��ϽŰ�.", D3DXVECTOR3(0, 0, 0));

	quest.questText.clear();
	quest.questText.push_back("����� �����簡 ������ �翡 ������ �ɾ����ϴ�.");
	quest.questText.push_back("�� ������ ���ķ� ������ ȣ�ڵ��� ������ ���� ������� ��ġ���ֽ��ϴ�.");
	quest.questText.push_back("ȣ�ڵ��� �������ּ���.");
	quest.questName = "����Ų ��ġ";
	quest.questTargetName = "Pumpkin";
	quest.questQTY = 10;
	info.questList.insert({ 1150, quest }); // ����Ʈ ���Ϲ�ȣ ����

	MapNPC.insert(std::make_pair(info.Name, info));

	info = NpcInfo(RESOURCE("Meshes/NPC/NPC02.X"), "Jin", "�ȳ��ϽŰ�.", D3DXVECTOR3(0, 0, 0));
	quest.questText.clear();
	quest.questText.push_back("���ڰ� ũ�� �þ Muspel���� ������ �����Ұ� �Ǿ����ϴ�.");
	quest.questText.push_back("Muspel�� ���ڸ� �ٿ��ּ���.");
	quest.questText.push_back("��Ź�帳�ϴ�. ���谡��.");
	quest.questName = "Muspel ��ġ";
	quest.questTargetName = "Muspel";
	quest.questQTY = 3;
	info.questList.insert({ 1160, quest }); // ����Ʈ ���Ϲ�ȣ ����
	
	quest.questText.clear();
	quest.questText.push_back("�Ѵ������� ��ü���� �Ͼ�� �����߽��ϴ�.");
	quest.questText.push_back("������ ��ġ�� �Ž����� �̷��� ��ü���� �������ּ���.");
	quest.questText.push_back("��Ź�帳�ϴ�. ���谡��.");
	quest.questName = "�ذ� ��ġ";
	quest.questTargetName = "SkullWarrior";
	quest.questQTY = 3;
	info.questList.insert({ 1161, quest });
	info.Button = UIDB::SHOP;
	MapNPC.insert(std::make_pair(info.Name, info));

	info = NpcInfo(RESOURCE("Meshes/NPC/NPC03.X"), "Kings", "�ȳ��ϽŰ�.", D3DXVECTOR3(0, 0, 0));
	quest.questText.clear();
	quest.questText.push_back("��ó ���� ��ũ���� ���� ���ν��� �ֺ� ��ũ���� ������Ű���ֽ��ϴ�.  ");
	quest.questText.push_back("���ν��� �����ϰ� ��ũ���� �л�����ּ���.");
	quest.questName = "���ν� ��ġ";
	quest.questTargetName = "Orc";
	quest.questQTY = 1;
	info.questList.insert({ 1170, quest }); // ����Ʈ ���Ϲ�ȣ ����

	MapNPC.insert(std::make_pair(info.Name, info));

	info = NpcInfo(RESOURCE("Meshes/NPC/NPC04.X"), "Bob", "�ȳ��ϽŰ�.", D3DXVECTOR3(0, 0, 0));
	quest.questText.clear();
	quest.questText.push_back("�׵��� ��� �ϵ��� ���Ŀ��� ������ ���� Seth�� �־�������");
	quest.questText.push_back("���������ϴ�. Seth�� ���� ���� Ȯ���ϱ����� �񷽵��� �����帮����.");
	quest.questName = "�� ��ġ";
	quest.questTargetName = "Golem";
	quest.questQTY = 10;
	info.questList.insert({ 1180, quest }); // ����Ʈ ���Ϲ�ȣ ����
	MapNPC.insert(std::make_pair(info.Name, info));

	info = NpcInfo(RESOURCE("Meshes/NPC/NPC05.X"), "Dan", "�ȳ��ϽŰ�.", D3DXVECTOR3(0, 0, 0));
	quest.questText.clear();
	quest.questText.push_back("�׵����� ���࿡ ���ĸ� ���Ҷ��� �Ǿ����ϴ�.");
	quest.questText.push_back("Seth�� óġ�ϰ� ������.");
	quest.questText.push_back("��Ź�帳�ϴ�. ���谡��.");
	quest.questName = "Seth ��ġ";
	quest.questTargetName = "Seth";
	quest.questQTY = 1;
	info.questList.insert({ 1190, quest });
	info.Button = UIDB::QUEST;
	MapNPC.insert(std::make_pair(info.Name, info));
}
