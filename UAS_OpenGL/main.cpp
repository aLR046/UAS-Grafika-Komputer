#include <GL/freeglut.h>
#include "render.h"
#include "camera.h"
#include "house.h"

void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
    case 'a':
    case 'A':
        rotateY -= 5.0f;
        break;

    case 'd':
    case 'D':
        rotateY += 5.0f;
        break;

    case 'w':
    case 'W':
        cameraY -= 0.3f;
        break;

    case 's':
    case 'S':
        cameraY += 0.3f;
        break;

    case 'q':
    case 'Q':
        cameraZ -= 0.5f;
        break;

    case 'e':
    case 'E':
        cameraZ += 0.5f;
        break;

    case 'o':
    case 'O':

        doorOpening = true;
        doorClosing = false;

        break;

    case 'p':
    case 'P':

        doorClosing = true;
        doorOpening = false;

        break;

    case 'l':
    case 'L':
        toggleLighting();
        break;

    case 27:
        exit(0);
    }

    glutPostRedisplay();
}

void timer(int)
{
    updateDoor();

    glutPostRedisplay();

    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(1000, 700);

    glutCreateWindow("UAS Grafika Komputer - Rumah 3D");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();

    return 0;
}