#pragma once


#include "Singleton.h"
#include <map>
#include <string>

template< typename T, typename A >
class cResourceMgr : public Singleton<A>
{
protected:
	typedef std::map< std::string, T>			MAP_RESOURCE;

	MAP_RESOURCE		m_ResourceTable;		//리소스 테이블

public:
	cResourceMgr(void);
	~cResourceMgr(void);

	//파일 경로로 리소스를 불러온다.
	T GetResource( std::string filePath, void* pParam = NULL );	

	//특정 리소스 해제
	void RemoveResource( std::string filePath ); 

	//모든 리소스 해제
	void ClearResource();

protected:

	//로드 방식만 재정의 
	virtual T LoadResource( std::string filePath, void* pParam = NULL ) = 0;

	//해재 방식만 재정의
	virtual void ReleaseResource( T data ) = 0;
	
};

template< typename T, typename A >
cResourceMgr<T,A>::cResourceMgr(void)
{}


template< typename T, typename A >
cResourceMgr<T,A>::~cResourceMgr(void)
{
	//모든 리소스를 턴다.
	this->ClearResource();
}


template<typename T, typename A>
T cResourceMgr<T,A>::GetResource( std::string filePath, void* pParam )
{
	std::map<std::string,T>::iterator pFind;

	//이미 로딩되었는지 확인
	pFind = m_ResourceTable.find(filePath);

	//해당 filePath 가 맵에 추가 되어있지 않다면...
	if( pFind == m_ResourceTable.end() )
	{
		//LoadResource 함수로 새로운 Resource 로딩
		T newResource = LoadResource(filePath, pParam );

		//리소스 로딩이 실패되었다면 0 리턴
		if( newResource == 0 )
			return 0;

		//Map Table 에 추가
		m_ResourceTable.insert( std::make_pair( filePath,newResource) );

		return newResource;

	}


	//여기까지왔다면 이미 있다는거
	return pFind->second;
}


//특정 리소스 해제
template<typename T, typename A>
void cResourceMgr<T,A>::RemoveResource( std::string filePath )
{
	std::map<std::string,T>::iterator pFind;

	//이미 로딩되었는지 확인
	pFind = m_ResourceTable.find(filePath);

	//존재한다면...
	if( pFind != m_ResourceTable.end() )
	{
		//찾은 리소스 해재...
		ReleaseResource( pFind->second );

		//Iterator 가 가리키는 곳을 삭제.
		m_ResourceTable.remove( pFind );
	}
}


//모든 리소스 해제
template<typename T, typename A>
void cResourceMgr<T,A>::ClearResource()
{
	std::map<std::string,T>::iterator pIter;

	//Binary RedBlack Tree 로 되어있는 map에 다음과 같이 순차접근으로 모두 해제할때
	//중위 접근으로 털린다.
	for( pIter = m_ResourceTable.begin() ; pIter != m_ResourceTable.end() ; ++pIter )
	{
		ReleaseResource( pIter->second );
	}

	//Table
	m_ResourceTable.clear();
}