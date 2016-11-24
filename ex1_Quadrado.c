//Criar um quadrado que possua um gradiente do vermelho para o amarelo;

#include <GL/gl.h>
#include <GL/glut.h>

//Função para criar o desenho
void desenho(){
  	// Para a cor do fundo 
  	glClearColor(1,1,1,1);
  	glClear(GL_COLOR_BUFFER_BIT );
	// Para projeção do plano cartesiano
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Para limitar o plano cartesiano
	gluOrtho2D(-3, 3, -3, 3); // limitado por um quadrado de lado 5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Quadrado com degrade de vermelho para Amarelo
	glBegin(GL_QUADS);
	glColor3f(1,1,0);
	glVertex2f(2, -2);	
	glVertex2f(2, 2);
	glColor3f(1,0,0);
	glVertex2f(-2, 2);
	glVertex2f(-2, -2);
	glEnd();
  	//Ordem do Desenho
  	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	//Simple buffer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(450,100);
	glutInitWindowSize(500,500); //Limitando o qadrado, sendo de tamho 500 x 500
	glutCreateWindow("Gradiente Vermelho para Amarelo"); //Texto que aparecerá na barra de status

	//Chamando a função Draw para desenhar
	glutDisplayFunc(desenho);
	glutMainLoop();
	return 0;
}