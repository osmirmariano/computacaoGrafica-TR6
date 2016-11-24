//Trabalho 15  Desenhar boneco palito e a casa do boneco palito
#include <gl/glut.h>
#include <windows.h>
#include <math.h>

#define frc 100
#define PI 3.1415926535897932

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);

            //triangulo 1
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2i(200,50);
            glVertex2i(205,50); //porta inicio
            glVertex2i(205,85); //
            glVertex2i(225,85); //
            glVertex2i(225,50); //
            glVertex2i(205,50);// porta fim
            glVertex2i(300,50);
            glVertex2i(300,100);
            glVertex2i(200,100);
            glVertex2i(225,130);
            glVertex2i(250,100); // fim triangulo teto
            glVertex2i(300,100);
            glVertex2i(300,130);
            glVertex2i(225,130);
            glVertex2i(200,100);
            glVertex2i(200,50);

    glEnd();

    glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2i(250,65);
            glVertex2i(270,65);
            glVertex2i(270,85);
            glVertex2i(250,85);
            glVertex2i(250,65);

    glEnd();

    //cabeça do boneco
    int x=90,y=100,r=8;
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 1.0f);
        for(int i=0; i < frc+1; i++)
        {
            glVertex2f(x+r*cos(2.0*PI*i/frc),y+r*sin(2.0*PI*i/frc));
        }
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2i(90,92);
        glVertex2i(90,65);
        glVertex2i(100,50);
        glVertex2i(90,65);
        glVertex2i(80,50);
        glVertex2i(90,65);
        glVertex2i(90,92);
        glVertex2i(100,75);
        glVertex2i(90,92);
        glVertex2i(80,75);
        glVertex2i(90,92);
    glEnd();

    glFlush();
}

void Inicializa(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Redimensiona(GLsizei w, GLsizei h)
{
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if(w <= h)
            gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else
            gluOrtho2D(0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(20,20);
    glutCreateWindow(" Boneco Palito e sua Casa");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    Inicializa();
    glutMainLoop();
}


//Trabalho 17  Criar um quadrado que tenha em seu interior uma circunferência, a circunferência deve
// ter em seu interior um triângulo e o triângulo deve possuir um degradê de vermelho para o preto
#include <gl/glut.h>
#include <windows.h>
#include <math.h>

#define frc 100
#define PI 3.1415926535897932
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    //Quadrado
    glBegin(GL_LINE_LOOP);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2i(50, 50);
            glVertex2i(200, 50);
            glVertex2i(200, 200);
            glVertex2i(50, 200);
            glVertex2i(50, 50);
    glEnd();
    //circunferencia
    int x=125,y=125,r=73;
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        for(int i=0; i < frc+1; i++)
        {
            glVertex2f(x+r*cos(2.0*PI*i/frc),y+r*sin(2.0*PI*i/frc));
        }
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    //triangulo
    glBegin(GL_TRIANGLES);

            glVertex2i(62, 95);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2i(122, 195);
            glVertex2i(190, 95);
    glEnd();

    glFlush();
}

void Inicializa(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Redimensiona(GLsizei w, GLsizei h)
{
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if(w <= h)
            gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else
            gluOrtho2D(0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(20,20);
    glutCreateWindow(" Quadrado,Circunferencia e Triangulo Degradê ");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    Inicializa();
    glutMainLoop();
}

