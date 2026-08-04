#ifndef RENDER_H
#define RENDER_H

extern bool lightingEnabled;

void init();
void display();
void reshape(int width, int height);
void toggleLighting();

#endif