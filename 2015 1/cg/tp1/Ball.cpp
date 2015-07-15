#include "Ball.h"

using namespace std;

Ball::Ball(){
	m_radius = 2;

	m_pos.x = 50;
	m_pos.y = 16 + 3;
	
	m_velocity.x = 1;
	m_velocity.y = 1;

	m_speedup = 0;

	m_color.set(0.8, 0.8, 0.8, 0);

	m_segments = 40;
}

void Ball::draw(){	
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL); //GL_LINE

	float step = (6.2831) / m_segments;

	glColor3f(m_color.r - 0.3, m_color.g - 0.3, m_color.b - 0.3);
	float offset = 0.2;
	glBegin(GL_POLYGON);
	for (int i = 0; i < m_segments; ++i){
		glVertex3f(m_pos.x - offset + m_radius * cos(i * step), 
				   m_pos.y - offset + m_radius * sin(i * step), 0);
	}
	glEnd();	


	glColor3f(m_color.r, m_color.g, m_color.b);
    glBegin(GL_POLYGON);
	for (int i = 0; i < m_segments; ++i){
		glVertex3f(m_pos.x + m_radius * cos(i * step), 
				   m_pos.y + m_radius * sin(i * step), 0);
	}
	glEnd();	
}

void Ball::update(){
	m_pos.x += m_velocity.x;
	m_pos.y += m_velocity.y;
	
	m_pos.y += m_velocity.y > 0 ? m_speedup*m_speedup : - m_speedup*m_speedup;

	m_speedup += m_speedup < 0 ? 0.02 : - 0.02;	
}