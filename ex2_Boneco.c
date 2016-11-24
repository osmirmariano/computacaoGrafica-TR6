//Desenhar um boneco palito. Desenhar a casa palito em que esse boneco palito mora;
#include <GL/gl.h>
#include <GL/glut.h>
#define PI 3.1415926535

void desenho(){
	//Cor do fundo 
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// projecao do plano cartesiano
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// limitar o plano cartesiano
	gluOrtho2D(-30, 30, -30, 30); // limitado por um quadrado de lado 5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

  	glColor3f(0.0f, 0.0f, 1.0f);     
	// Desenha a casa
	glBegin(GL_QUADS);
		glVertex2f(-15.0f,-15.0f);
		glVertex2f(-15.0f,  5.0f);       
		glVertex2f( 15.0f,  5.0f);       
		glVertex2f( 15.0f,-15.0f);
	glEnd();

	// Altera a cor do desenho para branco
	glColor3f(1.0f, 1.0f, 1.0f);  
	// Desenha a porta e a janela  
	glBegin(GL_QUADS);
		glVertex2f(-4.0f,-14.5f);
		glVertex2f(-4.0f,  0.0f);       
		glVertex2f( 4.0f,  0.0f);       
		glVertex2f( 4.0f,-14.5f);       
		glVertex2f( 7.0f,-5.0f);
		glVertex2f( 7.0f,-1.0f);       
		glVertex2f(13.0f,-1.0f);       
		glVertex2f(13.0f,-5.0f);             
	glEnd();

	// Altera a cor do desenho para azul
	glColor3f(0.0f, 0.0f, 1.0f);     
	// Desenha as "linhas" da janela  
	glBegin(GL_LINES);      
		glVertex2f( 7.0f,-3.0f);      
		glVertex2f(13.0f,-3.0f);       
		glVertex2f(10.0f,-1.0f);    
		glVertex2f(10.0f,-5.0f);             
	glEnd();    

	// Altera a cor do desenho para vermelho
	glColor3f(1.0f, 0.0f, 0.0f); 
	// Desenha o telhado
	glBegin(GL_TRIANGLES);
		glVertex2f(-15.0f, 5.0f);   
		glVertex2f(  0.0f,17.0f);    
		glVertex2f( 15.0f, 5.0f);       
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f); 
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

 	
	// Executa os comandos OpenGL 
	glFlush();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	//Simple buffer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(450,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Casa e seu morador");

	//Chamando a função desenho
	glutDisplayFunc(desenho);
	glutMainLoop();
	return 0;
}