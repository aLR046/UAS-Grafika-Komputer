#include "house.h"
#include "camera.h"
#include "render.h"
#include <GL/freeglut.h>

bool lightingEnabled = true;

void init()
{
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    // Lighting
 
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glShadeModel(GL_SMOOTH);
}

void setupLight()
{
    GLfloat lightPosition[] =
    {
        8.0f,
        10.0f,
        8.0f,
        1.0f
    };

    GLfloat ambient[] =
    {
        0.3f,
        0.3f,
        0.3f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    // Material
    GLfloat matSpecular[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat matShininess[] = { 20.0f };

    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
}

void toggleLighting()
{
    lightingEnabled = !lightingEnabled;

    if (lightingEnabled)
    {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    else
    {
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
    }

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setupCamera();

    if (lightingEnabled)
    {
        setupLight();
    }

    drawHouse();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    float ratio = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, ratio, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}