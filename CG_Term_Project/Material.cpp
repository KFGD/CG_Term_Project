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
	:mAmbient(copyMaterial.mAmbient), mDiffuse(copyMaterial.mDiffuse), mSpecular(copyMaterial.mSpecular), mEmission(copyMaterial.mEmission), mShiness(copyMaterial.mShiness){}


CMaterial::~CMaterial()
{
}
