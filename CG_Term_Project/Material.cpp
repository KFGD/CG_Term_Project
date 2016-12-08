#include "Material.h"



void CMaterial::GiveEffect()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, mAmbient.ToArray());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mDiffuse.ToArray());
	glMaterialfv(GL_FRONT, GL_SPECULAR, mSpecular.ToArray());
	glMaterialfv(GL_FRONT, GL_SHININESS, &mShiness);
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
