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

void CApplication::Run()
{
	InitScene();
}

void CApplication::InitScene()
{
	InitMap();
	InitUserObject();
}

void CApplication::InitMap()
{
	CGameObject object;
	CQuadMesh quadMesh;
	
	CTexture quadTexture("count_1.bmp");
	object.SetRotation(Vertex3(-35.0f, 0.0f, 0.0f));
	object.SetScale(Vertex3(2.0f, 2.0f, 0.0f));
	object.InitMesh(quadMesh);
	object.InitTexture(quadTexture);

	//Collider
	CQuadCollider quadCollider;

	for (int i = -2.5; i < 2.5; ++i) {
		for (int j = -2.5; j < 2.5; ++j) {
			object.SetPosition(Vertex3(j * 2, i * 2, 0.0f));
			
			//Collider
			quadCollider.SetCenterPosOfCollider(Vertex3(0.0f, 0.0f, 0.0f));
			quadCollider.SetNormalVectorOfQuadCollider(Vertex3(0.0f, 90.0f, 0.0f));
			quadCollider.SetSizeOfCQuadCollider(Vertex3(1.0f, 0.0f, 1.0f));
			object.InitCollider(quadCollider);

			PutGameObject(object);
		}
	}
}

void CApplication::InitUserObject()
{
	CGameObject object;
	CSphereMesh sphereMesh(1.0f, 100, 100);
	object.InitMesh(sphereMesh);

	//Collider
	CSphereCollider sphereCollider(Vertex3(0.0f, 0.0f, 0.0f), 1.0f);
	object.InitCollider(sphereCollider);

	//Rigidbody
	CRigidbody rigidbody;
	object.InitRigidbody(rigidbody);

	object.SetTag("USER");

	PutGameObject(object);
}

void CApplication::PutGameObject(const CGameObject& gameObject)
{
	
	CGameObject* copyObject = gameObject.Clone();
	copyObject->GenerateTexture();
	mGameObjects.push_back(copyObject);
}

void CApplication::ClearScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 15, 0, 0, 0, 0, 1, 0);
}

void CApplication::MovePlayer()
{

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
	gluPerspective(45.0f, ratio, 10, 100);
}
