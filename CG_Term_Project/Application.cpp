#include "Application.h"


CApplication::CApplication()
{
}

CApplication::~CApplication()
{
}

void CApplication::InputGameObject(CGameObject gameObject)
{
	mGameObjects.push_back(gameObject);
}

void CApplication::RenderScene()
{
	for (CGameObject object : mGameObjects) {
		object.RenderObject();
	}
}

void CApplication::Reshape(int w, int h)
{
	float ratio = w / (float)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 10, 100);
}
