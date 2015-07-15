#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>

int NUM_LADOS = 3;
int RAIO = 25.0;


void drawText(){
/*
The explanation for this is found in the man page for glRasterPos-- raster operations maintain their own state for current color and current texture coordinate (e.g. GL_CURRENT_RASTER_COLOR) In this case, with lighting turned off, the state is copied from GL_CURRENT_COLOR *when you call glRasterPos2f*. So glColor4f between that and a raster operation is ignored.
*/
	glColor3f(0.4, 0.4, 0.5);		// A ordem das duas funções 
	glRasterPos2f(18.0, 10.0);		// muda o comportamento do programa
	char s[] = "Pressione + ou - para alterar o poligono";

	for(char c : s)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
}

void drawScene(){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	float step = (6.2831) / NUM_LADOS;
	float cenX=50.0,  cenY=50.0;
	float posX, posY;

	glLineWidth(2);	
	glColor3f(0.537, 0.835, 0.835);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < NUM_LADOS; ++i){
		posX = cenX + RAIO * cos(i * step);
		posY = cenY + RAIO * sin(i * step);
		glVertex2f(posX, posY);
	}
	glEnd();
	
	drawText();

	glFlush();
}

void keyPress(unsigned char c, int x, int y){
	if(c == '+')
		NUM_LADOS++;

	if(c == '-')
		NUM_LADOS = NUM_LADOS == 3 ?  NUM_LADOS : NUM_LADOS -1;

	drawScene();
}



int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("[EX1] Saulo Antunes Silva");

	glViewport(0, 0, 500, 500);
	glOrtho(0.0f, 100.0f, 0.0f, 100.0f, -1.0f, 1.0f);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keyPress);

	glutMainLoop();
	return 0;
}