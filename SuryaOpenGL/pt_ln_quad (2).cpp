#include<windows.h>
#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Test");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}