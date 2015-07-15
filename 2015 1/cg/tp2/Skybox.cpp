#include "Skybox.h"
#include "config.h"

#define SB_LIM 1000.0f

Skybox::Skybox(){
	m_skyColor = {1.0, 1.0, 1.0};
	m_sideColor = {0.0, 0.0, 1.0};
	m_floorColor = {0.0, 1.0, 0.0};
}

void Skybox::draw(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		
   //sky
	glBegin(GL_QUADS);
		glColor3fv(&m_skyColor[0]);
		glVertex3f(-SB_LIM, SB_LIM,  SB_LIM); //p5
		glVertex3f(-SB_LIM, SB_LIM, -SB_LIM); //p6
		glVertex3f( SB_LIM, SB_LIM, -SB_LIM); //p7
		glVertex3f( SB_LIM, SB_LIM,  SB_LIM); //p8
	glEnd();
	
   //floor
	glBegin(GL_QUADS);
		glColor3fv(&m_floorColor[0]);
		glVertex3f(-SB_LIM, 0.0f,  SB_LIM); //p1
		glVertex3f(-SB_LIM, 0.0f, -SB_LIM); //p2
		glVertex3f( SB_LIM, 0.0f, -SB_LIM); //p3
		glVertex3f( SB_LIM, 0.0f,  SB_LIM); //p4
	glEnd();
	
   // +z
   glBegin(GL_QUADS);
		glColor3fv(&m_sideColor[0]);
		glVertex3f(-SB_LIM, 0.0f,  SB_LIM); //p1
		glVertex3f( SB_LIM, 0.0f,  SB_LIM); //p4
		glColor3fv(&m_skyColor[0]);
		glVertex3f( SB_LIM, SB_LIM,  SB_LIM); //p8
		glVertex3f(-SB_LIM, SB_LIM,  SB_LIM); //p5
   glEnd();

   // -z
   glBegin(GL_QUADS);
		glColor3fv(&m_sideColor[0]);
		glVertex3f(-SB_LIM, 0.0f, -SB_LIM); //p2
		glVertex3f( SB_LIM, 0.0f, -SB_LIM); //p3
		glColor3fv(&m_skyColor[0]);
		glVertex3f( SB_LIM, SB_LIM, -SB_LIM); //p7
		glVertex3f(-SB_LIM, SB_LIM, -SB_LIM); //p6
   glEnd();

   // -x
   glBegin(GL_QUADS);
		glColor3fv(&m_sideColor[0]);
		glVertex3f(-SB_LIM, 0.0f,  SB_LIM); //p1
		glVertex3f(-SB_LIM, 0.0f, -SB_LIM); //p2
		glColor3fv(&m_skyColor[0]);
		glVertex3f(-SB_LIM, SB_LIM, -SB_LIM); //p6
		glVertex3f(-SB_LIM, SB_LIM,  SB_LIM); //p5
   glEnd();

   // +x
   glBegin(GL_QUADS);
		glColor3fv(&m_sideColor[0]);
		glVertex3f( SB_LIM, 0.0f, -SB_LIM); //p3
		glVertex3f( SB_LIM, 0.0f,  SB_LIM); //p4
		glColor3fv(&m_skyColor[0]);
		glVertex3f( SB_LIM, SB_LIM,  SB_LIM); //p8
		glVertex3f( SB_LIM, SB_LIM, -SB_LIM); //p7
   glEnd();

   glPopMatrix();
}

Skybox::~Skybox(){}