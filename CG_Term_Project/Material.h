#pragma once
#include "Utility.h"

class CMaterial
{
public:
	void GiveEffect();
	
private:
	Vertex4 mAmbient;
	Vertex4 mDiffuse;
	Vertex4 mSpecular;
	Vertex4 mEmission;
	GLfloat mShiness;

public:
	CMaterial();
	CMaterial(const CMaterial& copyMaterial);
	~CMaterial();
};

