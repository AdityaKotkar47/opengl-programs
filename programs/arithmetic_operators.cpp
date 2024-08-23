
#include <GL/glut.h>

void init(){
    glClearColor(0, 0, 0, 1.0);
    gluOrtho2D(-300, 300, -300, 300);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // borders
    glBegin(GL_LINES);
        glColor3f(0, 1, 0);

        glVertex2i(-100, 300);
        glVertex2i(-100, -100);

        glVertex2i(100, 100);
        glVertex2i(100, -300);

        glVertex2i(-300, 100);
        glVertex2i(100, 100);

        glVertex2i(-100, -100);
        glVertex2i(300, -100);
    glEnd();

    // corners
    glPointSize(6);
    glBegin(GL_POINTS);
        glColor3f(1, 0, 0);
        glVertex2i(-100, 100);
        glVertex2i(100, -100);
    glEnd();

    // operators

    // plus
    glBegin(GL_POLYGON);
        glColor3f(0, 1, 1);
        glVertex2i(-210, 210);
        glVertex2i(-210, 250);
        glVertex2i(-190, 250);
        glVertex2i(-190, 210);
        glVertex2i(-150, 210);
        glVertex2i(-150, 190);
        glVertex2i(-190, 190);
        glVertex2i(-190, 150);
        glVertex2i(-210, 150);
        glVertex2i(-210, 190);
        glVertex2i(-250, 190);
        glVertex2i(-250, 210);

    glEnd();

    // minus
    glBegin(GL_POLYGON);

        glVertex2i(-50, -10);
        glVertex2i(50, -10);
        glVertex2i(50, 10);
        glVertex2i(-50, 10);
    glEnd();

    // x
    glBegin(GL_POLYGON);
        glVertex2i(186, -200);
        glVertex2i(158, -172);
        glVertex2i(172, -158);
        glVertex2i(200, -186);
        glVertex2i(228, -158);
        glVertex2i(242, -172);
        glVertex2i(214, -200);
        glVertex2i(242, -228);
        glVertex2i(228, -242);
        glVertex2i(200, -214);
        glVertex2i(172, -242);
        glVertex2i(158, -228);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("berij vajabaaki gunakar");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
