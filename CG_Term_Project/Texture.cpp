#include "Texture.h"



bool CTexture::InitTexture()
{
	AUX_RGBImageRec *textureimg[1];
	memset(textureimg, 0, sizeof(void *) * 1);

	textureimg[0] = LoadBMPFile(mFileName.c_str());
	glGenTextures(1, &mTexture);
	//glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, textureimg[0]->sizeX, textureimg[0]->sizeY, 0,
			GL_RGB, GL_UNSIGNED_BYTE, textureimg[0]->data);
	
	if (textureimg[0]) {
		if (textureimg[0]->data) free(textureimg[0]->data);
			free(textureimg[0]);
	}
	else return FALSE;
	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glDisable(GL_TEXTURE_2D);
	return TRUE;
}

void CTexture::AttachTexture()
{
	glBindTexture(GL_TEXTURE_2D, mTexture);
}


CTexture::CTexture(const std::string fileName)
	:mFileName(fileName.c_str())
{
}

CTexture::CTexture(const CTexture & copyTexture)
	:mFileName(copyTexture.mFileName)
{
}

CTexture & CTexture::operator=(const CTexture & rhs)
{
	this->mFileName = rhs.mFileName;

	return *this;
}

CTexture * CTexture::Clone()
{
	return new CTexture(*this);
}


CTexture::~CTexture()
{
	if (mTexture) {
		glDeleteTextures(1, &mTexture);
		mTexture = 0;
	}
}
