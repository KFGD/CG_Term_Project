#pragma once
#include <iostream>
#include <typeinfo>
#include "Material.h"
#include "BaseMesh.h"


class CGameObject
{
public:
	void InitMaterial(const CMaterial& material);
	template <typename T, typename = typename std::enable_if<std::is_base_of<BaseMesh, T>::value, T>::type> 
	void InitMesh(const T& mesh);
	void RenderObject();


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
	~CGameObject();
};

template <typename T, typename = typename std::enable_if<std::is_base_of<BaseMesh, T>::value, T>::type>
inline void CGameObject::InitMesh(const T & mesh)
{
	std::cout << typeid(T).name() << std::endl;
	if (mMesh) delete mMesh;
	mMesh = new T(mesh);
}
