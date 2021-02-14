#ifndef DRAWLIB_H
#define DRAWLIB_H
#include "GL/glut.h"
#include <ctime>
#include <cmath>
#include <vector>

struct Figure {
    float x,y;
    float r,g,b;
    float Sx,Sy;
    float Tx,Ty;
};

struct Circle {
    float r,g,b,Sx,Sy,Tx,Ty;
};

struct Point {
    float x,y;
};

extern std::vector <Figure> forest;
extern std::vector <Figure> stars;

extern clock_t currentTime;

void plotFallingStar();
void initFallingStar();
void drawStar(Figure star);
void drawStars();
void drawSky(Figure sky);
void drawCircle(Circle);
void drawCat(Figure cat);
void drawHouse(float windowR, float windowG, float windowB);
void drawForest();
void drawTree(Figure tree);
void draw();

#endif // DRAWLIB_H
