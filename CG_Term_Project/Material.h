#pragma once
#include <iostream>
#include "Utility.h"

class CMaterial
{
public:
	void GiveEffect();
	void SetAmbient(const Vertex4& ambient);
	void SetDiffuse(const Vertex4& diffuse);
	void SetSpecular(const Vertex4& specular);
	void SetEmission(const Vertex4& Emission);
	void SetShiness(const GLfloat shiness);
	
private:
	Vertex4 mAmbient;
	Vertex4 mDiffuse;
	Vertex4 mSpecular;
	Vertex4 mEmission;
	GLfloat mShiness;

public:
	CMaterial();
	CMaterial(const CMaterial& copyMaterial);
	CMaterial& operator=(const CMaterial& rhs);
	CMaterial* Clone();
	~CMaterial();
};

