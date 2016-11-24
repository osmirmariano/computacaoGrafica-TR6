//Desenhar uma cena que possua iluminação/sombreamento.
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

GLfloat angle, fAspect, rotX, rotY;
GLdouble obsX, obsY, obsZ;
GLfloat r, g, b;
GLint especMaterial;   

// Função responsável pela especificação dos parâmetros de iluminação
void DefineIluminacao (){
    GLfloat luzAmbiente[4]={0.2,0.2,0.2,5.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};          // "cor"
    //GLfloat luzEspecular[4]={r, g, b, 1.0};
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    //glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}

// Função callback chamada para fazer o desenho
void Desenha(){
    // Limpa a janela de visualização com a cor de fundo definida previamente
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DefineIluminacao();
    // Troca cor corrente para verde
    glColor3f(0.0f, 1.0f, 0.0f);
    // Desenha o teapot com a cor corrente (wire-frame)
    glutSolidTeapot(50.0f);
    // Execução dos comandos de desenho
    glutSwapBuffers();
}


// Inicialização
void Inicializa(){
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_FLAT);

    // Inicializa a variável que especifica o ângulo da projeção
    // perspectiva
    angle=50;

    // Inicializa as variáveis usadas para alterar a posição do
    // observador virtual
    rotX = 30;
    rotY = 0;
    obsZ = 180;
    r, g, b = 1.0;
    especMaterial = 90;
}


// Função usada para especificar a posição do observador virtual
void PosicionaObservador(){
    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    DefineIluminacao();
    // Especifica posição do observador e do alvo
    glTranslatef(0,0,-obsZ);
    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);
}


// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(){
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();
    // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
    gluPerspective(angle,fAspect,0.5,500);
    PosicionaObservador();
}


// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    // Para previnir uma divisão por zero
    if (h == 0) h = 1;
    // Especifica as dimensões da viewport
    glViewport(0, 0, w, h);
    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;
    EspecificaParametrosVisualizacao();
}


// Callback para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN){
            // Zoom-in
            if (angle >= 10)
                angle -= 5;
        }
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN) {
            // Zoom-out
            if (angle <= 130)
                angle += 5;
        }
    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y){
    switch (tecla){
        case GLUT_KEY_LEFT: rotY--;
            break;
        case GLUT_KEY_RIGHT:rotY++;
            break;
        case GLUT_KEY_UP:   rotX++;
            break;
        case GLUT_KEY_DOWN: rotX--;
            break;
        case GLUT_KEY_HOME: obsZ++;
            break;
        case GLUT_KEY_END:  obsZ--;
            break;
    }
    PosicionaObservador();
    glutPostRedisplay();
}



// Programa Principal
int main(int argc, char **argv){
    glutInit(&argc, argv);
    // Define do modo de operacao da GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // Especifica o tamanho inicial em pixels da janela GLUT
    glutInitWindowSize(800,600);
    // Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(30,30);
    // Cria a janela passando como argumento o titulo da mesma
    glutCreateWindow("Desenho de uma cena com iluminação/sombreamento");
    // Registra a funcao callback de redesenho da janela de visualizacao
    glutDisplayFunc(Desenha);
    // Registra a funcao callback para tratamento das teclas especiais
    glutSpecialFunc(TeclasEspeciais);
    // Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);
    // Registra a funcao callback para tratamento do mouse
    glutMouseFunc(GerenciaMouse);
    Inicializa();
    glutMainLoop();
}