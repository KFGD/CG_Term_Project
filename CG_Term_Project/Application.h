#pragma once
#include<vector>
#include "GameObject.h"

class CApplication
{
public:
	CApplication();
	~CApplication();

public:
	void InitGameObject(const CGameObject& gameObject);

private:
	//Scene
	std::vector<CGameObject*> mGameObjects;
	
private:
	void ClearScene();

public:
	void RenderScene();
	void Reshape(int w, int h);
	
};

