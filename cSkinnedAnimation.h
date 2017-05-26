#pragma once

#include "cXMesh_Skinned.h"
class Camera;

class cSkinnedAnimation
{
private:
	typedef std::map<BONE*, Transform*>						MAP_BONETRANSFORM;		//���εǴ� ��Transform ��
	typedef std::map< std::string, LPD3DXANIMATIONSET >			MAP_ANIMSET;
	typedef std::vector< LPD3DXANIMATIONSET >					VEC_ANIMSET;		

private:
	cXMesh_Skinned*		m_pSkinnedMesh;	
	MAP_BONETRANSFORM	m_mapApplyBoneTransform;
	MAP_BONETRANSFORM	m_mapBoneTransform;

	/////////////////////////////////////////////////////////////////////////////////

	LPD3DXANIMATIONCONTROLLER		m_pAnimController;			//Animation ��Ʈ�ѷ�
	UINT							m_AnimNum;					//Animation ����
	MAP_ANIMSET						m_mapAnimSet;				//Map ���� �Ǿ��ִ� AnimationSet
	VEC_ANIMSET						m_vecAnimSet;				//Vector �� �Ǿ��ִ� AnimationSet
	
	LPD3DXANIMATIONSET				m_pNowPlayAnimationSet;		//���� �÷��̵ǰ��ִ� AnimationSet
	D3DXTRACK_DESC					m_Track_Desc_0;				//0�� Track_Desc ( 0 �� Track �� ���� )
	
	bool							m_bPlay;					//���� �÷��� ���̴�?
	bool							m_bLoop;					//���� �÷��̴�?
	LPD3DXANIMATIONSET				m_pPrevPlayAnimationSet;	//OneShot �÷��̽� �ѹ� Animation �÷��̵ǰ� �ٽ� �ǵ��ư� Animaiton

	float							m_fCrossFadeTime;			//ũ�ν����̵� Ÿ��
	float							m_fLeftCrossFadeTime;		//����ũ�ν����̵� Ÿ��
	float							m_fOutCrossFadeTime;		//OneShot Animation ������ �ǵ��ư��� CrossFade Ÿ��

	double							manimationPlayFactor;		//Animation ���� Factor ( 0 �̸� ó�� 1 �ϼ��� ������ )


	float							m_fAnimDelta;

public:
	HRESULT		Init( cXMesh_Skinned* pSkinnedMesh );
	void		Release();
	void		Update( float timeDelta );
	void		Render(Transform* pTransform );
	void		RenderBoneName( Camera* pCam,  Transform* pTransform );

	
	void Play( std::string animName, float crossFadeTime = 0.0 );
	void Play( int animIndex, float crossFadeTime = 0.0 );
	void Play( LPD3DXANIMATIONSET animSet, float crossFadeTime = 0.0 );
	void PlayOneShot( std::string animName, float inCrossFadeTime = 0.0, float outCrossFadeTime = 0.0f );
	void PlayOneShotAfterHold( std::string animName, float crossFadeTime = 0.0 );
	void Stop(){
		this->m_bPlay = false;
		m_fLeftCrossFadeTime = 0;
		m_fCrossFadeTime = 0;
		m_pAnimController->SetTrackWeight(0, 1);
		m_pAnimController->SetTrackEnable(1, false);
	}
	void SetPlaySpeed( float speed );


	void AddBoneTransform( std::string boneName, Transform* pTransform );
	void AddApplyTransform( std::string boneName, Transform* pTransform );
	void RemoveBoneTransform( std::string boneName );
	void RemoveApplyTransform( std::string boneName );

	bool IsPlay() { return m_bPlay; }
	float GetPlayTime(std::string name) 
	{
		LPD3DXANIMATIONSET anim;
		m_pAnimController->GetAnimationSetByName(name.c_str(), &anim);
		return anim->GetPeriod();
	}

	std::string GetPlayName()
	{
		return m_pNowPlayAnimationSet->GetName();
	}

public:
	cSkinnedAnimation(void);
	~cSkinnedAnimation(void);

	cXMesh_Skinned* GetMesh() { return m_pSkinnedMesh; }
private:
	//Animation �� �ٲ۴�.
	void SetAnimation( LPD3DXANIMATIONSET animSet );



};

