//para compilar execute: gcc -lGL -lGLU -lglut teste.c -o teste

#include <GL/gl.h>
#include <GL/glut.h>

//Drawing funciton
void draw(){
  //Background color
  glClearColor(1,1,1,1);
  //glClear(GL_COLOR_BUFFER_BIT );
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// projecao do plano cartesiano
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// limitar o plano cartesiano
	gluOrtho2D(-3, 3, -3, 3); // limitado por um quadrado de lado 5
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// iniciar o desenho de uma imagem...
	// Tracando linhas...
	/*
	glBegin(GL_LINES_STRIP);

	glVertex2f(-5, 5);
	glVertex2f(-5, -5);

	glVertex2f(-5, -5);
	glVertex2f(5, -5);

	glVertex2f(5, -5);
	glVertex2f(5, 5);

	glVertex2f(5, 5);
	glVertex2f(-5, 5);

	glEnd();*/
	
       glColor3f(1.0f, 0.0f, 0.0f); // sets color to black.
       glBegin(GL_TRIANGLE_STRIP); // draw in triangle strips
            glVertex2f(0.0f, 0.75f); // top of the roof
            glVertex2f(-0.5f, 0.25f); // left corner of the roof
            glVertex2f(0.5f, 0.25f); // right corner of the roof
            glVertex2f(-0.5f, -0.5f); // bottom left corner of the house
            glVertex2f(0.5f, -0.5f); //bottom right corner of the house
       glEnd();
       glutSwapBuffers();


	/* //Quadrado com degrade de verde para azul
	glBegin(GL_QUADS);
	
	glColor3f(1,1,0);

	glVertex2f(2, -2);	
	glVertex2f(2, 2);

	glColor3f(1,0,0);

	glVertex2f(-2, 2);
	glVertex2f(-2, -2);

	glEnd();
	*/

	//Triangulo com degrade de verde para azul
	/*glBegin(GL_TRIANGLES);
	
	glColor3f(0,1,0);

	glVertex2f(-2, -2);	
	glVertex2f(2, 2);

	glColor3f(0,0,1);

	glVertex2f(-2, 2);
	glVertex2f(-2, -2);

	glEnd();
	


  //Draw order
  glFlush();*/
}

//Main program
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Simple buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(50,25);
  glutInitWindowSize(500,500);
  glutCreateWindow("Gradiente Vermelho para Amarelo");

  //Call to the drawing function
  glutDisplayFunc(draw);
  glutMainLoop();

  return 0;
}