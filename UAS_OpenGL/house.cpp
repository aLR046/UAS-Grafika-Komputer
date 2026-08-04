#include "house.h"
#include <GL/freeglut.h>

float doorAngle = 0.0f;

bool doorOpening = false;
bool doorClosing = false;

void updateDoor()
{
    if (doorOpening)
    {
        doorAngle -= 2.0f;

        if (doorAngle <= -90.0f)
        {
            doorAngle = -90.0f;
            doorOpening = false;
        }
    }

    if (doorClosing)
    {
        doorAngle += 2.0f;

        if (doorAngle >= 0.0f)
        {
            doorAngle = 0.0f;
            doorClosing = false;
        }
    }
}


void drawGround()
{
    glColor3f(0.25f, 0.60f, 0.25f);

    glBegin(GL_QUADS);

    glVertex3f(-10, -1, -10);
    glVertex3f(10, -1, -10);
    glVertex3f(10, -1, 10);
    glVertex3f(-10, -1, 10);

    glEnd();
}


void drawFoundation()
{
    glColor3f(0.55f, 0.55f, 0.55f);

    glPushMatrix();

    glTranslatef(0, -1.05f, 0);

    glScalef(2.8f, 0.25f, 2.8f);

    glutSolidCube(1);

    glPopMatrix();
}


void drawBody()
{
    glColor3f(0.95f, 0.90f, 0.80f);

    glPushMatrix();

    glScalef(2.5f, 2.0f, 2.5f);

    glutSolidCube(1);

    glPopMatrix();
}


