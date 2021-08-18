#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
int inX=0,inY=0;


void poli(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{

    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();

}
void myInit ()
{
    //glColor3f(0.0, 0.2, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 600, 0, 600, -10.0, 10.0);

}

void display ()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 255, 255);
    for(int j=0; j<4; j++)
    {
        int x1 = inX+0, yl= inY+0;
        int x2 = inX+75,y2= inY+0;
        int x3 = inX+75,y3= inY+75;
        int x4 = inX+0, y4= inY+75;
        for(int i=0; i<4; i++,x1+=150,x2+=150,x3+=150,x4+=150)
        {
            poli    (x1,yl,x2,y2,
                     x3,y3,x4,y4);

        }
        inX+=75;
        inY+=75;
        x1 = inX+0, yl= inY+0;
        x2 = inX+75,y2= inY+0;
        x3 = inX+75,y3= inY+75;
        x4 = inX+0, y4= inY+75;
        for(int i=0; i<4; i++,x1+=150,x2+=150,x3+=150,x4+=150)
        {
            poli    (x1,yl,x2,y2,
                     x3,y3,x4,y4);

        }
        inX=0;
        inY+=75;
    }
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(600,200);

    // Giving name to window
    glutCreateWindow("Chess Board by Taneem");
    myInit();

    glutDisplayFunc(display);
    //glutTimerFunc(25, update, 0);

    glutMainLoop();
}
