#include "Application.h"


CApplication::CApplication()
{
}

CApplication::~CApplication()
{
	for (int i = 0; i < mGameObjects.size(); ++i) {
		CGameObject* object = mGameObjects.at(i);
		delete object;
	}
}

void CApplication::InputGameObject(const CGameObject& gameObject)
{
	//std::cout << "InputGameObject" << std::endl;

	//CGameObject* copyObject = new CGameObject(gameObject);
	mGameObjects.push_back(gameObject.Clone());
}

void CApplication::ClearScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 15, 15, 0, 0, 0, 0, 1, 0);
}

void CApplication::RenderScene()
{
	ClearScene();
	for (int i = 0; i < mGameObjects.size(); ++i) {
		CGameObject* object = mGameObjects.at(i);
		object->RenderObject();
	}
	glFlush();
	glutSwapBuffers();
}

void CApplication::Reshape(int w, int h)
{
	float ratio = w / (float)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 10, 100);
}
