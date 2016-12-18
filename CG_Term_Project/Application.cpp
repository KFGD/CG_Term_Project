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


void CApplication::InitObjects()
{
	InitMap();
	InitUserObject();
}

void CApplication::InitMap()
{
	CGameObject object;
	CQuadMesh quadMesh;
	
	CTexture quadTexture("count_1.bmp");
	object.SetRotation(Vertex3(90.0f, 0.0f, 0.0f));
	object.SetScale(Vertex3(1.0f, 1.0f, 1.0f));
	object.InitMesh(quadMesh);
	object.InitTexture(quadTexture);
	object.SetTag("TILE");

	//Collider
	CQuadCollider quadCollider;

	for (int i = -2; i < 2; ++i) {
		for (int j = -2; j < 2; ++j) {
			object.SetPosition(Vertex3(j, i, 0.0f));
			//object.SetPosition(Vertex3(j, 0.0f, i));
			if (j == -1) {
				if (i == -1) {
					break;
				}
			}
			//Collider
			quadCollider.SetCenterPosOfCollider(Vertex3(0.0f, 0.0f, 0.0f));
			quadCollider.SetNormalVectorOfQuadCollider(Vertex3(0.0f, 1.0f, 0.0f));
			quadCollider.SetSizeOfCQuadCollider(Vertex3(1.0f, 0.0f, 1.0f));
			object.InitCollider(quadCollider);

			PutGameObject(object);
		}
	}
}

void CApplication::InitUserObject()
{
	CGameObject object;
	object.SetPosition(Vertex3(0.0f, 2.0f, 0.0f));

	//Mesh
	CSphereMesh sphereMesh(0.5f, 100, 100);
	object.InitMesh(sphereMesh);

	//Material
	CMaterial material;
	material.SetAmbient(Vertex4(0.2f, 0.2f, 0.2f, 1.0f));
	material.SetDiffuse(Vertex4(0.2f, 0.2f, 0.2f, 1.0f));
	material.SetSpecular(Vertex4(1.0f, 1.0f, 0.0f, 1.0f));
	material.SetEmission(Vertex4(0.0f, 0.0f, 0.0f, 1.0f));
	material.SetShiness(10.0f);
	object.InitMaterial(material);

	//Collider
	CSphereCollider sphereCollider(Vertex3(0.0f, 0.0f, 0.0f), 0.5f);
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
	gluLookAt(0, 5, 8, 0, 0, 0, 0, 1, 0);

	// LIGHT0 설정
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);  //주변광 성분 설정
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);  //반사광 성분 설정
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);//경면광 성분 설정
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);// 광원 위치 설정
	glEnable(GL_LIGHT0);	//Light0 활성화

}

void CApplication::MovePlayer()
{
	//Select UserObject
	CGameObject* userObject = nullptr;
	std::vector<CGameObject*> tileObject;

	for (int i = 0; i < mGameObjects.size(); ++i) {
		CGameObject* currentObject = mGameObjects.at(i);
		if (0 == currentObject->GetTag().compare("USER")) {
			userObject = currentObject;
		}
		else if (0 == currentObject->GetTag().compare("TILE")) {
			tileObject.push_back(currentObject);
		}
	}
	CRigidbody& userRigidbody = *(userObject->GetRigidbody());
	userRigidbody.AddDirectionVectorOfRigidbody(Vertex3(0.0f, -mGravity, 0.0f));	//중력
	
	Vertex3 curPos = userObject->GetPosition();	//현재 중심점 위치
	Vertex3 nextPos = curPos;
	nextPos = nextPos + userRigidbody.GetDirectionVectorOfRigidbody();	//이동할 중심점의 위치
	GLfloat radius = ((CSphereCollider*)userObject->GetCollider())->GetRadiusOfSphereCollider();	//구의 반지름

	Vertex3 nextBottomPointPos(nextPos.x, nextPos.y - radius, nextPos.z);
	for (int i = 0; i < tileObject.size(); ++i) {
		CGameObject* currentTile = tileObject.at(i);
		CQuadCollider* tileColider = (CQuadCollider*)currentTile->GetCollider();
		
		Vertex3 tileColiderPos = currentTile->GetPosition();
		tileColiderPos = tileColiderPos +tileColider->GetCenterPosOfCollider();
		


		if (tileColiderPos.x - 0.5f < nextPos.x && tileColiderPos.x + 0.5f > nextPos.x &&
			tileColiderPos.y - 0.5f < nextPos.z && tileColiderPos.y + 0.5f > nextPos.z &&
			nextPos.y <= 0) {
			nextPos = curPos;
			userRigidbody.SetDirectionVectorOfRigidbody(Vertex3(userRigidbody.GetDirectionVectorOfRigidbody().x, mGravity*20, userRigidbody.GetDirectionVectorOfRigidbody().z));
			nextPos = nextPos + userRigidbody.GetDirectionVectorOfRigidbody();
		}
	}
	userObject->SetPosition(nextPos);
}

void CApplication::InputArrowKey(int key)
{
	//Select UserObject
	CGameObject* userObject = nullptr;
	
	for (int i = 0; i < mGameObjects.size(); ++i) {
		CGameObject* currentObject = mGameObjects.at(i);
		if (0 == currentObject->GetTag().compare("USER")) {
			userObject = currentObject;
			break;
		}
	}
	CRigidbody& userRigidbody = *(userObject->GetRigidbody());
	userRigidbody.SetDirectionVectorOfRigidbody(Vertex3(0.0f, userRigidbody.GetDirectionVectorOfRigidbody().y, 0.0f));
	switch (key)
	{
	case GLUT_KEY_UP:
		userRigidbody.AddDirectionVectorOfRigidbody(Vertex3(0.0f, 0.0f, -0.01f));
		//userObject->AddPosition(Vertex3(0.0f, 0.0f, -0.1f));
		break;
	case GLUT_KEY_DOWN:
		userRigidbody.AddDirectionVectorOfRigidbody(Vertex3(0.0f, 0.0f, +0.01f));
		//userObject->AddPosition(Vertex3(0.0f, 0.0f, +0.1f));
		break;
	case GLUT_KEY_RIGHT:
		userRigidbody.AddDirectionVectorOfRigidbody(Vertex3(+0.01f, 0.0f, 0.0f));
		//userObject->AddPosition(Vertex3(+0.1f, 0.0f, 0.0f));
		break;
	case GLUT_KEY_LEFT:
		userRigidbody.AddDirectionVectorOfRigidbody(Vertex3(-0.01f, 0.0f, 0.0f));
		//userObject->AddPosition(Vertex3(-0.1f, 0.0f, 0.0f));
		break;
	default:
		break;
	}
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
	gluPerspective(45, ratio, 0.1, 100);
}
