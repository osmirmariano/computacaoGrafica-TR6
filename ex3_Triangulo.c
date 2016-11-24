//Desenhar dois triângulos, um verde e outro azul;

#include <GL/gl.h>
#include <GL/glut.h>

//Função para realizar o desenho dos triângulos
void desenho(){
  	//Background color
  	glClearColor(1,1,1,1);
  	glClear(GL_COLOR_BUFFER_BIT);

	// projecao do plano cartesiano
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// limitar o plano cartesiano
	gluOrtho2D(-10, 10, -10, 10); // limitado o tamanho
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

 	glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f); // vermelho
        glVertex2f(-8,-5);
        glVertex2f( 8,-5);
        glVertex2f(-8, 0);
        glColor3f(0.0f, 1.0f, 0.0f); // verde
        glVertex2f( 8, 0);
        glVertex2f(-8, 5);
        glVertex2f( 8, 5);
    glEnd();
  	glFlush();
}

int main(int argc, char **argv){
  	glutInit(&argc, argv);
  	//Simple buffer
  	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  	glutInitWindowPosition(450,100);
	glutInitWindowSize(350,350); //Limitando o qadrado, sendo de tamho 350 x 350
  	glutCreateWindow("Triângulos");

  	//Chamado a função desenhar
  	glutDisplayFunc(desenho);
  	glutMainLoop();
  	return 0;
}