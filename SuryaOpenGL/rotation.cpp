void draw_triangle(void){
glTranslatef(translate_x, translate_y, 0);
glRotatef(beta, 1, 0, 0);
glRotatef(alpha, 0, 1, 0);
glColor3f(1, 1, 1);

if(strcmp(_triangle->texture_path, "" ) != 0){
glBegin(GL_TRIANGLES);
glTexCoord2f( (_triangle->v[0]).x, (_triangle->v[0]).y);
glVertex2f((_triangle->v[0]).x, (_triangle->v[0]).y);
glTexCoord2f( (_triangle->v[1]).x, (_triangle->v[1]).y);
glVertex2f((_triangle->v[1]).x, (_triangle->v[1]).y);
glTexCoord2f ((_triangle->v[2]).x, (_triangle->v[2]).y);
glVertex2f((_triangle->v[2]).x, (_triangle->v[2]).y);
glEnd();
}else{
glBegin(GL_TRIANGLES);
glVertex2f((_triangle->v[0]).x, (_triangle->v[0]).y);
glVertex2f((_triangle->v[1]).x, (_triangle->v[1]).y);
glVertex2f((_triangle->v[2]).x, (_triangle->v[2]).y);
glEnd();
}

glScalef(xscale, yscale, 1.0f);
}

void DisplayFunc_triangle(void){

glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();

glViewport(0, 0, width / 2, height / 2);
glPushMatrix();
glTranslatef(0, 0, -10);
glRotatef(0, 1, 0, 0);
glRotatef(0, 0, 1, 0);

GLfloat light_position[] = { 0, 0, 1, 0};
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
draw_axis();
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
draw_triangle();
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glPopMatrix();

glMatrixMode(GL_PROJECTION);
glPushMatrix();

glLoadIdentity();
glOrtho(-1.2, 1.2, -1.2, 1.2, -1.2, 1.2);
glMatrixMode(GL_MODELVIEW);

glViewport(0, height / 2 + 1, width / 2 + 1, height / 2);
glPushMatrix();
glRotatef(90, 0, 1, 0);
draw_axis();

enable_texture2D();
draw_triangle();
glPopMatrix();

disable_texture2D();
glViewport(width / 2 + 1, height / 2 + 1, width / 2, height / 2);
glPushMatrix();
draw_axis();
enable_texture2D();
draw_triangle();
glPopMatrix();
disable_texture2D();

glViewport(width / 2 + 1, 0, width / 2, height / 2);
glPushMatrix();
glRotatef(90, 1, 0, 0);
draw_axis();
enable_texture2D();
draw_triangle();
glPopMatrix();
disable_texture2D();

glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);

glFlush();
glutSwapBuffers();
}

void MotionFunc_triangle(int x, int y){
if (GLUT_DOWN == left_click){
beta = beta + (y - yold) / 2.f;
alpha = alpha + (x - xold) / 2.f;
glutPostRedisplay();
}else if(GLUT_DOWN == right_click){
translate_x = translate_x + (x - xold )/300.0;
translate_y = translate_y + (y - yold )/300.0;
glutPostRedisplay();
}
xold = x;
yold = y;
}
