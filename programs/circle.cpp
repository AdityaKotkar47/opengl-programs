#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define pi 3.142857


void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-780, 780, -420, 420);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    float x, y, i;
    glBegin(GL_POINTS);
        for (i=0; i < (2*pi); i += 0.001){
            x = 180 * cos(i);
            y = 180 * sin(i);

            glVertex2f(x, y);
        }
    glEnd();

    glFlush();
}



int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(768, 418);
    glutCreateWindow("circle hai yeah");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
