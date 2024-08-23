#include <GL/glut.h>

void init(){
    gluOrtho2D(-300, 300, -300, 300);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    // triangle up
    glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.7, 0.2);
        glVertex2i(-60, -50);
        glVertex2i(60, -50);
        glVertex2i(0, 100);
    glEnd();
    // triangle down
    glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.6, 0.8);
        glVertex2i(0, -100);
        glVertex2i(60, 50);
        glVertex2i(-60, 50);
    glEnd();
    // hexagon
    glBegin(GL_POLYGON);
        glColor3f(0.7, 0.5, 0.7);
        glVertex2i(20, 50);
        glVertex2i(-20, 50);
        glVertex2i(-40, 0);
        glVertex2i(-20, -50);
        glVertex2i(20, -50);
        glVertex2i(40, 0);
    glEnd();
    // lines
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(20, 50);
        glVertex2i(-20, 50);
        glVertex2i(-20, 50);
        glVertex2i(-40, 0);
        glVertex2i(-40, 0);
        glVertex2i(-20, -50);
        glVertex2i(-20, -50);
        glVertex2i(20, -50);
        glVertex2i(20, -50);
        glVertex2i(40, 0);
        glVertex2i(40, 0);
        glVertex2i(20, 50);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("star hai");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
