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

private:
	//BaseScene
	void InitMap();
	void InitUserObject();
	
	//Not BaseScene
	void PutGameObject(const CGameObject& gameObject);

private:
	//BaseScene
	const GLfloat mGravity = 0.0095f;
	std::vector<CGameObject*> mGameObjects;
	
	//Not BaseScene
	bool mIsGameClear;

	//Light
	//���� ��ġ �� planet A�� ��ġ
	const GLfloat light_position[4] = { 0.0f, 5.0f, 0.0f, 1.0f };
	const GLfloat light_ambient[4] = { 1.0f, 1.0f, 1.0f, 1.0f };	//�ֺ���
	const GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };	//�ݻ籤
	const GLfloat light_specular[4] = { 0.8f, 0.8f, 0.8f, 1.0f };//��鱤

private:
	void ClearScene();

public:
	void InitObjects();
	void RenderScene();
	void MovePlayer();
	void InputArrowKey(int key);
	void Reshape(int w, int h);
	
};

