#include "QuadCollider.h"



const Vertex3 & CQuadCollider::GetNormalVectorOfQuadCollider()
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return this->mNormalVector;
}

void CQuadCollider::SetNormalVectorOfQuadCollider(const Vertex3 & normalVector)
{
	this->mNormalVector = normalVector;
}

const Vertex3 & CQuadCollider::GetSizeOfQuadCollider()
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return this->mSize;
}

void CQuadCollider::SetSizeOfCQuadCollider(const Vertex3 & size)
{
	this->mSize = size;
}

CQuadCollider::CQuadCollider()
{
}

CQuadCollider::CQuadCollider(const Vertex3 & centerPos, const Vertex3 & normalVector, const Vertex3 & size)
	:BaseCollider(centerPos), mNormalVector(normalVector), mSize(size)
{
}

CQuadCollider::CQuadCollider(const CQuadCollider & copyCollider)
	: BaseCollider(copyCollider), mNormalVector(copyCollider.mNormalVector), mSize(copyCollider.mSize)
{
}

CQuadCollider::~CQuadCollider()
{
}

CQuadCollider & CQuadCollider::operator=(const CQuadCollider & copyCollider)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	this->mCenterPos = copyCollider.mCenterPos;
	this->mIsTrigger = copyCollider.mIsTrigger;
	this->mNormalVector = copyCollider.mNormalVector;
	this->mSize = copyCollider.mSize;

	return *this;
}

BaseCollider * CQuadCollider::Clone() const
{
	return new CQuadCollider(*this);
}
