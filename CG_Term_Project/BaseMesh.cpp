#include "BaseMesh.h"


BaseMesh::BaseMesh(GAMEOBJECT_TYPE type):mMeshType(type){}
BaseMesh::BaseMesh(const BaseMesh & copyMesh)
	: mMeshType(copyMesh.mMeshType) 
{
	//std::cout << "BaseMesh 복사 생성자 " << std::endl;
}
BaseMesh & BaseMesh::operator=(const BaseMesh & copyMesh)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->mMeshType = copyMesh.mMeshType;

	//std::cout << "BaseMesh 대입 연산자" << std::endl;

	return *this;
}
BaseMesh::~BaseMesh() 
{
	//std::cout << "BaseMesh소멸자" << std::endl; 
}
