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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	this->mCenterPos = copyCollider.mCenterPos;
	this->mIsTrigger = copyCollider.mIsTrigger;

	return *this;
}


BaseCollider::~BaseCollider()
{
}
