#include "BaseMesh.h"


BaseMesh::BaseMesh(GAMEOBJECT_TYPE type):mMeshType(type){}
BaseMesh::BaseMesh(const BaseMesh & copyMesh)
	:mMeshType(copyMesh.mMeshType){}
BaseMesh::~BaseMesh() { std::cout << "BaseMesh¼Ò¸êÀÚ" << std::endl; }
