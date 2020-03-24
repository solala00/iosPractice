#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

using namespace std;

float xAxis[3] = { 2,0,0 }, yAxis[3] = { 0,2,0 }, zAxis[3] = { 0,0,2 }, origin[3] = { 0,0,0 };
GLfloat Move[3] = { 0.1, 0.1, 0.1 };


void drawAxis(void)
{
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);
    glVertex3fv(origin);
    glVertex3fv(xAxis);

    glVertex3fv(origin);
    glVertex3fv(yAxis);

    glVertex3fv(origin);
    glVertex3fv(zAxis);

    glEnd();

    glRasterPos3f(2.1, 0.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');

    glRasterPos3f(0.0, 2.1, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');

    glRasterPos3f(0.0, 0.0, 2.1);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Z');
}


void drawCube(void)
{

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2,2,2,  0,0,0,  0,1,0);

    drawAxis();

    glPushMatrix();
    glTranslatef(Move[0],Move[1],Move[2]);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glBegin(GL_TRIANGLES);

    //2
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( -1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( -1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);

    //3
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( -1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( -1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    //6
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( -1.0f, -1.0f, 1.0f);
    glVertex3f( -1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( -1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    //1
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);

    //4
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( -1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    //5
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( -1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void changeSize(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-5,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a': case 'A':
        Move[0] += 0.1;
        break;
    case 'w': case 'W':
        Move[1] += 0.1;
        break;
    case 'q': case 'Q':
        Move[2] += 0.1;
        break;
    case 'd': case 'D':
        Move[0] -= 0.1;
        break;
    case 's': case 'S':
        Move[1] -= 0.1;
        break;
    case 'e': case 'E':
        Move[2] -= 0.1;
        break;
    case 'r': case 'R':
        Move[0] = 0.1;
        Move[1] = 0.1;
        Move[2] = 0.1;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(600, 80);
    glutCreateWindow("move cube");

    glutReshapeFunc(changeSize);
    glutDisplayFunc(drawCube);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 1;
}
