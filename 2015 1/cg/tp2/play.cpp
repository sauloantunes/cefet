#include "config.h"

using namespace std;

float X,Y,Z = 0;
float STEP = 1;
float ANGLE = 0;
int CAMERA = 1;

Skybox skybox;
Tower tower;
vector<Boids> boids;

// BOIDS ALGORITHM
//////////////////
Vec4 rule1(Boids b){
   Vec4 center;

   for (int i = 0; i < boids.size(); ++i)
      center = center + boids[i].m_position;      
   center = center - b.m_position;

   center = center / (boids.size() - 1);

   return (center - b.m_position) / 100;
}

Vec4 rule2(Boids b){
   Vec4 dist;

   for (int i = 0; i < boids.size(); ++i){
      if((boids[i].m_position - b.m_position).module() < 20)
         dist = dist - (boids[i].m_position - b.m_position);
   }

   return dist;
}

Vec4 rule3(Boids b){
   Vec4 velocity;

   for (int i = 0; i < boids.size(); ++i)
      velocity = velocity + boids[i].m_velocity;   
   velocity = velocity - b.m_velocity;

   velocity = velocity / (boids.size() - 1);

   return (velocity - b.m_velocity) / 2;
}

void moveBoids(){
   for (int i = 1; i < boids.size(); ++i){
      Vec4 v;
      v = v + rule1(boids[i]);
      v = v + rule2(boids[i]);
      v = v + rule3(boids[i]);

      boids[i].m_velocity = boids[i].m_velocity + v;
      boids[i].m_position = boids[i].m_position + boids[i].m_velocity;
   }
}


void keyPress(unsigned char c, int x, int y){
   if(c == 's')
      STEP /= 2;
   if(c == 'S')
      STEP++;
   
   if(c == 'c' || c == 'C')
      CAMERA = (CAMERA + 1) % 3;
   
   if(c == '+'){
      Boids b;
      b.setPosition(rand() % 400, 0, rand() % 400);
      boids.push_back(b);
   }

   if(c == '-'){
      if(boids.size() > 1){
         boids.pop_back();
      }
   }



   if(c == 'x')
      X -= STEP;
   if(c == 'X')
      X += STEP;
   
   if(c == 'y')
      Y -= STEP;
   if(c == 'Y')
      Y += STEP;
   
   if(c == 'z')
      Z -= STEP;
   if(c == 'Z')
      Z += STEP;

   if(c == 'q')
      boids[0].m_velocity.y -= 0.1;
   if(c == 'Q')
      boids[0].m_velocity.y += 0.1;

   cout << "X: " << X << endl;
   cout << "Y: " << Y << endl;
   cout << "Z: " << Z << endl;
   cout << "S: " << STEP << endl;
   cout << "C: " << CAMERA << endl;
   cout << endl;
}

void selectCamera(){
   switch(CAMERA){
      case 0 : gluLookAt(X, Y, Z, 
                         boids[0].m_position.x, boids[0].m_position.y, boids[0].m_position.z,
                         0,1,0);
               break;

      case 1 : gluLookAt(0, boids[0].m_position.x, 0, 
                         boids[0].m_position.x, boids[0].m_position.y, boids[0].m_position.z,
                         0,1,0);
               break;

      case 2 : gluLookAt(boids[0].m_position.x, boids[0].m_position.y, boids[0].m_position.z, 
                         boids[0].m_position.x, boids[0].m_position.y, boids[0].m_position.z,
                         0,1,0);
               break;
   }
}

void drawObjects(){
   for (int i = 0; i < boids.size(); ++i)
      boids[i].draw();
   
   skybox.draw();
   tower.draw();
}

void goBoid(){
   ANGLE += 0.01;
   boids[0].m_velocity.x = sin(ANGLE) * 2;
   boids[0].m_velocity.z = cos(ANGLE) * 2;
   boids[0].m_position = boids[0].m_position + boids[0].m_velocity;
}

void display(){
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   goBoid();
   moveBoids();
   
   selectCamera();
   drawObjects();

   glutSwapBuffers();
}

void initObjects(){
   for (int i = 0; i < 5; ++i){
      Boids b;
      b.setPosition(0, rand() % 400, rand() % 400);
      boids.push_back(b);
   }

   boids[0].setPosition(100, 50, 100);

   tower.setPosition(400, 400);
   tower.setColor(0.3, 0.3, 0.3);
}

void animation(int x){
   glutPostRedisplay();
   glutTimerFunc(25, animation, 0);
}

void reshape(int width, int height){
   if (height == 0)
      height = 1;
   
   float aspect = (float)width / (float)height;
 
   glViewport(0, 0, width, height);
 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f, aspect, 1.0f, 2000.0f);
}


void initGLU(){
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyPress);
   glutTimerFunc(25, animation, 0);
}
 
void initGL(){
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   //glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   //glClearDepth(100.0);
   //glEnable(GL_LIGHTING);
   //glEnable(GL_LIGHT0);
   //GLfloat lightpos[] = {0, 100, 0, 0};
   //glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

   //glEnable(GL_COLOR_MATERIAL);
   //glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(200, 50);
   glutCreateWindow("BOIDS");

   initGL();
   initGLU();
   initObjects();

   glutMainLoop();
   return 0;
}