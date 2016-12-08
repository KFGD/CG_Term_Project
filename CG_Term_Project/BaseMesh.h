#pragma once
#include <iostream>
#include "Utility.h"


class BaseMesh
{
public:
	virtual void AttachMesh() = 0;
	virtual BaseMesh* Clone() const = 0;

protected:
	GAMEOBJECT_TYPE mMeshType;

public:
	BaseMesh(GAMEOBJECT_TYPE type);
	BaseMesh(const BaseMesh& copyMesh);
	BaseMesh& operator=(const BaseMesh& copyMesh);
	virtual ~BaseMesh();
};

