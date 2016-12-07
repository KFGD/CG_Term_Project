#include "GameObject.h"



void CGameObject::InitMaterial(const CMaterial & material)
{
	this->mMaterial = new CMaterial(material);
}

void CGameObject::RenderObject()
{
	glPushMatrix();
	
	//Roatation
	glRotatef(mRotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(mRotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(mRotation.z, 0.0f, 0.0f, 1.0f);

	//Translation
	glTranslatef(mPosition.x, mPosition.y, mPosition.z);

	//Scale
	glScalef(mScale.x, mScale.y, mScale.z);

	//Material
	if (mMaterial) mMaterial->GiveEffect();

	//Mesh
	if (mMesh) mMesh->AttachMesh();
	
	glPopMatrix();
}


CGameObject::CGameObject()
{
}


CGameObject::~CGameObject()
{
	if (mMaterial) {
		delete mMaterial;
		mMaterial = nullptr;
	}
	if (mMesh) {
		delete mMesh;
		mMesh = nullptr;
	}
}
