#pragma once
#include<vector>
#include "GameObject.h"
#include "QuadMesh.h"
#include "SphereMesh.h"
#include "QuadCollider.h"
#include "SphereCollider.h"

class CApplication
{
public:
	CApplication();
	~CApplication();

public:
	void Run();

private:
	//BaseScene
	void InitScene();
	void InitMap();
	void InitUserObject();
	
	//Not BaseScene
	void PutGameObject(const CGameObject& gameObject);

private:
	//BaseScene
	std::vector<CGameObject*> mGameObjects;
	
	//Not BaseScene
	bool mIsGameClear;

private:
	void ClearScene();

public:
	void MovePlayer();
	void RenderScene();
	void Reshape(int w, int h);
	
};

