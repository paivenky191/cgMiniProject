#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include "game.h"
#include<stdio.h>
#include<stdlib.h>
#define COLUMNS 40
#define ROWS 40
#define FPS 7

extern short sDirection;
bool gameOver=false;

int score=0;
int flag=0;

void timer_callback(int);
void display_callback();

void reshape_callback(int,int);
void mymouse_callback(int,int,int,int);
void mykey(unsigned char,int,int);
void mykey_callback(int,int,int);

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    //printf("helloi am init");


}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(690,690);
    glutInitWindowPosition(100,0);

    glutCreateWindow("SNAKE MANIA");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(mykey_callback);
    glutKeyboardFunc(mykey);
   // glutMouseFunc(mymouse_callback);
    init();
    //first();
    glutMainLoop();
    return 0;
}

void display_callback()
{


    if(flag==0)
    {

         char c[]="  SNAKE MANIA";
         char c1[]="           press s/S to continue...";
    int n=strlen(c);
    int n1=strlen(c1);
    glColor3f(1,0,0);
    for(int i=0;i<n;i++)
    {

        glRasterPos2f(3*i,28);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c[i]);
    }
    //glutSwapBuffers();*/
     glColor3f(1,0,0);
    for(int i=0;i<n1;i++)
    {

        glRasterPos2f(i,15);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c1[i]);
    }

glutSwapBuffers();

    }


    glClear(GL_COLOR_BUFFER_BIT);
    if(flag){
            initGrid(COLUMNS,ROWS);
        setup();
    }



}

void reshape_callback(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void mykey(unsigned char x,int h,int y)
{
    if(x=='s'||x=='S')
    {
        flag=1;
    }
}


void mykey_callback(int key,int,int)
{
        switch(key)
        {
        case GLUT_KEY_UP:
            if(sDirection !=DOWN)
                sDirection=UP;
            break;
        case GLUT_KEY_DOWN:
            if(sDirection !=UP)
                sDirection=DOWN;
            break;
        case GLUT_KEY_RIGHT:
            if(sDirection !=LEFT)
                sDirection=RIGHT;
            break;
        case GLUT_KEY_LEFT:
            if(sDirection !=RIGHT)
                sDirection=LEFT;
            break;

        }
}
