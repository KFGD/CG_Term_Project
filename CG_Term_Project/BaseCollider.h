#pragma once
#include "Utility.h"

class BaseCollider
{
public:
	virtual BaseCollider* Clone() const = 0;

	void SetCenterPosOfCollider(const Vertex3& centerPos);
	const Vertex3& GetCenterPosOfCollider();

protected:
	Vertex3 mCenterPos;
	bool mIsTrigger;

public:
	BaseCollider();
	BaseCollider(const Vertex3& centerPos);
	BaseCollider(const BaseCollider& copyCollider);
	BaseCollider& operator=(const BaseCollider& copyCollider);
	virtual ~BaseCollider();
};

