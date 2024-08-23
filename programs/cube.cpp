#include<GL/glut.h>

typedef float matrix[4][4];

static GLfloat input[8][3] =
{
    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
    {30,30,0},{80,30,0},{80,80,0},{30,80,0}
};


void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(-10.0, 454.0, -10.0, 250.0, -250.0, 250.0);
    glEnable(GL_DEPTH_TEST);
}

void draw(float a[8][3])
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.4,0.5);
        glVertex3fv(a[0]);
        glVertex3fv(a[1]);
        glVertex3fv(a[2]);
        glVertex3fv(a[2]);
        glVertex3fv(a[3]);
        glVertex3fv(a[0]);
    glColor3f(0.8,0.2,0.4);
        glVertex3fv(a[0]);
        glVertex3fv(a[4]);
        glVertex3fv(a[5]);
        glVertex3fv(a[5]);
        glVertex3fv(a[1]);
        glVertex3fv(a[0]);
    glColor3f(0.3,0.6,0.7);
        glVertex3fv(a[0]);
        glVertex3fv(a[4]);
        glVertex3fv(a[7]);
        glVertex3fv(a[7]);
        glVertex3fv(a[3]);
        glVertex3fv(a[0]);
    glColor3f(0.2,0.8,0.2);
        glVertex3fv(a[6]);
        glVertex3fv(a[5]);
        glVertex3fv(a[1]);
        glVertex3fv(a[1]);
        glVertex3fv(a[2]);
        glVertex3fv(a[6]);
    glColor3f(0.7,0.7,0.2);
        glVertex3fv(a[6]);
        glVertex3fv(a[2]);
        glVertex3fv(a[3]);
        glVertex3fv(a[3]);
        glVertex3fv(a[7]);
        glVertex3fv(a[6]);
    glColor3f(0.1,0.1,0.1);
        glVertex3fv(a[6]);
        glVertex3fv(a[7]);
        glVertex3fv(a[4]);
        glVertex3fv(a[4]);
        glVertex3fv(a[5]);
        glVertex3fv(a[6]);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    draw(input);
    glFlush();
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1400,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Cube");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
