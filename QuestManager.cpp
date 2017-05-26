#include "stdafx.h"
#include "QuestManager.h"

QuestManager::QuestManager()
{
}


QuestManager::~QuestManager()
{
}


void QuestManager::AddPlayerQuest(UINT questIndex,  PLAYER_QUEST playerQuestInfo){
	_questList.insert({ questIndex, playerQuestInfo });
}


void QuestManager::DeletePlayerQuest(UINT questIndex){

	if (_questList.size() > 1){
		_questList.erase(questIndex);
		//_questList.find(questIndex)->second.questNpc->GetInfo().questList.find(questIndex)->second.npcQuestStatus = UIQUEST::QUEST_STATUS::QUEST_END;
	}
	else{
		_questList.clear();
	}
}


void QuestManager::GiveUpPlayerQuest(UINT questIndex){

	if (_questList.size() > 1){
		
		(*_questList.find(questIndex)->second.questNpc)->SetQuestStatus(questIndex, UIQUEST::QUEST_STATUS::QUEST_BEGIN);
		
		_questList.erase(questIndex);
	
	}
	else{
		(*_questList.find(questIndex)->second.questNpc)->SetQuestStatus(questIndex, UIQUEST::QUEST_STATUS::QUEST_BEGIN);
		_questList.clear();
	}
}


// ��ü ����Ʈ �� �˻��ؼ� ������
PLAYER_QUEST QuestManager::GetPlayerQuest(UINT questIndex){
	//LOG_MGR->AddLog("����Ʈ�ε��� : %s", questIndex);
	return _questList.find(questIndex)->second;
}


// ��ü ����Ʈ ����Ʈ�� ������ ������
std::map<UINT, PLAYER_QUEST> QuestManager::GetPlayerQuestList(){
	return _questList;
}


void QuestManager::QuestComplete(UINT questIndex){
	if (_questList.size() > 1){

		(*_questList.find(questIndex)->second.questNpc)->SetQuestStatus(questIndex, UIQUEST::QUEST_STATUS::QUEST_END);

		_questList.erase(questIndex);

	}
	else{
		(*_questList.find(questIndex)->second.questNpc)->SetQuestStatus(questIndex, UIQUEST::QUEST_STATUS::QUEST_END);
		_questList.clear();
	}
}