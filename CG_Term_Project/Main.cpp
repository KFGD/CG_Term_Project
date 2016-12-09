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
}

void initMap() {
	CGameObject object;
	CQuadMesh quadMesh;
	CTexture quadTexture("count_1.bmp");
	object.SetRotation(Vertex3(-35.0f, 0.0f, 0.0f));
	object.SetScale(Vertex3(2.0f, 2.0f, 0.0f));
	object.InitMesh(quadMesh);
	object.InitTexture(quadTexture);
	for (int i = -2.5; i < 2.5; ++i) {
		for (int j = -2.5; j < 2.5; ++j) {
			object.SetPosition(Vertex3(j * 2, i*2, 0.0f));
			app.InitGameObject(object);
		}
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("KFGD_ComputerGraphics_TermProject");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	script();
	initMap();

	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glutMainLoop();

	return 0;
}