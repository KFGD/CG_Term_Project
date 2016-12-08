#pragma once
#include "BaseMesh.h"
#include <iostream>

class CSphereMesh : public BaseMesh
{
public:
	CSphereMesh(GLdouble radius, GLfloat slices, GLint stackse);
	CSphereMesh(const CSphereMesh& sphereMesh);
	CSphereMesh& operator=(const CSphereMesh& rhs);
	~CSphereMesh();

private:
	GLdouble mRadius;
	GLfloat mSlices;
	GLint mStacks;

public:
	// BaseMesh��(��) ���� ��ӵ�
	virtual void AttachMesh() override;
	// BaseMesh��(��) ���� ��ӵ�
	virtual BaseMesh * Clone() const override;
};

