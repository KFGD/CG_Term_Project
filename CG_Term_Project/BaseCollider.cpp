#include "BaseCollider.h"



void BaseCollider::SetCenterPosOfCollider(const Vertex3 & centerPos)
{
	mCenterPos = centerPos;
}

const Vertex3 & BaseCollider::GetCenterPosOfCollider()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return mCenterPos;
}

BaseCollider::BaseCollider()
	:mIsTrigger(false)
{
}

BaseCollider::BaseCollider(const Vertex3 & centerPos)
	:mCenterPos(centerPos), mIsTrigger(false)
{
}

BaseCollider::BaseCollider(const BaseCollider & copyCollider)
	:mCenterPos(copyCollider.mCenterPos), mIsTrigger(copyCollider.mIsTrigger)
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
