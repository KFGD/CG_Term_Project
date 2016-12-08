#pragma once
#include "BaseMesh.h"

class CQuadMesh : public BaseMesh
{
public:
	CQuadMesh();
	CQuadMesh(const CQuadMesh& mesh);
	~CQuadMesh();

	// BaseMesh을(를) 통해 상속됨
	virtual void AttachMesh() override;
	virtual BaseMesh * Clone() const override;
};

