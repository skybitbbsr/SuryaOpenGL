#include<Windows.h>
#include<GL/GL.h>
#include<GL/GLU.h>
#include<GL/GLUT.h>
#include<gl/freeglut_ext.h>

struct GLintPoint {
	GLint x, y;
};

int random(int m) {
	return rand() % m;
}

void drawDot(GLint x,GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void rec_triangle() {
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3] = { {10,10},{600,10},{300,600} };
	int index = random(3);
	GLintPoint point = T[index];
	drawDot(point.x, point.y);
	for (int i = 0; i < 55000; i++) {
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Recursive Triangle");
	glutDisplayFunc(rec_triangle);
	myInit();
	glutMainLoop();
	return 0;
}