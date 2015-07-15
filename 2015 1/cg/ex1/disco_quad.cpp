#include <GL/glut.h>
#include <cstdio>

bool fill = 0;

void quadrado(GLenum mode)
{
    glPolygonMode(GL_FRONT_AND_BACK, mode);    
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(100.0, 100.0);
        glVertex2f(200.0, 200.0);
        glVertex2f(500.0, 100.0);
        glVertex2f(400.0, 200.0);
        glVertex2f(500.0, 500.0);
        glVertex2f(400.0, 400.0);
        glVertex2f(100.0, 500.0);
        glVertex2f(200.0, 400.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(200.0, 200.0);
    glEnd();
    glFlush();
}

void drawScene(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    if(fill){    
        glColor3f(0.537, 0.835, 0.835);
        quadrado(GL_FILL);
    }

    glColor3f(0.0, 0.0, 0.0);
    quadrado(GL_LINE);

}

void key(unsigned char c, int x, int y){
    if (c == 'c')
        fill = !fill;
    
    drawScene();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("[EX1] Saulo Antunes Silva");
    
    glOrtho(0.0, 600.0, 0.0, 600.0, -1.0, 1.0);

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(key);

    glutMainLoop();
    return 0;
}