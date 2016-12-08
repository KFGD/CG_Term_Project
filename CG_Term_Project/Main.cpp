#pragma once
#include "Application.h"
#include "SphereMesh.h"
#include "Main.h"

CApplication app;

void display() {
	app.RenderScene();
}


void reshape(int w, int h) {
	app.Reshape(w, h);
}

void script() {
	CGameObject object;
	CSphereMesh sphereMesh(1.0f, 100, 100);
	object.InitMesh(sphereMesh);
	app.InputGameObject(object);
	std::cout << "script 호출 완료" << std::endl;
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("KFGD_ComputerGraphics_TermProject");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	script();
	
	glutMainLoop();

	return 0;
}