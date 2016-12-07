#include "SphereMesh.h"

CSphereMesh::CSphereMesh(GLdouble radius, GLfloat slices, GLint stacks)
	:BaseMesh(SPHERE),mRadius(radius),mSlices(slices),mStacks(stacks){}
CSphereMesh::CSphereMesh(const CSphereMesh & sphereMesh)
	:BaseMesh(sphereMesh.mMeshType), mRadius(sphereMesh.mRadius), mSlices(sphereMesh.mSlices), mStacks(sphereMesh.mStacks){}
CSphereMesh::~CSphereMesh() { std::cout << "SphereMesh ¼Ò¸êÀÚ" << std::endl; }

void CSphereMesh::AttachMesh()
{
	glutSolidSphere(mRadius, mSlices, mStacks);
}
