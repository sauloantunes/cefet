#include "Bar.h"

Bar::Bar(){
	m_velocity = 0;

	m_size.x = 40;
	m_size.y = 6;

	m_pos.x = 50 -  m_size.x / 2;
	m_pos.y = 10;

	m_color.set(0.8, 0.8, 0.8, 0);
}

void Bar::draw(){	
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL); //GL_LINE

	glColor3f(m_color.r - 0.3, m_color.g - 0.3, m_color.b - 0.3);
	float offset = fabs(0.5 * m_velocity);

	if(m_velocity > 0.0){	
	    glBegin(GL_POLYGON);
			glVertex3f(m_pos.x - offset           , m_pos.y - offset	       , 0);
			glVertex3f(m_pos.x + m_size.x - offset, m_pos.y - offset 	 	   , 0);
			glVertex3f(m_pos.x + m_size.x         , m_pos.y                    , 0);
			glVertex3f(m_pos.x + m_size.x         , m_pos.y + m_size.y         , 0);
			glVertex3f(m_pos.x                    , m_pos.y + m_size.y         , 0);
			glVertex3f(m_pos.x - offset           , m_pos.y + m_size.y - offset, 0);
		glEnd();
	}
	else{
	    glBegin(GL_POLYGON);
			glVertex3f(m_pos.x                    , m_pos.y                    , 0);
			glVertex3f(m_pos.x +            offset, m_pos.y - offset 	 	   , 0);
			glVertex3f(m_pos.x + m_size.x + offset, m_pos.y - offset           , 0);
			glVertex3f(m_pos.x + m_size.x + offset, m_pos.y - offset + m_size.y, 0);
			glVertex3f(m_pos.x + m_size.x         , m_pos.y + m_size.y         , 0);
			glVertex3f(m_pos.x                    , m_pos.y + m_size.y     	   , 0);
		glEnd();	
	}
	

	glColor3f(m_color.r, m_color.g, m_color.b);
    glBegin(GL_POLYGON);
		glVertex3f(m_pos.x, m_pos.y, 0);
		glVertex3f(m_pos.x + m_size.x, m_pos.y, 0);
		glVertex3f(m_pos.x + m_size.x, m_pos.y + m_size.y, 0);
		glVertex3f(m_pos.x , m_pos.y + m_size.y, 0);
	glEnd();


}

void Bar::update(){
	m_pos.x = m_pos.x + m_velocity;

	if(m_pos.x < 0)
		m_pos.x = 0;

	if(m_pos.x + m_size.x > 100)
		m_pos.x = 100 - m_size.x;
}

struct position Bar::getPoint(int point){
	struct position p(m_pos.x, m_pos.y);

	switch(point){
		case 0: 												return p; break;
		case 1: p.set(m_pos.x + m_size.x, m_pos.y);  			return p; break;
		case 2: p.set(m_pos.x + m_size.x, m_pos.y + m_size.y);  return p; break;
		case 3: p.set(m_pos.x           , m_pos.y + m_size.y);  return p; break;
		default: 												return p;
	}
}