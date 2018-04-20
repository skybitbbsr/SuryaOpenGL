#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
void lineBressenham(int xa, int ya, int xb, int yb)
{
	int x, y, xEnd, yEnd;
	int dx = abs(xa - xb);
	int dy = abs(ya - yb);
	int p = 2 * dy - dx;
	int twody = 2 * dy;
	int twodydx = 2 * (dy - dx);
	float m = (float)(yb - ya) / (float)(xb - xa);
	if ((m >= 0) && (m <= 1))
	{
		if (xa>xb)
		{
			x = xb;
			y = yb;
			xEnd = xa;
		}
		else
		{
			x = xa;
			y = ya;
			xEnd = xb;
		}

		setpixel(x, y);
		while (x<xEnd)
		{
			x++;
			if (p<0)
				p += twody;
			else
			{
				y++;
				p += twodydx;
			}

			setpixel(x, y);
		}
	}

	else if (m>1)
	{
		if (ya>yb)
		{
			x = xb;
			y = yb;
			yEnd = ya;
		}
		else
		{
			x = xa;
			y = ya;
			yEnd = yb;
		}

		setpixel(x, y);
		while (y<yEnd)
		{
			y++;
			if (p<0)
				p += 2 * dx;
			else
			{
				x++;
				p += 2 * (dx - dy);
			}

			setpixel(x, y);
		}
	}
	else if (m<-1)
	{
		if (ya>yb)
		{
			x = xb;
			y = yb;
			yEnd = ya;
		}
		else
		{
			x = xa;
			y = ya;
			yEnd = yb;
		}

		setpixel(x, y);
		while (y<yEnd)
		{
			y--;
			if (p<0)
				p += 2 * dx;
			else
			{
				x++;
				p += 2 * (dx - dy);
			}

			setpixel(x, y);
		}
	}
	else if ((m >= -1) && (m <= 0))
	{
		if (xa>xb)
		{
			x = xb;
			y = yb;
			xEnd = xa;
		}
		else
		{
			x = xa;
			y = ya;
			xEnd = xb;
		}

		setpixel(x, y);
		while (x<xEnd)
		{
			x++;
			if (p<0)
				p += twody;
			else
			{
				y--;
				p += twodydx;
			}

			setpixel(x, y);
		}
	}

}
void setdata()
{
	int xa, xb, ya, yb;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(4.0);
	printf("Enter the points : ");
	scanf_s("%d %d %d %d", &xa, &ya, &xb, &yb);
	lineBressenham(xa, ya, xb, yb);
}
int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bressenham Line Algorithm");
	init();
	glutDisplayFunc(setdata);
	glutMainLoop();
	return 0;
}