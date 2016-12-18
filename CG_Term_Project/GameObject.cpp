#include "GameObject.h"



void CGameObject::InitMaterial(const CMaterial & material)
{
	if (mMaterial) delete mMaterial;
	this->mMaterial = new CMaterial(material);
}

void CGameObject::DeleteMesh()
{
	if (mMesh) delete mMesh;
	mMesh = nullptr;
}

void CGameObject::InitTexture(const CTexture & texture)
{
	if (mTexture) delete mTexture;
	this->mTexture = new CTexture(texture);
}

void CGameObject::DeleteTexture()
{
	if (mTexture) delete mTexture;
	mTexture = nullptr;
}

void CGameObject::DeleteCollider()
{
	if (mCollider) delete mCollider;
	mCollider = nullptr;
}

void CGameObject::InitRigidbody(const CRigidbody & rigidbody)
{
	if (mRigidbody) delete mRigidbody;
	this->mRigidbody = new CRigidbody(rigidbody);
}

void CGameObject::GenerateTexture()
{
	if (mTexture) mTexture->InitTexture();
}

void CGameObject::SetMesh(BaseMesh * mesh)
{
	this->mMesh = mesh;
}

BaseCollider * CGameObject::GetCollider()
{
	return this->mCollider;
}

CRigidbody * CGameObject::GetRigidbody()
{
	return this->mRigidbody;
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
	if (mMaterial) 
		mMaterial->GiveEffect();
	
	
	if (mTexture) {
		glEnable(GL_TEXTURE_2D);
		mTexture->AttachTexture();	//BindTexture
	}
	//Mesh
	if (mMesh) mMesh->AttachMesh();
	
	if (mTexture) glDisable(GL_TEXTURE_2D);
	
	glPopMatrix();
}

void CGameObject::SetTag(const std::string & tag)
{
	this->mTag = tag;
}

const std::string & CGameObject::GetTag()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return this->mTag;
}

void CGameObject::SetPosition(const Vertex3 & position)
{
	this->mPosition = position;
}

const Vertex3 & CGameObject::GetPosition()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return this->mPosition;
}

void CGameObject::SetRotation(const Vertex3 & rotation)
{
	this->mRotation = rotation;
}

void CGameObject::SetScale(const Vertex3 & scale)
{
	this->mScale = scale;
}

void CGameObject::AddPosition(const Vertex3 & addVertex3)
{
	this->mPosition = this->mPosition + addVertex3;
}


CGameObject::CGameObject()
	:mPosition(0.0f, 0.0f, 0.0f), mRotation(0.0f, 0.0f, 0.0f), mScale(1.0f, 1.0f, 1.0f)
{
}

CGameObject::CGameObject(const CGameObject & copyObject)
	:mTag(copyObject.mTag), mPosition(copyObject.mPosition), mRotation(copyObject.mRotation), mScale(copyObject.mScale), limitCount(copyObject.limitCount),
	mMaterial(copyObject.mMaterial != nullptr ? copyObject.mMaterial->Clone() : nullptr), mMesh(copyObject.mMesh != nullptr ? copyObject.mMesh->Clone() : nullptr),
	mTexture(copyObject.mTexture != nullptr ? copyObject.mTexture->Clone() : nullptr), mCollider(copyObject.mCollider != nullptr ? copyObject.mCollider->Clone() : nullptr),
	mRigidbody(copyObject.mRigidbody != nullptr ? copyObject.mRigidbody->Clone() : nullptr)
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
	this->mCollider = rhs.mCollider;
	this->mRigidbody = rhs.mRigidbody;

	//Member Primitive Variable
	this->mTag = rhs.mTag;
	this->mPosition = rhs.mPosition;
	this->mRotation = rhs.mRotation;
	this->mScale = rhs.mScale;

	//Rule
	this->limitCount = rhs.limitCount;

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
	if (mCollider) {
		delete mCollider;
		mCollider = nullptr;
	}
	if (mRigidbody) {
		delete mRigidbody;
		mRigidbody = nullptr;
	}
}
