#pragma once
#include "BaseMesh.h"

class CQuadMesh : public BaseMesh
{
private:
	Vertex g_quadVertices[4] = {
		{ 0.0f,0.0f, -1.0f, 0.0f, -1.0f },
		{ 1.0f,0.0f,  1.0f, 0.0f, -1.0f },
		{ 1.0f,1.0f,  1.0f, 0.0f,  1.0f },
		{ 0.0f,1.0f, -1.0f, 0.0f,  1.0f }
	};

public:
	CQuadMesh();
	CQuadMesh(const CQuadMesh& mesh);
	~CQuadMesh();

	// BaseMesh��(��) ���� ��ӵ�
	virtual void AttachMesh() override;
	virtual BaseMesh * Clone() const override;
};

