#pragma once

//여기에 UI 태그 넘버 셋팅을 한다.
//define? enum? 뭘로 하지
namespace UITag
{
	enum
	{
		UI_SCREEN = 100,

		//우측 하단

		UI_SCREEN_ICON_INVENTORY,
		UI_SCREEN_ICON_QUEST,
		UI_SCREEN_ICON_SKILL,
		UI_SCREEN_ICON_EXIT,

		//좌측 상단

		UI_SCREEN_EXP,

		//가운데 하단

		UI_SCREEN_HPBAR,
		UI_SCREEN_MPBAR,

		//가운데 하단 스킬

		UI_SCREEN_SOCKET = 150,

		//스킬

		UI_SKILL = 200,
		UI_SKILL_DISC,
		UI_SKILL_SOCKET = 250,

		//인벤토리

		UI_INVENTORY = 300,
		UI_INVENTORY_SOCKET = 350,

		// 아이템 장착
		UI_EQUIPPEDITEM = 420,
		UI_EQUIPPEDITEM_SOCKET = 450,
		UI_EQUIPPEDITEM_HEAD,
		UI_EQUIPPEDITEM_BODY,
		UI_EQUIPPEDITEM_GLOVE,
		UI_EQUIPPEDITEM_SHOES,
		UI_EQUIPPEDITEM_SHEILD,
		UI_EQUIPPEDITEM_WAIST,
		UI_EQUIPPEDITEM_RING,
		UI_EQUIPPEDITEM_NECKLESS,
		UI_EQUIPPEDITEM_EARING,
		UI_EQUIPPEDITEM_WEAPON,
	
		//마우스 소켓

		UI_MOUSE_SOCKET = 1000,

		//NPC 대화

		UI_DIALOG = 1100,
		UI_DIALOG_CLOSE,
		UI_DIALOG_BEGIN,
		UI_DIALOG_QUEST,
		UI_DIALOG_QUEST_NEXT,
		UI_DIALOG_QUEST_ACCEPT,
		UI_DIALOG_QUEST_NO,
		UI_DIALOG_QUEST_GIVE_UP,
		UI_DIALOG_QUEST_SOCKET = 1150,
		
		//maptool

		UI_MAPTOOL = 1200,
		UI_MAPTOOL_OBJECT_TAB,
		UI_MAPTOOL_OBJECT_LIST,
		UI_MAPTOOL_CHARACTER_TAB,
		UI_MAPTOOL_CHARACTER_LIST,

		UI_MAPTOOL_OBJECT = 1210,
		UI_MAPTOOL_OBJECT_END = 1309,
		UI_MAPTOOL_CHARACTER = 1310,
		UI_MAPTOOL_CHARACTER_END = 1409,

		// 상점
		UI_SHOP = 1700,
		UI_SHOP_OPEN,
		UI_SHOP_SELL,
		UI_SHOP_BUY,
		//UI tag 갯수


		// 상점 여러개 수량 판매
		UI_SHOP_COUNT_PLUS,
		UI_SHOP_COUNT_MINUS,
		UI_SHOP_BTN_OK,
		UI_SHOP_BTN_CANCLE,

		UI_SHOP_BUY_INVENTORY_SOCKET = 1730,

		UI_END
	};
}

#define SCREEN_SOCKET(i) (UITag::UI_SCREEN_SOCKET + i)
#define SCREEN_SOCKET_IDX(tagNum) (tagNum - UITag::UI_SCREEN_SOCKET)

#define SKILL_SOCKET(i) (UITag::UI_SKILL_SOCKET + i)
#define SKILL_SOCKET_IDX(tagNum) (tagNum - UITag::UI_SKILL_SOCKET)

#define INVENTORY_SOCKET(i) (UITag::UI_INVENTORY_SOCKET + i)
#define INVENTORY_SOCKET_IDX(tagNum) (tagNum - UITag::UI_INVENTORY_SOCKET)

#define SHOP_BUY_SOCKET(i) (UITag::UI_SHOP_BUY_INVENTORY_SOCKET + i)
#define SHOP_BUY_SOCKET_IDX(tagNum) (tagNum - UITag::UI_SHOP_BUY_INVENTORY_SOCKET)

#define EQUIPPED_ITEM_SOCKET(i) (UITag::UI_EQUIPPEDITEM_SOCKET + i)
#define EQUIPPED_ITEM_SOCKET_IDX(tagNum) (tagNum - UITag::UI_EQUIPPEDITEM_SOCKET)

#define MAPTOOL_OBJ_TAG(i) (UITag::UI_MAPTOOL_OBJECT + i)
#define MAPTOOL_OBJ_IDX(tagNum) (tagNum - UITag::UI_MAPTOOL_OBJECT)

#define MAPTOOL_CHAR_TAG(i) (UITag::UI_MAPTOOL_CHARACTER + i)
#define MAPTOOL_CHAR_IDX(tagNum) (tagNum - UITag::UI_MAPTOOL_CHARACTER)

namespace UIDB
{
	enum
	{
		QUEST = 1,
		SHOP = 2,

		BUTTON_END
	};
}