#include <GL/glut.h>
#include <math.h>

typedef float matris[4][4];

static GLfloat input[8][3] = {
    {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, -0.5, 0.5}, {-0.5, -0.5, 0.5},
    {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, -0.5, -0.5}, {-0.5, -0.5, -0.5}
};

// GLfloat dy = 0; // Angle for rotation around Y
GLfloat dX = 0; // Uncomment this line for rotation around X


void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); // Adjusted for centering
    glEnable(GL_DEPTH_TEST);
}

void spin() {
    // dy += 0.08; // for Y rotation
    dX += 0.08; // for X rotation

    /*if (dy > 360) {
        dy = 0; // Reset angle after full rotation
    }*/
    if (dX > 360) dX = 0; // Reset angle after full rotation for X

    glutPostRedisplay();
}

void draw(float a[8][3]){
    GLfloat rV[8][3]; // Rotated vertices

    // Rotation around Y-axis
    //GLfloat r1 = dy * M_PI / 180; // Convert degrees to radians
    for (int i = 0; i < 8; i++) {
        /*
        rV[i][0] = a[i][0] * cos(r1) - a[i][2] * sin(r1);
        rV[i][2] = a[i][0] * sin(r1) + a[i][2] * cos(r1);
        rV[i][1] = a[i][1];
            */

        /*
        Uncomment the following lines to rotate around the X-axis instead:
        */
        GLfloat tempY = a[i][1] * cos(dX * M_PI / 180) - a[i][2] * sin(dX * M_PI / 180);
        GLfloat tempZ = a[i][1] * sin(dX * M_PI / 180) + a[i][2] * cos(dX * M_PI / 180);
        rV[i][1] = tempY;
        rV[i][2] = tempZ;
        rV[i][0] = a[i][0];



    }

    glBegin(GL_TRIANGLES);
        glColor3f(0.7, 0.4, 0.5); // behind
            glVertex3fv(rV[0]);
            glVertex3fv(rV[1]);
            glVertex3fv(rV[2]);
            glVertex3fv(rV[2]);
            glVertex3fv(rV[3]);
            glVertex3fv(rV[0]);
        glColor3f(0.3, 0.5, 0.7); // bottom
            glVertex3fv(rV[4]);
            glVertex3fv(rV[5]);
            glVertex3fv(rV[6]);
            glVertex3fv(rV[6]);
            glVertex3fv(rV[7]);
            glVertex3fv(rV[4]);
        glColor3f(1.0, 0.4, 0.5); // left
            glVertex3fv(rV[4]);
            glVertex3fv(rV[7]);
            glVertex3fv(rV[6]);
            glVertex3fv(rV[6]);
            glVertex3fv(rV[5]);
            glVertex3fv(rV[4]);
        glColor3f(0.7, 1.0, 0.5); // right
            glVertex3fv(rV[6]);
            glVertex3fv(rV[2]);
            glVertex3fv(rV[1]);
            glVertex3fv(rV[1]);
            glVertex3fv(rV[5]);
            glVertex3fv(rV[6]);
        glColor3f(0.7, 0.4, 1.0); // top
            glVertex3fv(rV[6]);
            glVertex3fv(rV[2]);
            glVertex3fv(rV[3]);
            glVertex3fv(rV[3]);
            glVertex3fv(rV[7]);
            glVertex3fv(rV[6]);
        glColor3f(0.7, 1.0, 1.0); // front
            glVertex3fv(rV[6]);
            glVertex3fv(rV[5]);
            glVertex3fv(rV[4]);
            glVertex3fv(rV[4]);
            glVertex3fv(rV[7]);
            glVertex3fv(rV[6]);
    glEnd();
}

void display_yeah_karega(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw(input);
    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800 ,600 ); // Smaller window size
    glutCreateWindow("jhum barabar");
    init();
    glutDisplayFunc(display_yeah_karega);
    glutIdleFunc(spin); // Call spin function during idle time
    glutMainLoop();
    return 0;
}
