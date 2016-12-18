#pragma once
#include "Utility.h"

class BaseCollider
{
public:
	virtual BaseCollider* Clone() const = 0;

	void SetCenterPosOfColider(const Vertex3& centerPos);
	virtual void OnTriggerEnter(const BaseCollider& colider) = 0;
	virtual void OnCollisionEnter(const BaseCollider& colider) = 0;

protected:
	Vertex3 mCenterPos;
	bool mIsTrigger;

public:
	BaseCollider();
	BaseCollider(const Vertex3& centerPos);
	BaseCollider& operator=(const BaseCollider& copyCollider);
	~BaseCollider();
};

