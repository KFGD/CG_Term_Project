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
	app.MovePlayer();
	glutPostRedisplay();
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

	//GLfloat whiteLight[4] = { 0.3,0.3, 0.3, 0.33 };
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);

	//GLfloat material_ambient[] = { 0.4,0.4,0.4,1.0 };
	//GLfloat material_diffuse[] = { 0.9,0.9,0.9,1.0 };
	//GLfloat material_specular[] = { 1.0,1.0,1.0,1.0 };
	//GLfloat material_shininess[] = { 25.0 };

	//glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

	app.InitObjects();

	glutMainLoop();

	return 0;
}