#pragma once
#include "BaseCollider.h"
class CQuadCollider : public BaseCollider
{
public:
	const Vertex3& GetNormalVectorOfQuadCollider();
	void SetNormalVectorOfQuadCollider(const Vertex3& normalVector);
	const Vertex3& GetSizeOfQuadCollider();
	void SetSizeOfCQuadCollider(const Vertex3& size);

private:
	Vertex3 mNormalVector;
	Vertex3 mSize;

public:
	CQuadCollider();
	CQuadCollider(const Vertex3& centerPos, const Vertex3& normalVector, const Vertex3& size);
	CQuadCollider(const CQuadCollider& copyCollider);
	~CQuadCollider();
	CQuadCollider& operator=(const CQuadCollider& copyCollider);

	// BaseCollider을(를) 통해 상속됨
	virtual BaseCollider * Clone() const override;
};

