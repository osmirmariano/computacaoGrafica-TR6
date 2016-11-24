//Trabalho 18  Desenhar um cubo, cujo cada lado possua uma cor diferente
//Trabalho 18  Desenhar um cubo, cujo cada lado possua uma cor diferente
#include <GL/glut.h>
//#include <windows.h>
#include <stdio.h>
//#include <GL/GLAux.h>

GLfloat angulo, aspecto, Rx,Ry, ObsZ;
GLint idTextura;

//carregar arquivo de textura
void Iluminacao(void)
{
    //tipos de luz
    GLfloat LuzAmbiente[4] = {0.2, 0.2, 0.2, 1.0};
    GLfloat LuzDifusa[4] = {0.7, 0.7, 0.7, 1.0};
    GLfloat LuzEspecular[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat LuzPosicao[4] = {0, 50, 50, 1.0};

    //Capacidade Brilho do Material
    GLfloat Especularidade[4] = {1.0, 1.0, 1.0, 1.0};
    GLint EspecMaterial = 60;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Habilitar mode de colorir de Gouraud
    glShadeModel(GL_SMOOTH);

    //Capacidade de reletância do Material
    glMaterialfv(GL_FRONT,GL_SPECULAR, Especularidade);
    glMateriali(GL_FRONT, GL_SHININESS, EspecMaterial);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LuzAmbiente);

    //Definicao dos Parametros de luz
    glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LuzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LuzPosicao);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

}
void Observador(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Iluminacao();

    glTranslatef(0,0,-ObsZ);
    glRotatef(Rx,1,0,0);
    glRotatef(Ry,0,1,0);
}

void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
        // Face frontal

        glColor3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        // Face posterior
        glColor3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        // Face superior
        glColor3f(0.0, 0.0, 1.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        // Face inferior
        glColor3f(0.0, 1.0, 1.0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        // Face lateral direita
        glColor3f(1.0, 1.0, 0.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        // Face lateral esquerda
        glColor3f(1.0, 0.0, 1.0);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();

    glutSwapBuffers();
}

void Inicializa(void)
{
    Iluminacao();
    angulo = 50;
    Rx = 30;
    Ry = 0;
    ObsZ = 10;
}

void EspecificacaoParametrosVisualizacao(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(angulo, aspecto, 0.1, 500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,80,200, 0,0,0, 0,1,0 );
}
void Redimensiona(GLsizei w, GLsizei h)
{
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    aspecto = (GLfloat)w/(GLfloat)h;

    EspecificacaoParametrosVisualizacao();
}
void ControleMouse(int botao, int estado, int x, int y)
{
    if(botao == GLUT_LEFT_BUTTON)
    {
         if(estado == GLUT_DOWN)
         {
             if(angulo >= 10) angulo -=5;
         }
    }
    if(botao == GLUT_RIGHT_BUTTON)
    {
         if(estado == GLUT_DOWN)
         {
             if(angulo <= 130) angulo +=5;
         }
    }
    EspecificacaoParametrosVisualizacao();
    glutPostRedisplay();
}
void ControleTeclado(int tecla, int x, int y)
{
  switch(tecla)
  {
    case GLUT_KEY_LEFT: Ry--;
        break;
    case GLUT_KEY_RIGHT: Ry++;
        break;
    case GLUT_KEY_UP: Rx++;
        break;
    case GLUT_KEY_DOWN: Rx--;
        break;
    case GLUT_KEY_HOME: ObsZ++;
        break;
    case GLUT_KEY_END: ObsZ--;
        break;
    case GLUT_KEY_F12:
                Rx = 30;
                Ry = 0;
                ObsZ = 10;
                angulo = 50;
                EspecificacaoParametrosVisualizacao();
                break;
  }
  Observador();
  glutPostRedisplay();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(20,20);
    glutCreateWindow(" Luz e Sombra");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(Redimensiona);
    glutMouseFunc(ControleMouse);
    glutSpecialFunc(ControleTeclado);
    Inicializa();
    glutMainLoop();
}