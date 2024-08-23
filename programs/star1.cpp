#include <GL/glut.h>

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-300, 300, -300, 300);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(-20, 50);
        glVertex2i(-60, 50);
        glVertex2i(-40, 0);
        glVertex2i(-60, -50);
        glVertex2i(-20, -50);
        glVertex2i(0, -100);
        glVertex2i(20, -50);
        glVertex2i(60, -50);
        glVertex2i(40, 0);
        glVertex2i(60, 50);
        glVertex2i(20, 50);
        glVertex2i(0, 100);

    glEnd();

    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("star hai akela");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
