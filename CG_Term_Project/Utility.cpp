#include"Utility.h"

//Convet String to wString
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

AUX_RGBImageRec *LoadBMPFile(const char* filename)
{ // 이미지 읽어오기
	FILE *pFile = NULL;
	if (!filename) return NULL;
	pFile = fopen(filename, "r");

	if (pFile) {
		fclose(pFile);
		std::wstring temp = s2ws(filename);
		return auxDIBImageLoad(temp.c_str());
	}
	return NULL;
}

Vertex3 Normalize(const Vertex3 & vector)
{
	float size = sqrtf((powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2)));
	Vertex3 result(vector.x / size, vector.y / size, vector.z / size);
	return result;
}

GLfloat DotProduct(const Vertex3 & vectorOne, const Vertex3 & vectorTwo)
{
	return vectorOne.x*vectorTwo.x + vectorOne.y*vectorTwo.y + vectorOne.z*vectorTwo.z;
}
