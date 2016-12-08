#pragma once
#include <iostream>
#include <typeinfo>
#include "Material.h"
#include "BaseMesh.h"


/*
	Nameing Rule
	1. Init~: Param Object Copy And link to Member Variable
	2. Set~: Param OBject link to Member Variable
*/

class CGameObject
{
public:
	void InitMaterial(const CMaterial& material);
	template <typename T, typename = typename std::enable_if<std::is_base_of<BaseMesh, T>::value, T>::type> 
	void InitMesh(const T& mesh);
	void SetMesh(BaseMesh* mesh);
	void RenderObject();
	void SetPosition(const Vertex3& position);
	void SetRotation(const Vertex3& rotation);

private:
	//Basic
	Vertex3 mPosition;
	Vertex3 mRotation;
	Vertex3 mScale;
	
	//Material
	CMaterial* mMaterial = nullptr;

	//Mesh
	BaseMesh* mMesh = nullptr;

public:
	CGameObject();
	CGameObject(const CGameObject& copyObject);
	CGameObject& operator=(const CGameObject& rhs);
	virtual CGameObject* Clone() const;
	~CGameObject();
};

template <typename T, typename = typename std::enable_if<std::is_base_of<BaseMesh, T>::value, T>::type>
inline void CGameObject::InitMesh(const T & mesh)
{

	//std::cout << typeid(T).name() << std::endl;
	if (mMesh) 
		delete mMesh;
	this->mMesh = new T(mesh);
	//std::cout << "InitMesh 호출 완료" << std::endl;
}