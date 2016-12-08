#pragma once
#include "BaseMesh.h"

class CQuadMesh : public BaseMesh
{
public:
	CQuadMesh();
	CQuadMesh(const CQuadMesh& mesh);
	~CQuadMesh();

	// BaseMesh��(��) ���� ��ӵ�
	virtual void AttachMesh() override;
	virtual BaseMesh * Clone() const override;
};

