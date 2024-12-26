
#include <GL/glut.h>

void init() {

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void midpointCircle(int xc, int yc, int r) {

    int x = 0, y = r, d = 1 - r;

    glBegin(GL_POINTS);
    while (x <= y) {

        glVertex2i(xc + y, yc + x); // I
        glVertex2i(xc + x, yc + y); // II
        glVertex2i(xc + x, yc - y); // III
        glVertex2i(xc + y, yc - x); // IV
        glVertex2i(xc - x, yc - y); // V
        glVertex2i(xc - y, yc - x); // VI
        glVertex2i(xc - x, yc + y); // VII
        glVertex2i(xc - y, yc + x); // VIII

        if (d < 0) {
            d += 2*x + 3;
        }
        else {
            d += 2*(x-y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    midpointCircle(250, 250, 100); // replace values here to use as a function

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("midpoint circle");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
