#pragma once
#include<vector>
#include"Utility.h"
#include"GameObject.h"

class BaseScene
{
public:

protected:
	std::vector<CGameObject*> mGameObjects;

public:
	BaseScene();
	~BaseScene();
};

