#include "BaseMesh.h"


BaseMesh::BaseMesh(GAMEOBJECT_TYPE type):mMeshType(type){}
BaseMesh::BaseMesh(const BaseMesh & copyMesh)
	: mMeshType(copyMesh.mMeshType) 
{
	//std::cout << "BaseMesh ���� ������ " << std::endl;
}
BaseMesh & BaseMesh::operator=(const BaseMesh & copyMesh)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	this->mMeshType = copyMesh.mMeshType;

	//std::cout << "BaseMesh ���� ������" << std::endl;

	return *this;
}
BaseMesh::~BaseMesh() 
{
	//std::cout << "BaseMesh�Ҹ���" << std::endl; 
}
