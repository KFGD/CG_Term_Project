#pragma once
#include<gl\glut.h>
#include<math.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<GLAUX.H>
#pragma comment(lib, "legacy_stdio_definitions.lib")

struct Vertex {
	float tu, tv;
	float x, y, z;
};

struct Vertex3 {
	GLfloat x, y, z;

	Vertex3():x(0.0f),y(0.0f),z(0.0f) {}
	Vertex3(GLfloat _x, GLfloat _y, GLfloat _z):x(_x),y(_y),z(_z){}
	Vertex3(const Vertex3& vertex3):x(vertex3.x),y(vertex3.y),z(vertex3.z){}
};

struct Vertex4 {
	GLfloat x, y, z, w;

	Vertex4() :x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	Vertex4(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w) :x(_x), y(_y), z(_z),w(_w) {}
	Vertex4(const Vertex4& vertex4) :x(vertex4.x), y(vertex4.y), z(vertex4.z), w(vertex4.w) {}
	float* ToArray() { GLfloat glArray[4] = { x, y, z, w }; return glArray; }
};

enum GAMEOBJECT_TYPE {
	QUAD,
	SPHERE,
};

//Convet String to wString
std::wstring s2ws(const std::string& s);
AUX_RGBImageRec *LoadBMPFile(const char* filename);