// Lantai Teras
void drawTerrace()
{
    glColor3f(0.75f, 0.75f, 0.75f);

    glPushMatrix();

    glTranslatef(0.0f, -0.92f, 1.65f);
    glScalef(1.8f, 0.12f, 0.9f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Tiang Teras
void drawTerracePillars()
{
    glColor3f(0.90f, 0.90f, 0.90f);

    // Tiang kiri
    glPushMatrix();

    glTranslatef(-0.75f, -0.20f, 2.00f);
    glScalef(0.12f, 1.45f, 0.12f);

    glutSolidCube(1.0);

    glPopMatrix();

    // Tiang kanan
    glPushMatrix();

    glTranslatef(0.75f, -0.20f, 2.00f);
    glScalef(0.12f, 1.45f, 0.12f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Kanopi Teras
void drawTerraceRoof()
{
    glColor3f(0.65f, 0.10f, 0.08f);

    glPushMatrix();

    glTranslatef(0.0f, 0.55f, 1.65f);
    glScalef(1.90f, 0.08f, 1.00f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Tangga
void drawSteps()
{
    glColor3f(0.65f, 0.65f, 0.65f);

    // Tangga atas
    glPushMatrix();

    glTranslatef(0.0f, -1.02f, 2.05f);
    glScalef(1.4f, 0.10f, 0.40f);

    glutSolidCube(1.0);

    glPopMatrix();

    // Tangga bawah
    glPushMatrix();

    glTranslatef(0.0f, -1.12f, 2.35f);
    glScalef(1.1f, 0.10f, 0.30f);

    glutSolidCube(1.0);

    glPopMatrix();
}


// Atap Rumah
void drawRoof()
{
    glColor3f(0.65f, 0.12f, 0.08f);

    glBegin(GL_TRIANGLES);

    // Depan
    glNormal3f(0.0f, 0.7f, 0.7f);

    glVertex3f(-1.4f, 1.0f, 1.25f);
    glVertex3f(1.4f, 1.0f, 1.25f);
    glVertex3f(0.0f, 2.0f, 1.25f);

    // Belakang
    glNormal3f(0.0f, 0.7f, -0.7f);

    glVertex3f(-1.4f, 1.0f, -1.25f);
    glVertex3f(0.0f, 2.0f, -1.25f);
    glVertex3f(1.4f, 1.0f, -1.25f);

    glEnd();

    glBegin(GL_QUADS);

    // Bidang kiri
    glNormal3f(-0.7f, 0.7f, 0.0f);

    glVertex3f(-1.4f, 1.0f, -1.25f);
    glVertex3f(0.0f, 2.0f, -1.25f);
    glVertex3f(0.0f, 2.0f, 1.25f);
    glVertex3f(-1.4f, 1.0f, 1.25f);

    // Bidang kanan
    glNormal3f(0.7f, 0.7f, 0.0f);

    glVertex3f(0.0f, 2.0f, -1.25f);
    glVertex3f(1.4f, 1.0f, -1.25f);
    glVertex3f(1.4f, 1.0f, 1.25f);
    glVertex3f(0.0f, 2.0f, 1.25f);

    glEnd();
}

// List Atap
void drawRoofBorder()
{
    glColor3f(0.45f, 0.05f, 0.05f);

    // Depan
    glPushMatrix();

    glTranslatef(0.0f, 1.02f, 1.28f);
    glScalef(2.90f, 0.08f, 0.08f);

    glutSolidCube(1.0);

    glPopMatrix();


    // Belakang
    glPushMatrix();

    glTranslatef(0.0f, 1.02f, -1.28f);
    glScalef(2.90f, 0.08f, 0.08f);

    glutSolidCube(1.0);

    glPopMatrix();


    // Nok Atap
    glPushMatrix();

    glTranslatef(0.0f, 2.02f, 0.0f);
    glScalef(0.10f, 0.10f, 2.60f);

    glutSolidCube(1.0);

    glPopMatrix();
}


// Daun Pintu
void drawDoorLeaf()
{
    glColor3f(0.55f, 0.30f, 0.10f);

    const float w = 0.50f;
    const float h = 1.10f;
    const float t = 0.05f;

    glBegin(GL_QUADS);

    // Depan
    glNormal3f(0, 0, 1);
    glVertex3f(0, 0, t);
    glVertex3f(w, 0, t);
    glVertex3f(w, h, t);
    glVertex3f(0, h, t);

    // Belakang
    glNormal3f(0, 0, -1);
    glVertex3f(w, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, h, 0);
    glVertex3f(w, h, 0);

    // Kiri
    glNormal3f(-1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, t);
    glVertex3f(0, h, t);
    glVertex3f(0, h, 0);

    // Kanan
    glNormal3f(1, 0, 0);
    glVertex3f(w, 0, t);
    glVertex3f(w, 0, 0);
    glVertex3f(w, h, 0);
    glVertex3f(w, h, t);

    // Atas
    glNormal3f(0, 1, 0);
    glVertex3f(0, h, t);
    glVertex3f(w, h, t);
    glVertex3f(w, h, 0);
    glVertex3f(0, h, 0);

    // Bawah
    glNormal3f(0, -1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(w, 0, 0);
    glVertex3f(w, 0, t);
    glVertex3f(0, 0, t);

    glEnd();
}

// Panel Pintu
void drawDoorPanels()
{
    const float panelDepth = 0.055f;

    glColor3f(0.42f, 0.22f, 0.08f);

    // Panel Atas
    glBegin(GL_QUADS);

    glNormal3f(0, 0, 1);

    glVertex3f(0.08f, 0.62f, panelDepth);
    glVertex3f(0.42f, 0.62f, panelDepth);
    glVertex3f(0.42f, 0.98f, panelDepth);
    glVertex3f(0.08f, 0.98f, panelDepth);

    glEnd();

    // Panel Bawah
    glBegin(GL_QUADS);

    glNormal3f(0, 0, 1);

    glVertex3f(0.08f, 0.12f, panelDepth);
    glVertex3f(0.42f, 0.12f, panelDepth);
    glVertex3f(0.42f, 0.48f, panelDepth);
    glVertex3f(0.08f, 0.48f, panelDepth);

    glEnd();
}

// Gagang Pintu
void drawDoorKnob()
{

    // Dudukan Gagang
    glColor3f(0.80f, 0.65f, 0.10f);

    glPushMatrix();

    glTranslatef(0.45f, 0.50f, 0.055f);
    glScalef(0.03f, 0.03f, 0.01f);

    glutSolidCube(1.0);

    glPopMatrix();


    // Batang Gagang
    glPushMatrix();

    glTranslatef(0.45f, 0.50f, 0.075f);
    glRotatef(90.0f, 0, 1, 0);

    GLUquadric* rod = gluNewQuadric();

    gluCylinder(rod,
        0.006,
        0.006,
        0.02,
        12,
        4);

    gluDeleteQuadric(rod);

    glPopMatrix();

    // Knob
    glPushMatrix();

    glTranslatef(0.47f, 0.50f, 0.075f);

    glutSolidSphere(0.02f, 20, 20);

    glPopMatrix();
}

// PINTU UTAMA
void drawDoor()
{
    glPushMatrix();

    // Posisi engsel pintu
    glTranslatef(-0.25f, -0.90f, 1.26f);

    // Animasi buka tutup pintu
    glRotatef(doorAngle, 0.0f, 1.0f, 0.0f);

    // Gambar seluruh komponen pintu
    drawDoorLeaf();
    drawDoorPanels();
    drawDoorKnob();

    glPopMatrix();
}

// BINGKAI PINTU
void drawDoorFrame()
{
    glColor3f(0.45f, 0.25f, 0.10f);

    const float t = 0.05f;

    // Tiang kiri
    glPushMatrix();
    glTranslatef(-0.30f, -0.35f, 1.29f);
    glScalef(t, 1.25f, t);
    glutSolidCube(1.0);
    glPopMatrix();

    // Tiang kanan
    glPushMatrix();
    glTranslatef(0.30f, -0.35f, 1.29f);
    glScalef(t, 1.25f, t);
    glutSolidCube(1.0);
    glPopMatrix();

    // Balok atas
    glPushMatrix();
    glTranslatef(0.00f, 0.25f, 1.29f);
    glScalef(0.65f, t, t);
    glutSolidCube(1.0);
    glPopMatrix();
}

// AMBANG PINTU
void drawDoorStep()
{
    glColor3f(0.60f, 0.60f, 0.60f);

    glPushMatrix();

    glTranslatef(0.0f, -1.02f, 1.30f);
    glScalef(0.65f, 0.08f, 0.18f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Kaca Jendela
void drawGlass(float x, float y, float z)
{
    glColor3f(0.45f, 0.80f, 1.00f);

    glPushMatrix();

    glTranslatef(x, y, z);

    glScalef(0.42f, 0.42f, 0.03f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Bingkai Jendela
void drawWindowFrame(float x, float y, float z)
{
    glColor3f(0.45f, 0.25f, 0.10f);

    const float t = 0.05f;

    // Atas
    glPushMatrix();
    glTranslatef(x, y + 0.25f, z);
    glScalef(0.55f, t, t);
    glutSolidCube(1.0);
    glPopMatrix();

    // Bawah
    glPushMatrix();
    glTranslatef(x, y - 0.25f, z);
    glScalef(0.55f, t, t);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kiri
    glPushMatrix();
    glTranslatef(x - 0.25f, y, z);
    glScalef(t, 0.55f, t);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kanan
    glPushMatrix();
    glTranslatef(x + 0.25f, y, z);
    glScalef(t, 0.55f, t);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Pembagi Jendela
void drawWindowBars(float x, float y, float z)
{
    glColor3f(0.30f, 0.15f, 0.05f);

    // Vertikal
    glPushMatrix();

    glTranslatef(x, y, z);

    glScalef(0.05f, 0.42f, 0.04f);

    glutSolidCube(1.0);

    glPopMatrix();

    // Horizontal
    glPushMatrix();

    glTranslatef(x, y, z);

    glScalef(0.42f, 0.05f, 0.04f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// SATU JENDELA
void drawWindow(float x, float y, float z)
{
    // Kaca
    drawGlass(x, y, z);

    // Bingkai
    drawWindowFrame(x, y, z + 0.03f);

    // Pembagi
    drawWindowBars(x, y, z + 0.04f);
}

// SEMUA JENDELA
void drawWindows()
{
    // Jendela kiri
    drawWindow(-0.7f, -0.05f, 1.26f);

    // Jendela kanan
    drawWindow(0.7f, -0.05f, 1.26f);
}

// Badan Cerobong
void drawChimneyBody()
{
    glColor3f(0.35f, 0.35f, 0.35f);

    glPushMatrix();

    glTranslatef(0.55f, 1.75f, 0.0f);
    glScalef(0.30f, 0.80f, 0.30f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Tutup Cerobong
void drawChimneyCap()
{
    glColor3f(0.20f, 0.20f, 0.20f);

    glPushMatrix();

    glTranslatef(0.55f, 2.15f, 0.0f);
    glScalef(0.42f, 0.06f, 0.42f);

    glutSolidCube(1.0);

    glPopMatrix();
}

// Asap Cerobong
void drawSmoke()
{
    glColor4f(0.85f, 0.85f, 0.85f, 0.8f);

    // Asap 1
    glPushMatrix();

    glTranslatef(0.55f, 2.45f, 0.00f);

    glutSolidSphere(0.06f, 20, 20);

    glPopMatrix();

    // Asap 2
    glPushMatrix();

    glTranslatef(0.60f, 2.65f, 0.03f);

    glutSolidSphere(0.08f, 20, 20);

    glPopMatrix();

    // Asap 3
    glPushMatrix();

    glTranslatef(0.52f, 2.90f, -0.02f);

    glutSolidSphere(0.10f, 20, 20);

    glPopMatrix();
}

// Cerobong Lengkap
void drawChimney()
{
    drawChimneyBody();
    drawChimneyCap();
    drawSmoke();
}

// DRAW HOUSE
void drawHouse()
{
    
    // Ground
    drawGround();

    // Pondasi
    drawFoundation();

    // Teras
    drawTerrace();
    drawSteps();
    drawTerracePillars();
    drawTerraceRoof();

    // Bangunan Utama
    drawBody();

    // Atap
    drawRoof();
    drawRoofBorder();

    // Pintu
    drawDoorFrame();
    drawDoorStep();
    drawDoor();

    // Jendela
    drawWindows();

    // Cerobong
    drawChimney();
}