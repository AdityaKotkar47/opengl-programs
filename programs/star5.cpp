#include <GL/glut.h>

void init(){
    glClearColor(0.9, 0.85, 0.3, 1.0);
    gluOrtho2D(-300, 300, -300, 300);
}

void star(){

    glClear(GL_COLOR_BUFFER_BIT);

    // triangle - top
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0.6, 0.2);
        glVertex2f(0, 100);
        glVertex2f(-18.75, 25);
        glVertex2f(18.75, 25);
    glEnd();

    // triangle - top right
    glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.5, 0.9);
        glVertex2f(75, 25);
        glVertex2f(18.75, 25);
        glVertex2f(30, -20);
    glEnd();

    // triangle - top left
    glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.5, 0.9);
        glVertex2f(-75, 25);
        glVertex2f(-18.75, 25);
        glVertex2f(-30, -20);
    glEnd();

    // triangle - bottom right
    glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.8, 0.1);
        glVertex2f(50, -100);
        glVertex2f(0, -50);
        glVertex2f(30, -20);
    glEnd();

    // triangle - bottom left
    glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.8, 0.1);
        glVertex2f(-50, -100);
        glVertex2f(-30, -20);
        glVertex2f(0, -50);
    glEnd();

    // pentagon - center
    glBegin(GL_POLYGON);
        glColor3f(1, 0.6, 0.85);
        glVertex2f(-18.75, 25);
        glVertex2f(-30, -20);
        glVertex2f(0, -50);
        glVertex2f(30, -20);
        glVertex2f(18.75, 25);
    glEnd();

    // borders
   // glBegin(GL_LINES);
   //     glColor3f(0, 0, 0);

  //      glVertex2f(-18.75, 25);
   //     glVertex2f(-30, -20);

   //     glVertex2f(-30, -20);
      //  glVertex2f(0, -50);

    //    glVertex2f(0, -50);
     //   glVertex2f(30, -20);

     //   glVertex2f(30, -20);
    //    glVertex2f(18.75, 25);

      //  glVertex2f(18.75, 25);
      //  glVertex2f(-18.75, 25);

  //  glEnd();



    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("bhot tof hai");
    init();
    glutDisplayFunc(star);
    glutMainLoop();

    return 0;
}
