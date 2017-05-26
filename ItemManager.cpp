#include "stdafx.h"
#include "ItemManager.h"

std::map<std::string, tagItemInfo> ItemManager::MapItem;

ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}

Item * ItemManager::CreateItem(ItemInfo &info, Transform* trans)
{
//	if (MapItem.find(info.Name)->second.Name.size() > 0)return;

	Item* result = new Item;
	result->Setup(info);

	_items.push_back(result);
	


	if (trans != NULL)
	{
		SAFE_DELETE(result->pTransform);
		result->pTransform = trans;
	}

	return result;
}

Item * ItemManager::CreateItem(std::string name, Transform* trans)
{
	auto iter = MapItem.find(name);
	if (iter == MapItem.end()) return NULL;

	return CreateItem(iter->second, trans);
}

void ItemManager::LoadItemInfo()
{
	ItemInfo info;
	info = ItemInfo("�̸�", "����", RESOURCE("Textures/Icon/�ӽñ�.png"), RESOURCE("Weapon/�ӽñ�.X"), IT_NONE, ITR_COMMON, 0, 0, 0, 0, 0, false);
	//MapItem.insert(std::make_pair(info.Name, info));
	//string testdat = "../Resources/Weapon/Sword_01.X";
	// �� ������ ����
	info = ItemInfo("�κ��� ���", "�ʺ� �����ڸ� ���� ���", "../Resources/�˻�_������_�۾�/������/���/�κ���_���.png",
		RESOURCE("Weapon/Sword_01.X"), IT_SWORD, ITR_COMMON, 1000, 0, 0, 10, 0, true);
	info.SetMatrix(0.022, 0.022, 0.022, 0, 0, 0, 0.1, 0, 0.1);
	//info.ResourcePath = "../Resources/Weapon/Sword_01.X";
	MapItem.insert({ info.Name, info });

	info = ItemInfo("���� ���", "���õ� �����ڸ� ���� ���", "../Resources/�˻�_������_�۾�/������/���/����_���.png",
		RESOURCE("Weapon/Sword_02.X"), IT_SWORD, ITR_UNCOMMON, 2000, 0, 0, 20, 0, true);
	info.SetMatrix(0.022, 0.022, 0.022, 0, 0, 0, 0.1, 0, 0.1);
	//info.ResourcePath = "../Resources/Weapon/Sword_02.X";
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�������� ���", "��� �����ڸ� ���� ���", "../Resources/�˻�_������_�۾�/������/���/��������_���.png",
		RESOURCE("Weapon/Sword_03.X"), IT_SWORD, ITR_RARE, 3000, 0, 0, 30, 0, true);
	info.SetMatrix(0.05, 0.05, 0.05, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� �λ縣 ���", "�������� �����ڸ� ���� ���", "../Resources/�˻�_������_�۾�/������/���/��_�λ縣_���.png",
		RESOURCE("Weapon/Sword_04.X"), IT_SWORD, ITR_EPIC, 4000, 0, 0, 40, 0, true);
	info.SetMatrix(0.03, 0.03, 0.05, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });


	info = ItemInfo("���� Ȱ", "�������� �����ڸ� ���� Ȱ", "../Resources/�˻�_������_�۾�/������/Ȱ/����_���.png",
		RESOURCE("Weapon/Bow.X"), IT_BOW, ITR_EPIC, 4000, 0, 0, 40, 0, true);
	info.SetMatrix(0.1, 0.1, 0.1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	//ITEM_MGR->CreateItem("�κ��� ���");
	//ITEM_MGR->CreateItem("���� ���");
	//ITEM_MGR->CreateItem("�������� ���");
	//ITEM_MGR->CreateItem("�� �λ縣 ���");
	//ITEM_MGR->CreateItem("���� Ȱ");
	// ���� ������ ����
	info = ItemInfo("���ö� ����", "�ʺ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/���ö�_����.png",
		RESOURCE(".."), IT_BODY, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("��ö ŸŸ���� ����", "���õ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/��ö_Ÿ��Ÿ��_����.png",
		RESOURCE(".."), IT_BODY, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ��ö ŸŸ���� ����", "��� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/��_��ö_Ÿ��Ÿ��_����.png",
		RESOURCE(".."), IT_BODY, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ���δ� ����", "�������� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/��_���δ�_����.png",
		RESOURCE(".."), IT_BODY, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	// �Ͱ��� ������ ����
	info = ItemInfo("���δ� �Ͱ���", "�ʺ� �����ڸ� ���� �Ͱ���", "../Resources/�˻�_������_�۾�/������/��/�Ͱ���/���δ�_�Ͱ���.png",
		RESOURCE(".."), IT_EARING, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�ٸ��� �Ͱ���", "���õ� �����ڸ� ���� �Ͱ���", "../Resources/�˻�_������_�۾�/������/��/�Ͱ���/�ٸ���_�Ͱ���.png",
		RESOURCE(".."), IT_EARING, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("Ÿ���� ��� �Ͱ���", "��� �����ڸ� ���� �Ͱ���", "../Resources/�˻�_������_�۾�/������/��/�Ͱ���/Ÿ����_���_�Ͱ���.png",
		RESOURCE(".."), IT_EARING, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("������ �����", "�������� �����ڸ� ���� �Ͱ���", "../Resources/�˻�_������_�۾�/������/��/�Ͱ���/������_�����.png",
		RESOURCE(".."), IT_EARING, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	// ����� ������ ����
	info = ItemInfo("���δ� �����", "�ʺ� �����ڸ� ���� �����", "../Resources/�˻�_������_�۾�/������/��/�����/���δ�_�����.png",
		RESOURCE(".."), IT_NECKLESS, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�ٷ��� �����", "���õ� �����ڸ� ���� �����", "../Resources/�˻�_������_�۾�/������/��/�����/�ٷ���_�����.png",
		RESOURCE(".."), IT_NECKLESS, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�ұ��� ���̾Ƹ�� �����", "��� �����ڸ� ���� �����", "../Resources/�˻�_������_�۾�/������/��/�����/�ұ���_���̾Ƹ��_�����.png",
		RESOURCE(".."), IT_NECKLESS, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("��� ��ȣ���� ����", "�������� �����ڸ� ���� �����", "../Resources/�˻�_������_�۾�/������/��/�����/���_��ȣ����_����.png",
		RESOURCE(".."), IT_NECKLESS, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	
	// ���� ������ ����
	info = ItemInfo("���δ� ����", "�ʺ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/���δ�_����.png",
		RESOURCE(".."), IT_RING, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("������ ����", "���õ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/������_����.png",
		RESOURCE(".."), IT_RING, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�׸�Ʈ ����", "��� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/�׸�Ʈ_����.png",
		RESOURCE(".."), IT_RING, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�ʽ´� ��ȣ���� ����", "�������� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/�ʽ´�_��ȣ����_����.png",
		RESOURCE(".."), IT_RING, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	// �Ź� ������ ����
	info = ItemInfo("���ö� �Ź�", "�ʺ� �����ڸ� ���� �Ź�", "../Resources/�˻�_������_�۾�/������/��/�Ź�/���ö�_�Ź�.png",
		RESOURCE(".."), IT_SHOES, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("��ö Ÿ��Ÿ�� �Ź�", "���õ� �����ڸ� ���� �Ź�", "../Resources/�˻�_������_�۾�/������/��/�Ź�/��ö_Ÿ��Ÿ��_�Ź�.png",
		RESOURCE(".."), IT_SHOES, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ��ö Ÿ��Ÿ�� �Ź�", "��� �����ڸ� ���� �Ź�", "../Resources/�˻�_������_�۾�/������/��/�Ź�/��_��ö_Ÿ��Ÿ��_�Ź�.png",
		RESOURCE(".."), IT_SHOES, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ���δ� �Ź�", "�������� �����ڸ� ���� �Ź�", "../Resources/�˻�_������_�۾�/������/��/�Ź�/��_���δ�_�Ź�.png",
		RESOURCE(".."), IT_SHOES, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });
	
	
	// �尩 ������ ����
	info = ItemInfo("���ö� �Ź�", "�ʺ� �����ڸ� ���� �尩", "../Resources/�˻�_������_�۾�/������/��/�尩/���ö�_�尩.png",
		RESOURCE(".."), IT_GLOVE, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("��ö Ÿ��Ÿ�� �尩", "���õ� �����ڸ� ���� �尩", "../Resources/�˻�_������_�۾�/������/��/�尩/��ö_Ÿ��Ÿ��_�尩.png",
		RESOURCE(".."), IT_GLOVE, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ��ö Ÿ��Ÿ�� �尩", "��� �����ڸ� ���� �尩", "../Resources/�˻�_������_�۾�/������/��/�尩/��_��ö_Ÿ��Ÿ��_�尩.png",
		RESOURCE(".."), IT_GLOVE, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ���δ� �尩", "�������� �����ڸ� ���� �尩", "../Resources/�˻�_������_�۾�/������/��/�尩/��_���δ�_�尩.png",
		RESOURCE(".."), IT_GLOVE, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	// ���� ������ ����
	info = ItemInfo("���ö� �Ź�", "�ʺ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/���ö�_����.png",
		RESOURCE(".."), IT_HEAD, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("���ٸ�Ʈ ����", "���õ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/���ٸ�Ʈ_����.png",
		RESOURCE(".."), IT_HEAD, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ��ö Ÿ��Ÿ�� ����", "��� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/��_��ö_Ÿ��Ÿ��_����.png",
		RESOURCE(".."), IT_HEAD, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� ���δ� ����", "�������� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/��_���δ�_����.png",
		RESOURCE(".."), IT_HEAD, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });
	

	// �㸮�� ������ ����
	info = ItemInfo("���δ� �㸮��", "�ʺ� �����ڸ� ���� �㸮��", "../Resources/�˻�_������_�۾�/������/��/�㸮��/���δ�_�㸮��.png",
		RESOURCE(".."), IT_WAIST, ITR_COMMON, 1000, 0, 0, 0, 1, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("����Ʈ�� �㸮��", "���õ� �����ڸ� ���� �㸮��", "../Resources/�˻�_������_�۾�/������/��/�㸮��/����Ʈ��_�㸮��.png",
		RESOURCE(".."), IT_WAIST, ITR_UNCOMMON, 2000, 0, 0, 0, 2, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�ٽǸ���ũ�� �㸮��", "��� �����ڸ� ���� �㸮��", "../Resources/�˻�_������_�۾�/������/��/�㸮��/�ٽǸ���ũ��_�㸮��.png",
		RESOURCE(".."), IT_WAIST, ITR_RARE, 3000, 0, 0, 0, 3, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("����� ��� �㸮��", "�������� �����ڸ� ���� �㸮��", "../Resources/�˻�_������_�۾�/������/��/�㸮��/�����_���_�㸮��.png",
		RESOURCE(".."), IT_WAIST, ITR_EPIC, 4000, 0, 0, 0, 4, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	// ���� ����
	info = ItemInfo("�㸧�� ���� ����", "�ʺ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/�㸧�� ���� ����.png", 
		RESOURCE("Weapon/Shiled01.X"), IT_SHEILD, ITR_COMMON, 1000, 0, 0, 0, 1, true);
	info.SetMatrix(0.02f, 0.02f, 0.02f, 0, 0, 0, 0, 0, 0);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�λ縣 ����", "���õ� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/�λ縣 ����.png",
		RESOURCE("Weapon/Shiled02.X"), IT_SHEILD, ITR_UNCOMMON, 2000, 0, 0, 0, 2, true);
	info.SetMatrix(0.1f, 0.1f, 0.1f, 0, 0, 0, 0, 0, 0);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�� �λ縣 ����", "��� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/�� �λ縣 ����.png",
		RESOURCE("Weapon/Shiled03.X"), IT_SHEILD, ITR_RARE, 3000, 0, 0, 0, 3, true);
	info.SetMatrix(0.2f, 0.2f, 0.2f, 0, 0, 0, 0, 0, 0);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("�ı��� �λ縣 ����", "�������� �����ڸ� ���� ����", "../Resources/�˻�_������_�۾�/������/��/����/�ı��� �λ縣 ����.png",
		RESOURCE("Weapon/Shiled04.X"), IT_SHEILD, ITR_EPIC, 4000, 0, 0, 0, 4, true);
	info.SetMatrix(0.1f, 0.1f, 0.1f, 0, 0, 0, 0, 0, 0);
	MapItem.insert({ info.Name, info });

	//ITEM_MGR->CreateItem("�㸧�� ���� ����");
	//ITEM_MGR->CreateItem("�λ縣 ����");
	//ITEM_MGR->CreateItem("�� �λ縣 ����");
	//ITEM_MGR->CreateItem("�ı��� �λ縣 ����");

	// ����
	info = ItemInfo("hp ����", "ü��ȸ�������� ������", "../Resources/�˻�_������_�۾�/������/����/hp����.png",
		RESOURCE(""), IT_POTION, ITR_COMMON, 5000, 0, 0, 0, 100, false); // �ʹ� �ʰ� �����ؼ� ������ ��� def�� ȸ�� ��ġ ����
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });

	info = ItemInfo("mp ����", "����ȸ�������� ������", "../Resources/�˻�_������_�۾�/������/����/mp����.png",
		RESOURCE(""), IT_POTION, ITR_COMMON, 5000, 0, 0, 0, 100, false);
	info.SetMatrix(1, 1, 1, 0, 0, 0, 0.1, 0, 0.1);
	MapItem.insert({ info.Name, info });


}
