    #include "Primitives.h"
    #include <GL/glut.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include <cstring>
    using namespace std;

    int w=400;
    int h=300;
    int leafSize=100;

    float randx, randy;

    float color=0.8;
    int score=0;
    bool started=0;

    char *string1="TOVARISCH MAIOR";
    char *string20="Feel as TOVARISCH MAIOR";
    char *string21="catch junkies and get more shoulder pips";

void outputchapter()
{
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(w/2+90, h+40);
    int len, i;
    len=strlen(string1);
    for(i=0; i<len; i++)
    {
        glutBitmapCharacter((void*)GLUT_BITMAP_HELVETICA_18, string1[i]);
    }
}

void outputdescription()
{
    glColor3f(1.0, 0.75, 0.79);
    glRasterPos2f(w/2+60, 3*h/4-10);
    int len20, i;
    len20=strlen(string20);
    for(i=0; i<len20; i++)
    {
        glutBitmapCharacter((void*)GLUT_BITMAP_HELVETICA_18, string20[i]);
    }


}

void outputdescription2()
{
    glColor3f(1.0, 0.75, 0.79);
    glRasterPos2f(w/2+20, 3*h/4-30);
    int len21, i;
    len21=strlen(string21);
    for(i=0; i<len21; i++)
    {
        glutBitmapCharacter((void*)GLUT_BITMAP_HELVETICA_18, string21[i]);
    }
}

void outputscore()
{
    glColor3f(1.0, 0.80, 0.80);
    glRasterPos2f(10, 2*h-30);
    char* tscore="STARS  ";
    char* chscore;
    char buffer[20];
    chscore = itoa(score, buffer, 10);
    int lensc, i;
    lensc=strlen(tscore);
    for(i=0; i<lensc; i++)
    {
        glutBitmapCharacter((void*)GLUT_BITMAP_HELVETICA_18, tscore[i]);
    }
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(80, 2*h-30);
    for(i=0; i<strlen(chscore); i++)
        glutBitmapCharacter((void*)GLUT_BITMAP_HELVETICA_18, chscore[i]);
}

void startgame(unsigned char key, int x, int y)
{
    if (key==' ')
        started=1;
}

    void setNextPos()
    {
        srand(time (NULL)+400);
        randy=((rand()%200)+90);

        srand(time(NULL)-160);
        randx=((rand()%300)+50);

        double i;
        i=rand()%2;
        if(i==0) {randx=2*w - randx;}
        i=rand()%2;
        if(i==0) {randy=2*h - randy;}
    }


    void reshape(int w, int h)
    {
        glViewport(0, 0, w, h);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        if(started==0)
        {
            outputchapter();
            outputdescription();
            outputdescription2();
        }

        if (started==1)
        {
            setNextPos();

            Vector2D t;
            leaf F(t, leafSize, 0, color, 0);
            F.moveRight(randx);
            F.moveUp(randy);
            F.print();
            outputscore();
        }

        glutSwapBuffers();
    }

    void mouseButton(int button, int state, int x, int y)
    {
        if (button == GLUT_LEFT_BUTTON)
		{

		    if (state == GLUT_DOWN && (x>randx-leafSize/2 && x<randx+leafSize/2) && (y>(2*h-(randy+ 0.9*leafSize)) && y<(2*h-(randy-0.1*leafSize))))
                {
                    score++;
                    color=0.2;
                }
		}
		if (state == GLUT_UP) {color=0.8;}
		glutPostRedisplay();
    }

    void timer(int = 0)
    {
        glutPostRedisplay();
        glutTimerFunc(50, timer, 0);
    }

    int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w*2, h*2);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Tovarisch Maior");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutTimerFunc(50, timer, 0);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMouseFunc(mouseButton);
    glutKeyboardFunc(startgame);

    glutMainLoop();

    return 0;
}
