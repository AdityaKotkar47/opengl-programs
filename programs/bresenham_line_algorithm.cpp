#include <GL/glut.h>
#include <iostream>

int x1, x2, y1, y2;

void init(){
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_point(int x, int y){
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // input stuff
    std::cout << "enter [x1, y1, x2, y2]: ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    int x = x1, y = y1;

    // for case 1 with |m| > 1 and |m| < 1

    // initial setup
    draw_point(x, y);
    int dx = x2 - x1, dy = y2 - y1;
    int decision_param; // p0

    if (dy < dx){

        decision_param = (2 * dy) - dx;

        for (int _i = 0; _i < dx; _i++){

            if (decision_param < 0){
                x += 1;
                decision_param += 2 * dy;
            } else {
                x += 1;
                y += 1;
                decision_param += 2 * (dy - dx);
            }
            draw_point(x, y);
        }
    } else {

        decision_param = (2 * dx) - dy;

        for (int _i = 0; _i < dy; _i++){

            if (decision_param < 0){
                y += 1;
                decision_param += 2 * dx;
            } else {
                x += 1;
                y += 1;
                decision_param += 2 * (dx - dy);
            }
            draw_point(x, y);
        }
    }

    glFlush();
}

int main(int argc, char** argv){
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
