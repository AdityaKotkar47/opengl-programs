#include <GL/glut.h>

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("just a window");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
