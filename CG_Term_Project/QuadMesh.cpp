#include "QuadMesh.h"



CQuadMesh::CQuadMesh()
	:BaseMesh(QUAD)
{
}

CQuadMesh::CQuadMesh(const CQuadMesh & mesh)
	:BaseMesh(mesh.mMeshType)
{
}


CQuadMesh::~CQuadMesh()
{
}

void CQuadMesh::AttachMesh()
{
	glBegin(GL_QUADS);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
	glEnd();
}

BaseMesh * CQuadMesh::Clone() const
{
	return new CQuadMesh(*this);
}
