#include "BaseCollider.h"



void BaseCollider::SetCenterPosOfCollider(const Vertex3 & centerPos)
{
	mCenterPos = centerPos;
}

const Vertex3 & BaseCollider::GetCenterPosOfCollider()
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	this->mCenterPos = copyCollider.mCenterPos;
	this->mIsTrigger = copyCollider.mIsTrigger;

	return *this;
}


BaseCollider::~BaseCollider()
{
}
