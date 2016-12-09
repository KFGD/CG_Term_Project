#pragma once
#include "Application.h"
#include "SphereMesh.h"
#include "QuadMesh.h"
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
	app.InitGameObject(object);

	CQuadMesh quadMesh;
	object.SetPosition(Vertex3(2.0f, 2.0f, 0.0f));
	object.InitMesh(quadMesh);
	app.InitGameObject(object);

	CTexture quadTexture("count_1.bmp");
	object.SetPosition(Vertex3(4.0f, 4.0f, 0.0f));
	object.SetRotation(Vertex3(-30.0f, 0.0f, 0.0f));
	object.InitTexture(quadTexture);
	app.InitGameObject(object);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("KFGD_ComputerGraphics_TermProject");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	script();
	
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glutMainLoop();

	return 0;
}