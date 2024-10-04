#include <GL/glut.h>
#include <iostream>

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {

    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p;

    int x = x1, y = y1;
    plotPoint(x, y);
    int yInc = (y2 > y1) ? 1 : -1;

    if (dy < dx) {
        p = 2*dy - dx;
        
        for (int i = 0; i < dx; i++) {
            if (p < 0) {
                p += 2*dy;
            } else {
                y += yInc;
                p += 2*(dy - dx);
            }
            x += 1;
            plotPoint(x, y);
        }
    }
    else {
        p = 2*dx - dy;

        for (int i = 0; i < dy; i++) {
            if (p < 0) {
                p += 2*dx;
            } else {
                x += 1;
                p += 2*(dx - dy);
            }
            y += yInc;
            plotPoint(x, y);
        }
    }

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Input coordinates
    int x1, x2, y1, y2;
    std::cout << "Enter [x1, y1, x2, y2]: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    drawLine(x1, y1, x2, y2);

    glFlush();
}

int main(int argc, char** argv) {
    // always input left point, then right point
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("bresenham wali line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
