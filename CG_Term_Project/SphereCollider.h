#pragma once
#include "BaseCollider.h"

class CSphereCollider : public BaseCollider
{
public:
	void SetRadiusOfSphereCollider(const GLfloat radius);
	const GLfloat GetRadiusOfSphereCollider();


private:
	GLfloat mRadius;

public:
	CSphereCollider();
	CSphereCollider(const Vertex3& centerPos, const GLfloat mRadius);
	CSphereCollider(const CSphereCollider& copyCollider);
	~CSphereCollider();
	CSphereCollider& operator=(const CSphereCollider& copyCollider);

	// BaseCollider��(��) ���� ��ӵ�
	virtual BaseCollider * Clone() const override;
};

