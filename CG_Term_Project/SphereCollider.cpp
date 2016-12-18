#include "SphereCollider.h"



void CSphereCollider::SetRadiusOfSphereCollider(const GLfloat radius)
{
	this->mRadius = radius;
}

const GLfloat CSphereCollider::GetRadiusOfSphereCollider()
{
	return this->mRadius;
}

CSphereCollider::CSphereCollider()
	:mRadius(0.0f), BaseCollider()
{
}

CSphereCollider::CSphereCollider(const Vertex3 & centerPos, const GLfloat mRadius)
	:BaseCollider(centerPos), mRadius(mRadius)
{
}

CSphereCollider::CSphereCollider(const CSphereCollider & copyCollider)
	:mRadius(copyCollider.mRadius), BaseCollider(copyCollider)
{
}


CSphereCollider::~CSphereCollider()
{
}

CSphereCollider & CSphereCollider::operator=(const CSphereCollider & copyCollider)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->mCenterPos = copyCollider.mCenterPos;
	this->mIsTrigger = copyCollider.mIsTrigger;
	this->mRadius = copyCollider.mRadius;

	return *this;
}

BaseCollider * CSphereCollider::Clone() const
{
	return new CSphereCollider(*this);
}
