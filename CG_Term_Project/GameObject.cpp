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
	glColor3f(0.0f, 1.0f, 0.0f);
	//Mesh
	if (mMesh) mMesh->AttachMesh();
	
	glPopMatrix();
}


CGameObject::CGameObject()
	:mPosition(0.0f, 0.0f, 0.0f), mRotation(0.0f, 0.0f, 0.0f), mScale(1.0f, 1.0f, 1.0f)
{
}

CGameObject::CGameObject(const CGameObject & copyObject)
	:mPosition(copyObject.mPosition), mRotation(copyObject.mRotation), mScale(copyObject.mScale),
	mMaterial(copyObject.mMaterial != nullptr ? copyObject.mMaterial->Clone() : nullptr), mMesh(copyObject.mMesh != nullptr ? copyObject.mMesh->Clone() : nullptr)
{
	//std::cout << "GameObject ���� ������" << std::endl;
}

CGameObject & CGameObject::operator=(const CGameObject & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	
	this->mMaterial = rhs.mMaterial;
	this->mMesh = rhs.mMesh;

	this->mPosition = rhs.mPosition;
	this->mRotation = rhs.mRotation;
	this->mScale = rhs.mScale;

	//std::cout << "GameObject ���� ������" << std::endl;
	return *this;
}

CGameObject * CGameObject::Clone() const
{
	return new CGameObject(*this);
}


CGameObject::~CGameObject()
{
	//std::cout << "GameObject �Ҹ���" << std::endl;
	if (mMaterial) {
		delete mMaterial;
		mMaterial = nullptr;
	}
	if (mMesh) {
		delete mMesh;
		mMesh = nullptr;
	}
}
