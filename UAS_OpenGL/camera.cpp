#include "camera.h"
#include <GL/freeglut.h>

float cameraX = 0.0f;
float cameraY = -0.2f;
float cameraZ = 9.5f;

float rotateY = -20.0f;

void setupCamera()
{
    glLoadIdentity();

    glTranslatef(cameraX, cameraY, -cameraZ);

    glRotatef(rotateY, 0, 1, 0);
}