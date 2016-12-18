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

void initMap() {
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("KFGD_ComputerGraphics_TermProject");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	app.Run();

	glutMainLoop();

	return 0;
}