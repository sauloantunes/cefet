#include "Object.h"
#include "Brick.h"
#include "Ball.h"
#include "Bar.h"
#include "HUD.h"

using namespace std;

// GAME VARIABLES

bool PLAY = 1;
struct color BG_COLOR(0.055,0.639,0.820, 0);
vector <Brick> bricks;
Bar  bar;
Ball ball;
HUD  hud;



// DRAW FUNCTIONS

void drawBricks(){
	for (int i = 0; i < bricks.size(); ++i)
		bricks[i].draw();
}

void drawBar(){	
	bar.draw();
}

void drawBall(){
	ball.draw();
}

void drawHUD(){
	hud.draw();
}

void draw(){
	glClearColor(BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
	glClear(GL_COLOR_BUFFER_BIT);

	drawBricks();
	drawBar();
	drawBall();
	drawHUD();	
	glFlush();
}


// SETUP FUNCTIONS

void setupBar(){
	bar.m_pos.x = 50 - bar.m_size.x/2;
}

void setupBall(){
	ball.m_pos.y = bar.m_pos.y + bar.m_size.y + ball.m_radius;
}

void setupBricks(){	
	ifstream infile(hud.m_bricksFile);
	bricks.clear();
	Brick b;
	while(infile >> b.m_pos.x  >> b.m_pos.y 
				 >> b.m_size.x >> b.m_size.y 
				 >> b.m_color.r >> b.m_color.g >> b.m_color.b)
		bricks.push_back(b);
	
	infile.close();
}

void setupHUD(){}

void setupGame(){
	setupBar();
	setupBall(); // ball should be set after bar, because it is set to be over the bar.
	setupBricks();
}


// COLLISION FUNCTIONS

bool ballInLine(position a, position b){
	   
	float x = ball.m_pos.x;
	float y = ball.m_pos.y;
	float r = ball.m_radius;

	if(a.y == b.y)
		return (x+r > min(a.x, b.x)) && 
	   		   (x-r < max(a.x, b.x)) &&
	   		   (abs(y-a.y) <= r);

	if(a.x == b.x)
		return (y+r > min(a.y, b.y)) && 
	   		   (y-r < max(a.y, b.y)) &&
	   		   (abs(x-a.x) < r);
}

bool brickCollision(Brick brick){
	for (int i = 0; i < 4; ++i){
		if(ballInLine(brick.getPoint(i), brick.getPoint(i+1))){
			if(i % 2)
				ball.m_velocity.x *= -1;
			else
				ball.m_velocity.y *= -1;
			
			return true;
		}		
	}
}

void checkBriksCollision(){
	for (int i = 0; i < bricks.size(); ++i){
		if(brickCollision(bricks[i])){
			bricks.erase(bricks.begin() + i);
			hud.m_score++;
			i--;
		}
	}
}

void checkBarCollision(){
	for (int i = 0; i < 4; ++i){
		if(ballInLine(bar.getPoint(i), bar.getPoint(i+1))){
			if(i % 2)
				ball.m_velocity.x *= -1;
			else
				ball.m_velocity.y *= -1;

				ball.m_speedup = abs(bar.m_velocity);
		}
	}
}

void checkWindowCollision(){
	//sides
	if(ball.m_pos.x - ball.m_radius < 0 || ball.m_pos.x + ball.m_radius> 100)
		ball.m_velocity.x *= -1;

	//top
	if(ball.m_pos.y + ball.m_radius> 100)
		ball.m_velocity.y *= -1;
	
	//bottom
	if(ball.m_pos.y - ball.m_radius < 0){
		ball.m_velocity.y *= -1;
		hud.m_lives--;
		if(hud.m_lives)
			setupBall();
	}
}


// LEVEL FUNCTIONS

void level1(){
	hud.m_bricksFile = "bricks1.txt";
	setupGame();
}

void level2(){
	hud.m_bricksFile = "bricks2.txt";
	ball.m_radius--;
	bar.m_size.y -= 4;
	bar.m_size.x--;
	BG_COLOR.set(4/255.0,153/255.0,199/255.0, 0);
	setupGame();
}


// GAME FUNCTIONS

void restart(){	
	bar   = *(new Bar());
	ball  = *(new Ball());
	hud   = *(new HUD());
	setupBricks();
	PLAY = 1;
}

void levelUp(){
	switch(hud.m_level){
		case 1: level1(); break;
		case 2: level2(); break;
		default: 		
			PLAY = 0;
			hud.m_hasMessage = 1;
			hud.m_message = (char*)"YOU WIN!";
	}
}

void checkGame(){
	if(hud.m_lives < 1){
		PLAY = 0;
		hud.m_hasMessage = 1;
		hud.m_message = (char*)"YOU LOSE";
	}

	if(bricks.size() < 1){
		hud.m_level++;
		levelUp();
	}
}


// ANIMATION FUNCTIONS

void animation(int x){
	if(PLAY){
		bar.update();
		ball.update();
		
		checkBarCollision();
		checkBriksCollision();
		checkWindowCollision();

		checkGame();
	}

	glutPostRedisplay();
	glutTimerFunc(25, animation, 0);
}


// EVENT FUNCTIONS

void keyPress(unsigned char c, int x, int y){
	if(c == 'r' || c == 'R')
		restart();
	if(c == 27)
		exit(1);
}

void mouseMotion(int x, int y){
	// Get the x-position of the pointer on a scale from 0 to 100
	float pos = (100.0 * x) /  (float)glutGet(GLUT_WINDOW_WIDTH);

	bar.m_velocity = 0;

	if(pos > 60)
		bar.m_velocity = pow(pos/80, 3);

	if(pos < 40)
		bar.m_velocity = pow((pos-100)/80, 3);
}


// MAIN FUNCTION

int main(int argc, char  **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(200,200);
	glutCreateWindow("BREAKOUT");
	
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyPress);
	glutPassiveMotionFunc(mouseMotion);
	glutTimerFunc(25, animation, 0);
	glOrtho(0, 100.0, 0, 100.0, -1, 1);

	level1();

	glutMainLoop();
}