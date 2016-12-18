#pragma once
#include<vector>
#include "GameObject.h"
#include "QuadMesh.h"
#include "SphereMesh.h"

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
	void InitGameObjects();
	
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
	void RenderScene();
	void Reshape(int w, int h);
	
};

