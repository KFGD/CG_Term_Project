#pragma once
#include "Application.h"
#include "SphereMesh.h"
#include "QuadMesh.h"
#include "Main.h"

CApplication app;

void display() {
	app.RenderScene();
}

void idleFunc() {
	if (!app.isClear && !app.isGameOver) {
		app.MovePlayer();
		glutPostRedisplay();
	}
}

void specialFunc(int key, int x, int y) {
	app.InputArrowKey(key);
}

void reshape(int w, int h) {
	app.Reshape(w, h);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("KFGD_ComputerGraphics_TermProject");

	glutDisplayFunc(display);
	glutIdleFunc(idleFunc);
	glutReshapeFunc(reshape);
	glutSpecialFunc(specialFunc);

	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);

	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	app.InitObjects();

	glutMainLoop();

	return 0;
}