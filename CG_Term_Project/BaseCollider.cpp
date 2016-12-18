#include "BaseCollider.h"



void BaseCollider::SetCenterPosOfColider(const Vertex3 & centerPos)
{
	mCenterPos = centerPos;
}

BaseCollider::BaseCollider()
	:mIsTrigger(false)
{
}

BaseCollider::BaseCollider(const Vertex3 & centerPos)
	:mCenterPos(centerPos), mIsTrigger(false)
{
}

BaseCollider & BaseCollider::operator=(const BaseCollider & copyCollider)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->mCenterPos = copyCollider.mCenterPos;
	this->mIsTrigger = copyCollider.mIsTrigger;

	return *this;
}


BaseCollider::~BaseCollider()
{
}
