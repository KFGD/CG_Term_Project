#include "Texture.h"



bool CTexture::InitTexture()
{
	AUX_RGBImageRec *textureimg[1];
	memset(textureimg, 0, sizeof(void *) * 1);

	textureimg[0] = LoadBMPFile(mFileName.c_str());
	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, textureimg[0]->sizeX, textureimg[0]->sizeY, GL_RGB,
		GL_UNSIGNED_BYTE, textureimg[0]->data);

	if (textureimg[0]) {
		if (textureimg[0]->data) free(textureimg[0]->data);
			free(textureimg[0]);
	}
	else return FALSE;
	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
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
