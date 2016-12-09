#include "GameObject.h"



void CGameObject::InitMaterial(const CMaterial & material)
{
	if (mMaterial) delete mMaterial;
	this->mMaterial = new CMaterial(material);
}

void CGameObject::InitTexture(const CTexture & texture)
{
	if (mTexture) delete mTexture;
	this->mTexture = new CTexture(texture);
}

void CGameObject::GenerateTexture()
{
	if (mTexture) mTexture->InitTexture();
}

void CGameObject::SetMesh(BaseMesh * mesh)
{
	this->mMesh = mesh;
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
	
	
	if (mTexture) {
		glEnable(GL_TEXTURE_2D);
		mTexture->AttachTexture();	//BindTexture
	}
	else glColor3f(1.0f, 1.0f, 1.0f);
	
	//Mesh
	if (mMesh) mMesh->AttachMesh();
	
	if (mTexture) glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void CGameObject::SetPosition(const Vertex3 & position)
{
	this->mPosition = position;
}

void CGameObject::SetRotation(const Vertex3 & rotation)
{
	this->mRotation = rotation;
}


CGameObject::CGameObject()
	:mPosition(0.0f, 0.0f, 0.0f), mRotation(0.0f, 0.0f, 0.0f), mScale(1.0f, 1.0f, 1.0f)
{
}

CGameObject::CGameObject(const CGameObject & copyObject)
	:mPosition(copyObject.mPosition), mRotation(copyObject.mRotation), mScale(copyObject.mScale),
	mMaterial(copyObject.mMaterial != nullptr ? copyObject.mMaterial->Clone() : nullptr), mMesh(copyObject.mMesh != nullptr ? copyObject.mMesh->Clone() : nullptr), mTexture(copyObject.mTexture != nullptr ? copyObject.mTexture->Clone() : nullptr)
{
	//std::cout << "GameObject 복사 생성자" << std::endl;
}

CGameObject & CGameObject::operator=(const CGameObject & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	
	//Member Pointer Variable
	this->mMaterial = rhs.mMaterial;
	this->mMesh = rhs.mMesh;
	this->mTexture = rhs.mTexture;

	//Member Primitive Variable
	this->mPosition = rhs.mPosition;
	this->mRotation = rhs.mRotation;
	this->mScale = rhs.mScale;

	//std::cout << "GameObject 대입 연산자" << std::endl;
	return *this;
}

CGameObject * CGameObject::Clone() const
{
	return new CGameObject(*this);
}


CGameObject::~CGameObject()
{
	//std::cout << "GameObject 소멸자" << std::endl;
	if (mMaterial) {
		delete mMaterial;
		mMaterial = nullptr;
	}
	if (mMesh) {
		delete mMesh;
		mMesh = nullptr;
	}
	if (mTexture) {
		delete mTexture;
		mTexture = nullptr;
	}
}
