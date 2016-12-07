#pragma once
#include<vector>
#include "GameObject.h"

class CApplication
{
public:
	CApplication();
	~CApplication();

public:
	void InputGameObject(CGameObject gameObject);

private:
	std::vector<CGameObject> mGameObjects;

public:
	void RenderScene();
	void Reshape(int w, int h);
	
};

