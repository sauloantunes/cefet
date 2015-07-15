#include "Boids.h"
#include "config.h"

Boids::Boids() : m_size(0.5), m_position(1), m_velocity(0) {
   m_headColor  = {1, 0, 0};
   m_bodyColor  = {1, 1, 0};
   m_wingsColor = {1, 1, 0.4};
   m_tailColor  = {1, 1, 0};
   m_wingPosition = 1;
   m_wingVelocity = 0.1;
}

Boids::Boids(float size) : Boids(){
   setSize(size);
}

void Boids::setPosition(float x, float y, float z){
   m_position.x = x;
   m_position.y = y;
   m_position.z = z;
}

void Boids::setSize(float s){
   m_size.x = s;
   m_size.y = s;
   m_size.z = s;
}

void Boids::setSize(float x, float y, float z){
   m_size.x = x;
   m_size.y = y;
   m_size.z = z;
}

void Boids::moveWing(){
   m_wingPosition += m_wingVelocity;

   if(abs(m_wingPosition) > 2)
      m_wingVelocity *= -1;
}

void Boids::draw(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glPushMatrix();

   glScalef(m_size.x, m_size.y, m_size.z);
   glTranslatef(m_position.x, m_position.y, m_position.z);

   float sign = 1;
   sign = m_velocity.z > 0 ? -1 : 1;
   
   glRotatef(m_velocity.angle('x') * sign, 0, 1, 0);
   glRotatef(90 - m_velocity.angle('y'), 0, 0, 1);
   //glRotatef(m_velocity.angle('z'), 0, 0, 0);

   moveWing();

   // head
   glBegin(GL_TRIANGLE_FAN);
      glColor3fv(&m_headColor[0]);
      glVertex3f( 5.0f, 0.0f, 0.0f); //p1
      glVertex3f( 0.0f, 1.0f, 1.0f); //p2
      glVertex3f( 0.0f, 1.0f,-1.0f); //p3
      glVertex3f( 0.0f,-1.0f,-1.0f); //p4
      glVertex3f( 0.0f,-1.0f, 1.0f); //p5
      glVertex3f( 0.0f, 1.0f, 1.0f); //p2
   glEnd();

   // body
   glBegin(GL_TRIANGLE_FAN);
      glColor3fv(&m_bodyColor[0]);
      glVertex3f(-10.0f, 0.0f, 0.0f); //p6
      glVertex3f(  0.0f, 1.0f, 1.0f); //p2
      glVertex3f(  0.0f, 1.0f,-1.0f); //p3
      glVertex3f(  0.0f,-1.0f,-1.0f); //p4
      glVertex3f(  0.0f,-1.0f, 1.0f); //p5
      glVertex3f(  0.0f, 1.0f, 1.0f); //p2
   glEnd();
   
   // left wing
   glBegin(GL_TRIANGLE_FAN);
      glColor3fv(&m_wingsColor[0]);
      glVertex3f(-5.0f, m_wingPosition, 5.0f); //p11
      glVertex3f(  0.0f, 1.0f, 1.0f); //p2
      glVertex3f(  0.0f,-1.0f, 1.0f); //p5
      glVertex3f(-10.0f, 0.0f, 0.0f); //p6
      glVertex3f(  0.0f, 1.0f, 1.0f); //p2
   glEnd();

   // right wing
   glBegin(GL_TRIANGLE_FAN);
      glColor3fv(&m_wingsColor[0]);
      glVertex3f( -5.0f, m_wingPosition,-5.0f); //p12
      glVertex3f(  0.0f, 1.0f,-1.0f); //p3
      glVertex3f(  0.0f,-1.0f,-1.0f); //p4
      glVertex3f(-10.0f, 0.0f, 0.0f); //p6
      glVertex3f(  0.0f, 1.0f,-1.0f); //p3
   glEnd();

   // tail
   glBegin(GL_TRIANGLE_FAN);
      glColor3fv(&m_tailColor[0]);
      glVertex3f(-10.0f, 0.0f, 0.0f); //p6
      glVertex3f(-12.0f, 0.2f, 1.0f); //p7
      glVertex3f(-12.0f, 0.2f,-1.0f); //p8
      glVertex3f(-12.0f,-0.2f,-1.0f); //p9
      glVertex3f(-12.0f,-0.2f, 1.0f); //p10
      glVertex3f(-12.0f, 0.2f, 1.0f); //p7
   glEnd();

   glPopMatrix();
}