#include <GL/glut.h>
#include <iostream>

void init() {
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Input coordinates
    int x1, x2, y1, y2;
    std::cout << "Enter [x1, y1, x2, y2]: ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1;
    int dy = y2 - y1;

    // Determine the absolute values for slope calculations
    int abs_dx = abs(dx);
    int abs_dy = abs(dy);

    // Initialize decision parameter and starting point
    int decision_param;
    int x = x1, y = y1;

    // Case I: Upward Slopes
    if (dx >= 0 && dy >= 0) {
        if (abs_dy <= abs_dx) {
            decision_param = (2 * dy) - dx;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dx; _i++) {
                if (decision_param >= 0) {
                    y += 1;
                    decision_param += (2 * (dy - dx));
                }
                x += 1;
                decision_param += (2 * dy);
                putPixel(x, y);
            }
        } else { // |m| > 1
            decision_param = (2 * dx) - dy;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dy; _i++) {
                if (decision_param >= 0) {
                    x += 1;
                    decision_param += (2 * (dx - dy));
                }
                y += 1;
                decision_param += (2 * dx);
                putPixel(x, y);
            }
        }
    }

    // Case II: Downward Slopes
    else if (dx >= 0 && dy < 0) {
        if (abs_dy <= abs_dx) {
            decision_param = (2 * dy) + dx;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dx; _i++) {
                if (decision_param >= 0) {
                    y -= 1;
                    decision_param += (2 * (dy + dx));
                }
                x += 1;
                decision_param += (2 * dy);
                putPixel(x, y);
            }
        } else {
            decision_param = (2 * abs_dx) + dy;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dy; _i++) {
                if (decision_param >= 0) {
                    x += 1;
                    decision_param += (2 * (abs_dx + dy));
                }
                y -= 1;
                decision_param += (2 * abs_dx);
                putPixel(x, y);
            }
        }
    }

    // Case III: Upward Slopes with negative slope
    else if (dx < 0 && dy >= 0) {
        if (abs_dy <= abs_dx) {
            decision_param = (2 * dy) - abs_dx;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dx; _i++) {
                if (decision_param >= 0) {
                    y += 1;
                    decision_param += (2 * (dy - abs_dx));
                }
                x -= 1;
                decision_param += (2 * dy);
                putPixel(x, y);
            }
        } else { // |m| > 1
            decision_param = (2 * abs_dx) - dy;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dy; _i++) {
                if (decision_param >= 0) {
                    x -= 1;
                    decision_param += (2 * (abs_dx - dy));
                }
                y += 1;
                decision_param += (2 * abs_dx);
                putPixel(x, y);
            }
        }
    }

    // Case IV: Downward Slopes with negative slope
    else {
        if (abs_dy <= abs_dx) {
            decision_param = (2 * dy) + abs_dx;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dx; _i++) {
                if (decision_param >= 0) {
                    y -= 1;
                    decision_param += (2 * (dy + abs_dx));
                }
                x -= 1;
                decision_param += (2 * dy);
                putPixel(x, y);
            }
        } else { // |m| > 1
            decision_param = (2 * abs_dx) + dy;

            putPixel(x, y);
            for (int _i = 0; _i < abs_dy; _i++) {
                if (decision_param >= 0) {
                    x -= 1;
                    decision_param += (2 * (abs_dx + dy));
                }
                y -= 1;
                decision_param += (2 * abs_dx);
                putPixel(x, y);
            }
        }
    }

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
