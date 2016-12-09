#pragma once
#include "Utility.h"

class CTexture
{
private:
	std::string mFileName;
	GLuint mTexture;	//copyConstructor can't copy mTexture;

public:
	bool InitTexture();
	void AttachTexture();

public:
	CTexture(const std::string fileName);
	CTexture(const CTexture& copyTexture);
	CTexture& operator=(const CTexture& rhs);
	CTexture* Clone();
	~CTexture();
};

