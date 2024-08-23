#include <GL/glut.h>

void init(){
    glClearColor(0, 0, 0, 1.0);
    gluOrtho2D(-250, 250, -250, 250);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON); // main rectangle frame
        glColor3f(0.5, 0.7, 1.0);
        glVertex2i(0, 0);
        glVertex2i(100, 0);
        glVertex2i(100, 50);
        glVertex2i(0, 50);
    glEnd();
    glBegin(GL_POLYGON); // top parallelogram
        glColor3f(1.0, 0.7, 0.2);
        glVertex2i(0, 50);
        glVertex2i(100, 50);
        glVertex2i(75, 85);
        glVertex2i(-25, 85);
    glEnd();
    glBegin(GL_POLYGON); // top triangle
        glColor3f(1.0, 1.0, 0.2);
        glVertex2i(-50, 50);
        glVertex2i(-25, 85);
        glVertex2i(0, 50);
    glEnd();
    glBegin(GL_POLYGON); // front square
        glColor3f(1.0, 0.6, 1.0);
        glVertex2i(-50, 50);
        glVertex2i(-50, 0);
        glVertex2i(0, 0);
        glVertex2i(0, 50);
    glEnd();
    glBegin(GL_POLYGON); // door
        glColor3f(0.1, 0.7, 0.6);
        glVertex2i(-31, 0);
        glVertex2i(-19, 0);
        glVertex2i(-19, 21);
        glVertex2i(-31, 21);
    glEnd();
    glBegin(GL_POLYGON); // window
        glColor3f(0.4, 1.0, 0.9);
        glVertex2i(30, 18);
        glVertex2i(70, 18);
        glVertex2i(70, 36);
        glVertex2i(30, 36);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(0.1, 0.1, 0.1);
        // window lines
        glVertex2i(30, 18);
        glVertex2i(70, 18);
        glVertex2i(70, 36);
        glVertex2i(30, 36);
        glVertex2i(30, 36);
        glVertex2i(30, 18);
        glVertex2i(70, 36);
        glVertex2i(70, 18);
        glVertex2i(50, 36);
        glVertex2i(50, 18);
        glVertex2i(30, 27);
        glVertex2i(70, 27);
        // door lines
        glVertex2i(-19, 0);
        glVertex2i(-19, 21);
        glVertex2i(-19, 21);
        glVertex2i(-31, 21);
        glVertex2i(-31, 21);
        glVertex2i(-31, 0);
        // other lines
        glVertex2i(-50, 50);
        glVertex2i(100, 50);
        glVertex2i(0, 50);
        glVertex2i(0, 0);
        glVertex2i(-25, 85);
        glVertex2i(0, 50);

    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("house");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
