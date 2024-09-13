#include <GL/glut.h>
#include <iostream>

int Xc, Yc, R;

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-250, 250, -250, 250);
}

void draw_point(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void Circle(int Xc, int Yc, int X, int Y)
{
    draw_point(Xc + X, Yc + Y);     // octet 1
    draw_point(Xc + Y, Yc + X);     // octet 2
    draw_point(Xc + Y, Yc - X);     // octet 3
    draw_point(Xc + X, Yc - Y);     // octet 4
    draw_point(Xc - X, Yc - Y);     // octet 5
    draw_point(Xc - Y, Yc - X);     // octet 6
    draw_point(Xc - Y, Yc + X);     // octet 7
    draw_point(Xc - X, Yc + Y);     // octet 8
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    std::cout << "enter the center coordinates (Xc, Yc) and radius (R): ";
    std::cin >> Xc >> Yc >> R;

    int X = 0; // xk
    int Y = R; // yk
    int decision_param = 3 - 2 * R; // initial decision parameter

    Circle(Xc, Yc, X, Y);

    while (X < Y)
    {
        if (decision_param < 0)
        {
            decision_param += 4 * X + 6;
        }
        else
        {
            decision_param += 4 * (X - Y) + 10;
            Y = Y - 1; // yk+1
        }
        X = X + 1; // xk+1
        Circle(Xc, Yc, X, Y);
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("bresenham wala circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
