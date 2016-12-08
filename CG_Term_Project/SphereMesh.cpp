#include "SphereMesh.h"

CSphereMesh::CSphereMesh(GLdouble radius, GLfloat slices, GLint stacks)
	:BaseMesh(SPHERE),mRadius(radius),mSlices(slices),mStacks(stacks){}
CSphereMesh::CSphereMesh(const CSphereMesh & sphereMesh)
	: BaseMesh(sphereMesh), mRadius(sphereMesh.mRadius), mSlices(sphereMesh.mSlices), mStacks(sphereMesh.mStacks) {
	//std::cout << "SphereMesh ���� ������ " << std::endl;
}
CSphereMesh & CSphereMesh::operator=(const CSphereMesh & rhs)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	this->mMeshType = rhs.mMeshType;
	this->mRadius = rhs.mRadius;
	this->mSlices = rhs.mSlices;
	this->mStacks = rhs.mStacks;

	//std::cout << "SphereMesh ���� ������" << std::endl;

	return *this;
}
CSphereMesh::~CSphereMesh() 
{
	//std::cout << "SphereMesh �Ҹ���" << std::endl; 
}

void CSphereMesh::AttachMesh()
{
	glutSolidSphere(mRadius, mSlices, mStacks);
}

BaseMesh * CSphereMesh::Clone() const
{
	return new CSphereMesh(*this);
}
