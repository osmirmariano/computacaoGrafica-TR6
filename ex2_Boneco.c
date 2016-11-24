//Desenhar um boneco palito. Desenhar a casa palito em que esse boneco palito mora;
#include <GL/glut.h>
#include <math.h>

#define frc 100
#define PI 3.1415926535897932

void Desenha(){
    //Cor do fundo Background
    glClearColor(1,1,1,1);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    // projecao do plano cartesiano
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);
        //triangulo 1
        glColor3f(0.0f, 0.0f, 0.0f);
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
        glColor3f(1.0f, 0.0f, 0.0f);
        for(int i=0; i < frc+1; i++)
        {
            glVertex2f(x+r*cos(2.0*PI*i/frc),y+r*sin(2.0*PI*i/frc));
        }
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.0f, 0.0f);
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
    // Executa os comandos OpenGL 
    glFlush();
}

void Inicializa(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Redimensiona(GLsizei w, GLsizei h){
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else
        gluOrtho2D(0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    //Simple buffer
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(450,100);
    glutInitWindowSize(700,500);
    glutCreateWindow("Boneco Palito e sua Casa");
    //Chamando a função desenho
    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    Inicializa();
    glutMainLoop();
}

