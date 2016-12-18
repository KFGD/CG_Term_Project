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
	float value = 1.0f;
	glBegin(GL_QUADS);
	//glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	//glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	//glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 0.0f);
	//glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, +0.5f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(+0.5f, +0.5f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(+0.5f, -0.5f, 0.0f);
	glEnd();

}

BaseMesh * CQuadMesh::Clone() const
{
	return new CQuadMesh(*this);
}
