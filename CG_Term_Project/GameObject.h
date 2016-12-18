#pragma once
#include <iostream>
#include <typeinfo>
#include "Material.h"
#include "BaseMesh.h"
#include "Texture.h"
#include "BaseCollider.h"
#include "Rigidbody.h"

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
	void DeleteMesh();
	void InitTexture(const CTexture& texture);
	void DeleteTexture();
	template <typename T, typename = typename std::enable_if<std::is_base_of<BaseCollider, T>::value, T>::type>
	void InitCollider(const T& collider);
	void DeleteCollider();
	void InitRigidbody(const CRigidbody& rigidbody);
	void GenerateTexture();

	void SetMesh(BaseMesh* mesh);
	BaseCollider* GetCollider();
	CRigidbody* GetRigidbody();

	void RenderObject();
	void SetTag(const std::string& tag);
	const std::string& GetTag();
	void SetPosition(const Vertex3& position);
	const Vertex3& GetPosition();
	void SetRotation(const Vertex3& rotation);
	void SetScale(const Vertex3& scale);
	void AddPosition(const Vertex3& addVertex3);

private:
	//Basic
	std::string mTag;
	Vertex3 mPosition;
	Vertex3 mRotation;
	Vertex3 mScale;
	
	//Material
	CMaterial* mMaterial = nullptr;

	//Mesh
	BaseMesh* mMesh = nullptr;

	//Texture
	CTexture* mTexture = nullptr;

	//Collider
	BaseCollider* mCollider = nullptr;
	
	//Rigidbody
	CRigidbody* mRigidbody = nullptr;

	//Rule
public:
	int limitCount = -1;

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

template <typename T, typename = typename std::enable_if<std::is_base_of<BaseCollider, T>::value, T>::type>
inline void CGameObject::InitCollider(const T & collider)
{
	if (mCollider)
		delete mCollider;
	this->mCollider = new T(collider);
}

