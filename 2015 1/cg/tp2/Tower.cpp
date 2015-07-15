#include "Tower.h"
#include "config.h"

Tower::Tower() : m_color(1), m_position(0) {
	m_color = {1, 0.5, 0.3};
	m_height = 80;
	m_radius = 20;
}

void Tower::setColor(float r, float g, float b){
	m_color = {r, g, b};
}

void Tower::setPosition(float x, float z){
	m_position.x = x;
	m_position.z = z;
}

void Tower::draw(){
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glPushMatrix();

   glColor3fv(&m_color[0]);

   glRotatef(-90,1,0,0);
   glTranslatef(m_position.x, m_position.z, 0);

   GLUquadricObj *quadratic;
   quadratic = gluNewQuadric();
   gluCylinder(quadratic, m_radius, m_radius, m_height, 32, 32);

   glPopMatrix();
}