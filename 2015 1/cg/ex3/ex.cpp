#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

void DesenhaObjeto(){
	
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
		float RAIO = .1;

		while(RAIO < 10){			
			for (float i = 0; i < 2 * 3.14; i += 0.1){
				float x = cos(i) * RAIO;
				float y = sin(i) * RAIO;
				glVertex2f(x, y);
				RAIO += 0.01;
			}
		}
	glEnd();

	glFlush();
}

int main(int argc, char **argv){
	// //Init configs
	// glutInit(&argc, argv);
	// glutInitDisplayMode(GLUT_SINGLE);

	// //Window configs
	// glutInitWindowSize(500,500);
	// glutInitWindowPosition(500,500);
	// glutCreateWindow("EX1");

	// glOrtho(-10, 10, -10, 10, -2, 2);
	// glutDisplayFunc(draw);
	// glutMainLoop();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,500);
	glutCreateWindow("EX");

	glutDisplayFunc(draw);
	
	glOrtho(-10, 10, -10, 10, -2, 2);
	glutMainLoop();
}