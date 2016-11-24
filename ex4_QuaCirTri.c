//Criar um quadrado que possua em seu interior uma circunferência e a circunferência possua 
//em seu interior um triângulo, o triângulo deve possuir um degradê do vermelho para o preto 
//e o centro das formas são coincidentes.
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define frc 100
#define PI 3.1415926535897932

void Desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    //Atribuindo a cor do background (fundo)
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

void Inicializa(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
    glutInitWindowSize(500,500); //Limitando o qadrado, sendo de tamho 500 x 500
    glutCreateWindow("Quadrado, Circunferência e Triângulo Degradê");
    //Chamando a função Draw para desenhar
    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    Inicializa();
    glutMainLoop();
}