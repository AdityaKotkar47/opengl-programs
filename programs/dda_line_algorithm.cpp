#include <GL/glut.h>
#include <iostream>

using namespace std;

void init() {

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void ddaLine(float x1, float y1, float x2, float y2) {

    float dx = x2-x1, dy = y2-y1;
    float steps = max(abs(dx), abs(dy));
    float xinc = dx/steps, yinc = dy/steps;
    float x = x1, y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {

        glVertex2f(x, y);

        x += xinc;
        y += yinc;
    }
    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    ddaLine(100, 100, 200, 200); // replace values here to use as a function

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("dda line");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
