#include "HUD.h"

HUD::HUD(){
	m_score = 0;
	m_lives = 3;
	m_level = 1;
	m_bricksFile = "bricks1.txt";

	m_hasMessage = 0;
	m_message = (char*)malloc(20);	

	m_color.set(0.9, 0.9, 0.9, 0);
}

void HUD::drawString(char* str){
	int i=0;

	while(str[i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i++]);
}

void HUD::draw(){
	glColor3f(m_color.r, m_color.g, m_color.b);

	char *str = (char*)malloc(20);

	sprintf(str, "score %d", m_score);
	glRasterPos3f(5, 95, 0);
	drawString(str);
	
	sprintf(str, "level %d", m_level);
	glRasterPos3f(85, 95, 0);
	drawString(str);
	
	glRasterPos3f(5, 92, 0);
	for (int i = 0; i < m_lives; ++i)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 1);

	if(m_hasMessage)
		showMessage();
}

void HUD::showMessage(){
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL); //GL_LINE
	glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    	glVertex3f(34,44, 0);
		glVertex3f(64,44, 0);
		glVertex3f(64,54, 0);
		glVertex3f(34,54, 0);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);   
		glVertex3f(35, 45, 0);
		glVertex3f(65, 45, 0);
		glVertex3f(65, 55, 0);
		glVertex3f(35, 55, 0);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glRasterPos3f(43, 49, 0);
	drawString(m_message);
	
	glColor3f(m_color.r, m_color.g, m_color.b);
	glRasterPos3f(15, 30, 0);
	drawString((char*)"<Press (R) to restart or (ESC) to exit>");
}