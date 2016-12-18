#include "Material.h"



void CMaterial::GiveEffect()
{
	GLfloat ambinet[4] = { mAmbient.x, mAmbient.y, mAmbient.z, mAmbient.w };
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambinet);
	
	GLfloat diffuse[4] = { mDiffuse.x, mDiffuse.y, mDiffuse.z, mDiffuse.w };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	
	GLfloat specular[4] = { mSpecular.x, mSpecular.y, mSpecular.z, mSpecular.w };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	
	glMaterialfv(GL_FRONT, GL_SHININESS, &mShiness);
}

void CMaterial::SetAmbient(const Vertex4 & ambient)
{
	this->mAmbient = ambient;
}

void CMaterial::SetDiffuse(const Vertex4 & diffuse)
{
	this->mDiffuse = diffuse;
}

void CMaterial::SetSpecular(const Vertex4 & specular)
{
	this->mSpecular = specular;
}

void CMaterial::SetEmission(const Vertex4 & Emission)
{
	this->mEmission = Emission;
}

void CMaterial::SetShiness(const GLfloat shiness)
{
	this->mShiness = shiness;
}

CMaterial::CMaterial()
{
}

CMaterial::CMaterial(const CMaterial & copyMaterial)
	:mAmbient(copyMaterial.mAmbient), mDiffuse(copyMaterial.mDiffuse), mSpecular(copyMaterial.mSpecular), mEmission(copyMaterial.mEmission), mShiness(copyMaterial.mShiness)
{
	//std::cout << "Material 복사 생성자" << std::endl;
}

CMaterial & CMaterial::operator=(const CMaterial & rhs)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->mDiffuse = rhs.mDiffuse;
	this->mSpecular = rhs.mSpecular;
	this->mEmission = rhs.mEmission;
	this->mShiness = rhs.mShiness;


	//std::cout << "Material 대입 연산자" << std::endl;

	return *this;
}

CMaterial * CMaterial::Clone()
{
	return new CMaterial(*this);
}


CMaterial::~CMaterial()
{
}
