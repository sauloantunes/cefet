#include "Brick.h"

Brick::Brick(){
	m_size.x = 10;
	m_size.y = 10;
}

void Brick::draw(){	
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL); //GL_LINE

	glColor3f(m_color.r - 0.3, m_color.g - 0.3, m_color.b - 0.3);
	float offset = 0.5;
    glBegin(GL_POLYGON);
		glVertex3f(m_pos.x - offset, 			m_pos.y - offset, 0);
		glVertex3f(m_pos.x + m_size.x - offset, m_pos.y - offset, 0);
		glVertex3f(m_pos.x + m_size.x, m_pos.y, 0);
		glVertex3f(m_pos.x + m_size.x - offset, m_pos.y + m_size.y - offset, 0);
		glVertex3f(m_pos.x, 			m_pos.y + m_size.y, 0);
		glVertex3f(m_pos.x - offset, 			m_pos.y + m_size.y - offset, 0);
	glEnd();


	glColor3f(m_color.r, m_color.g, m_color.b);
    glBegin(GL_POLYGON);
		glVertex3f(m_pos.x, m_pos.y, 0);
		glVertex3f(m_pos.x + m_size.x, m_pos.y, 0);
		glVertex3f(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);
		glVertex3f(m_pos.x , m_pos.y + m_size.y, 0);
	glEnd();
}

struct position Brick::getPoint(int point){	
	struct position p(m_pos.x, m_pos.y);

	switch(point){
		case 0: 												return p; break;
		case 1: p.set(m_pos.x + m_size.x, m_pos.y);  			return p; break;
		case 2: p.set(m_pos.x + m_size.x, m_pos.y + m_size.y);  return p; break;
		case 3: p.set(m_pos.x           , m_pos.y + m_size.y);  return p; break;
		default: 												return p;
	}
}