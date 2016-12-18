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
	bool isClear = false;
	bool isGameOver = false;
	CApplication();
	~CApplication();

private:
	//BaseScene
	void InitMap();
	void InitUserObject();
	void InitGoalObjects();
	
	//Not BaseScene
	void PutGameObject(const CGameObject& gameObject);

	void ClearScene();
private:
	//BaseScene
	const GLfloat mGravity = 0.0095f;
	std::vector<CGameObject*> mGameObjects;

	//Light
	//���� ��ġ �� planet A�� ��ġ
	const GLfloat light_position[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_ambient[4] = { 1.0f, 1.0f, 1.0f, 1.0f };	//�ֺ���
	const GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };	//�ݻ籤
	const GLfloat light_specular[4] = { 0.8f, 0.8f, 0.8f, 1.0f };//��鱤

public:
	void InitObjects();
	void RenderScene();
	void MovePlayer();
	void InputArrowKey(int key);
	void Reshape(int w, int h);
	
};

