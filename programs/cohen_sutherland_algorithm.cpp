#include <GL/glut.h>

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 750, -250, 250);
}

typedef struct point {
    float x, y;
    int rC[4]; // Region code as an array of integers
} PT;

PT p1, p2, p3, p4;

float xmin = -100, xmax = 100, ymin = -100, ymax = 100;

// Function to set region codes for each point
void setRC(PT &p) {
    // Reset region codes
    for (int i = 0; i < 4; i++) {
        p.rC[i] = 0;
    }

    if (p.x < xmin)      // to the left of the clipping window
        p.rC[0] = 1;      // set bit 0
    else if (p.x > xmax) // to the right of the clipping window
        p.rC[1] = 1;      // set bit 1
    if (p.y < ymin)      // below the clipping window
        p.rC[2] = 1;      // set bit 2
    else if (p.y > ymax) // above the clipping window
        p.rC[3] = 1;      // set bit 3
}

// Function to get the category of the line based on region codes
int getCategory(PT p1, PT p2) {
    int outsideCheck = (p1.rC[0] | p1.rC[1] | p1.rC[2] | p1.rC[3]) |
                       (p2.rC[0] | p2.rC[1] | p2.rC[2] | p2.rC[3]);

    if (outsideCheck == 0) return 1; // Completely inside
    if ((p1.rC[0] & p2.rC[0]) || (p1.rC[1] & p2.rC[1]) ||
        (p1.rC[2] & p2.rC[2]) || (p1.rC[3] & p2.rC[3])) return 2; // Completely outside

    return 3; // Partially inside
}

// Function to plot a line from point p1 to point p2 with an offset
void plotLine(PT p1, PT p2, int offsetX = 0) {
    glColor3f(0.223, 1, 0.078);
    glBegin(GL_LINES);
        glVertex2f(p1.x + offsetX, p1.y);
        glVertex2f(p2.x + offsetX, p2.y);
    glEnd();
}

// Function to plot the clipping window
void plotWindow(int offsetX = 0) {
    glColor3f(0.86, 0.078, 0.235);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin + offsetX, ymin);
        glVertex2f(xmax + offsetX, ymin);
        glVertex2f(xmax + offsetX, ymax);
        glVertex2f(xmin + offsetX, ymax);
    glEnd();
}

// Cohen-Sutherland line clipping algorithm
void lineClipperCS(PT &p1, PT &p2) {
    setRC(p1);
    setRC(p2);

    int category = getCategory(p1, p2);

    switch (category) {
        case 1: // Line is completely inside
            plotLine(p1, p2);
            break;
        case 2: // Line is completely outside
            break;
        case 3: { // Line is partially inside
            float m = (p2.y - p1.y) / (p2.x - p1.x); // Calculate slope

            if (p1.rC[0] || p1.rC[1] || p1.rC[2] || p1.rC[3]) { // If p1 is outside
                if (p1.rC[3]) { // Above
                    p1.x += (ymax - p1.y) / m;
                    p1.y = ymax;
                } else if (p1.rC[2]) { // Below
                    p1.x += (ymin - p1.y) / m;
                    p1.y = ymin;
                }
                else if (p1.rC[1]) { // Right
                    p1.y += m * (xmax - p1.x);
                    p1.x = xmax;
                } else if (p1.rC[0]) { // Left
                    p1.y += m * (xmin - p1.x);
                    p1.x = xmin;
                }
                setRC(p1); // Update region code after modification
            }

            if (p2.rC[0] || p2.rC[1] || p2.rC[2] || p2.rC[3]) { // If p2 is outside
                if (p2.rC[3]) { // Above
                    p2.x += (ymax - p2.y) / m;
                    p2.y = ymax;
                } else if (p2.rC[2]) { // Below
                    p2.x += (ymin - p2.y) / m;
                    p2.y = ymin;
                }
                else if (p2.rC[1]) { // Right
                    p2.y += m * (xmax - p2.x);
                    p2.x = xmax;
                } else if (p2.rC[0]) { // Left
                    p2.y += m * (xmin - p2.x);
                    p2.x = xmin;
                }
                setRC(p2); // Update region code after modification
            }

            plotLine(p1, p2);
            break;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    plotWindow();
    plotWindow(500);

    // Define points for lines to be clipped
    p1.x = -150;
    p1.y = -50;
    p2.x = 150;
    p2.y = 200;
    p3.x = 50;
    p3.y = -120;
    p4.x = 120;
    p4.y = 50;

    plotLine(p1, p2);
    plotLine(p3, p4);

    lineClipperCS(p1, p2);   // Clip first line and draw it with offset
    lineClipperCS(p3, p4);   // Clip second line and draw it with offset

    plotLine(p1, p2, 500);
    plotLine(p3, p4, 500);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("cohen bhai sutherland clipper algo");

    glutDisplayFunc(display);

    init();

    glutMainLoop();

    return 0;
}
