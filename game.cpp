#include<windows.h>

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<ctime>
#include<cstdlib>
#include<stdlib.h>
#include "game.h"

extern int score;

int gridX,gridY;
int snake_len=5;
bool food=true;
int foodX,foodY;
short sDirection = RIGHT;
int posX[MAXLENGTH]={20,20,20,20,20},posY[MAXLENGTH]{20,19,18,17,16};

extern bool gameOver;

void initGrid(int x,int y)
{
    gridX=x;
    gridY=y;
}


void unit(int,int);

void drawGrid()
{
    int i,j;
    for(i=0;i<gridX;i++)
    {
        for(j=0;j<gridY;j++)
        {
            unit(i,j);
        }
    }
}

void unit(int x,int y)
{
    if(x==0 || y==0 || x==gridX-1 || y==gridY-1)
    {
        glLineWidth(3.0);
        glColor3f(1.0,0.0,0.0);
    }

    else
    {
        glLineWidth(1.0);
        glColor3f(0.0,0.0,1.0);
    }
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}
//void randomf(int,int);
void drawFood()
{
    glColor3f(1,0,0);
    if(food)
        random(foodX,foodY);
    food=false;
    glRectf(foodX,foodY,foodX+1,foodY+1);//till here

}
void drawSnake()
{
    for(int i=snake_len-1;i>0;i--)
    {
        posX[i]=posX[i-1];
        posY[i]=posY[i-1];
    }
    if(sDirection==UP)
        posY[0]++;
    else if(sDirection==DOWN)
        posY[0]--;
    else if(sDirection==RIGHT)
        posX[0]++;
    else if(sDirection==LEFT)
        posX[0]--;
    for(int i=0;i<snake_len;i++)
    {
        if(i==0)
            glColor3f(0.0,1.0,0.0);
        else
            glColor3f(0.0,1.0,1.0);
        glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
    }
    if(posX[0]==0||posX[0]==gridX-1||posY[0]==0||posY[0]==gridY-1)
    {
        gameOver=true;
    }
    if(snake_len==7)
        gameOver=true;
    if(posX[0]==foodX &&posY[0]==foodY)
    {
        score++;
        snake_len++;
        if(snake_len>MAXLENGTH)
        {
            snake_len=MAXLENGTH;
        }


        food=true;

    }
}
void random(int &x,int &y)
{
    int _maxX=gridX-2;
    int _maxY=gridX-2;
    int _min=1;
    srand(time(NULL));
    x=_min+ rand() %(_maxX-_min);
    y=_min+ rand() %(_maxY-_min);
}

void setup()
{

    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="Your Score : ";
        strcat(text,_score);
        MessageBox(NULL,text,"GAME OVER",0);
        exit(0);
    }
}
void first()
{


    char c[]="SNAKE MANIA";
    int n=strlen(c);
    glColor3f(1,0,0);
    for(int i=0;i<n;i++)
    {

        glRasterPos2f(10+20*i,350);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c[i]);
    }

glutSwapBuffers();
}
