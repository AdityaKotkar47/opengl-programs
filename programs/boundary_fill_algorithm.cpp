#include <GL/glut.h>
#include <cmath>

using namespace std;

void init() {

    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

bool isSameColor(float color1[3], float color2[3]) {
    const float tolerance = 0.01;
    return (fabs(color1[0]-color2[0]) < tolerance
            && fabs(color1[1] - color2[1]) < tolerance
            && fabs(color1[2] - color2[2]) < tolerance);
}

void boundaryFill(int x, int y, float fillColor[3], float boundaryColor[3]) {

    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

    if (!isSameColor(currentColor, fillColor) && !isSameColor(currentColor, boundaryColor)) {

        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
        glFlush();

        boundaryFill(x+1, y, fillColor, boundaryColor);
        boundaryFill(x, y+1, fillColor, boundaryColor);
        boundaryFill(x-1, y, fillColor, boundaryColor);
        boundaryFill(x, y-1, fillColor, boundaryColor);
    }
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    float fillColor[3] = {0, 1, 1};
    float boundaryColor[3] = {1, 0, 0};

    glColor3fv(boundaryColor);
    glBegin(GL_LINES);
        glVertex2i(100, 100);
        glVertex2i(200, 100);

        glVertex2i(200, 100);
        glVertex2i(200, 200);

        glVertex2i(200, 200);
        glVertex2i(100, 200);

        glVertex2i(100, 200);
        glVertex2i(100, 100);
    glEnd();

    glColor3fv(fillColor);
    boundaryFill(101, 101, fillColor, boundaryColor);

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("boundary fill");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
