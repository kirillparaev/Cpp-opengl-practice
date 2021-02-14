#include <GL/glut.h>
#include <drawLib.h>
#include <vector>
#include <ctime>

Figure sky, cat;
Circle sun, moon, cloud_right, cloud_left, cloud_center;

std::vector <Figure> forest;
std::vector <Figure> stars;
std::vector <Point> graph;

clock_t currentTime;

void drawSky(Figure sky){
    glBegin(GL_QUADS);
    //небо
    glColor3f(sky.r,sky.g,sky.b);
    glVertex2f(-1,1);
    glVertex2f(1,1);
    glVertex2f(1,-1);
    glVertex2f(-1,-1);
    glEnd();
}

void drawTree(Figure tree){
    glPushMatrix();
    glTranslatef(tree.x,tree.y,1);
    glBegin(GL_QUADS);
    //ствол ели
    glColor3f(.32,.28,.08);
    glVertex2f(-.08,-.1);
    glVertex2f(.04,-.1);
    glVertex2f(.04,-.17);
    glVertex2f(-.08,-.17);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tree.x,tree.y,1);
    glBegin(GL_TRIANGLES);
    //листья ели
    glColor3f(tree.r,1,0);
    glVertex2f(-.15,-.1);
    glVertex2f(0,.15);
    glVertex2f(.1,-.1);
    glEnd();
    glPopMatrix();
}

void drawCat(Figure cat){
    glPushMatrix();
    glScalef(cat.Sx,cat.Sy,0);
    glTranslatef(cat.Tx,cat.Ty,0);
    glBegin(GL_TRIANGLES);
     //тело
     glColor3f(cat.r,cat.g,cat.b);
     glVertex2f(-.5,-.5);
     glVertex2f(.5,-.5);
     glVertex2f(0,.3);
     //правое ухо
     glColor3f(0,1,0);
     glVertex2f(.04,.2);
     glVertex2f(.16,.05);
     glVertex2f(.35,.2);
     //левое ухо
     glColor3f(0,1,0);
     glVertex2f(-.04,.2);
     glVertex2f(-.16,.05);
     glVertex2f(-.35,.2);
     //левый глаз
     glColor3f(0,0,0);
     glVertex2f(-.12,.02);
     glVertex2f(0,0);
     glVertex2f(-.12,-.07);
     //правый глаз
     glVertex2f(.12,-.07);
     glVertex2f(0,0);
     glVertex2f(.12,.02);
     //рот
     glColor3f(0,0,1);
     glVertex2f(-.12,-.12);
     glVertex2f(.12,-.12);
     glVertex2f(0,-.19);
     glEnd();
    glPopMatrix();}

void drawForest(){
    glPushMatrix();
    srand(clock());         //динамический рандом
    Figure tree;
    for(int i=0; i<25; i++){
        tree.Sx = .5 ; tree.Sy = .5; tree.Ty = 0; tree.b = 0; tree.g = 1;      //инициализация статичных параметров
        tree.x = -(0.1 * (rand() % 10));
        tree.y = -(0.1 * (rand() % 10));
        tree.r = abs((0.01 * (rand() % 10))*10);
        forest.push_back(tree);
     }
    for(int i=0; i<25; i++){
        drawTree(forest[i]);
    }
    glPopMatrix();
}

void drawStar(Figure star){
    glPushMatrix();
    glScalef(star.Sx, star.Sy, 1);
    glTranslatef(star.x, star.y, 1);

    glBegin(GL_QUADS);
    glColor3f(star.r, star.g, star.b);
    glVertex2f(-.02,.02);
    glVertex2f(.02,.02);
    glVertex2f(.02,-.02);
    glVertex2f(-.02,-.02);
    glEnd();
    glPopMatrix();
}

void drawStars(){
    glPushMatrix();
    srand(clock());         //динамический рандом
    Figure star;
    for(int i=0; i<100; i++){
        star.Sx = .2 ; star.Sy = .2; star.Ty = 0; star.Tx = 0; star.b = 1; star.g = 1; star.r = 1;     //инициализация статичных параметров
        star.x = -(1 * (rand() % 10));                  //рандомизатор, похоже, выдаёт только положительные числа, из-за
        star.y = (1 * (rand() % 10));                   //чего отрисовка звёзд происходит только в одной из четвертей пространства, в зависимости от знаков x y.
        stars.push_back(star);                          //это "исправлено" увеличением кол-ва звёзд в 2 раза и записью отзеркаленных по х звёзд в эти новые элементы массива
        star.x = -star.x;
        stars.push_back(star);
     }
    for(int i=0; i<100; i++){
        drawStar(stars[i]);
    }
    glPopMatrix();
}

void drawHouse(float windowR, float windowG, float windowB){
    glPushMatrix();
    glTranslatef(.6,.2,0);
    glScalef(.8,.8,1);
    glBegin(GL_QUADS);
    //стена дома
    glColor3f(.93,0,.16);
    glVertex2f(-.5,.3);
    glVertex2f(.5,.3);
    glVertex2f(.5,-.55);
    glVertex2f(-.5,-.55);
    //дверь
    glColor3f(.66,.63,.38);
    glVertex2f(-.2,-.23);
    glVertex2f(0,-.23);
    glVertex2f(0,-.55);
    glVertex2f(-.2,-.55);
    //ручка двери
    glColor3f(.26,.22,.4);
    glVertex2f(-.1,-.4);
    glVertex2f(0,-.4);
    glVertex2f(0,-.43);
    glVertex2f(-.1,-.43);

    //окна
    //левая оконная рама
    //glColor3f(.54,.78,.62);
    glColor3f(.73,.73,.73);
    glVertex2f(-.37,.19);
    glColor3f(.73,.73,.73);
    glVertex2f(-.2,.19);
    glColor3f(windowR,windowG,windowB);
    glVertex2f(-.2,-.11);
    glColor3f(windowR,windowG,windowB);
    glVertex2f(-.37,-.11);
    //правая оконная рама
    glColor3f(.73,.73,.73);
    glVertex2f(.2,.19);
    glColor3f(.73,.73,.73);
    glVertex2f(.4,.19);
    glColor3f(windowR,windowG,windowB);
    glVertex2f(.4,-.12);
    glColor3f(windowR,windowG,windowB);
    glVertex2f(.2,-.12);
    //левый подоконник
    glColor3f(.11,.12,.12);
    glVertex2f(-.45,-.11);
    glVertex2f(-.13,-.11);
    glVertex2f(-.17,-.2);
    glVertex2f(-.41,-.2);
    //правый подоконник
    glColor3f(.11,.12,.12);
    glVertex2f(.12,-.12);
    glVertex2f(.46,-.12);
    glVertex2f(.4,-.2);
    glVertex2f(.15,-.2);
    //ставни левого окна слева направо
    glColor3f(.15,.73,.39);
    glVertex2f(-.46,.25);
    glVertex2f(-.37,.19);
    glVertex2f(-.37,-.11);
    glVertex2f(-.46,-.2);

    glColor3f(.15,.73,.39);
    glVertex2f(-.2,.19);
    glVertex2f(-.12,.12);
    glVertex2f(-.12,-.2);
    glVertex2f(-.2,-.11);

    //ставни правого окна слева направо
    glColor3f(.15,.73,.39);
    glVertex2f(.1,.24);
    glVertex2f(.2,.19);
    glVertex2f(.2,-.12);
    glVertex2f(.1,-.2);

    glColor3f(.15,.73,.39);
    glVertex2f(.4,.19);
    glVertex2f(.48,.25);
    glVertex2f(.48,-.2);
    glVertex2f(.4,-.12);

    //труба отопления
    //основание
    glPushMatrix();
    glScalef(0,.7,0);
    glColor3f(.87,.91,.91);
    glVertex2f(.4,.7);
    glVertex2f(.5,.7);
    glVertex2f(.5,.4);
    glVertex2f(.4,.4);
    //переход
    glColor3f(.57,.58,.58);
    glVertex2f(.36,.76);
    glVertex2f(.54,.76);
    glVertex2f(.5,.7);
    glVertex2f(.4,.7);
    //вершина трубы
    glColor3f(.3,.3,.3);
    glVertex2f(.36,.93);
    glVertex2f(.54,.93);
    glVertex2f(.54,.76);
    glVertex2f(.36,.76);

    glColor3f(.46,.46,.46);
    glVertex2f(.36,.9);
    glVertex2f(.425,.9);
    glVertex2f(.425,.8);
    glVertex2f(.36,.8);

    glColor3f(.46,.46,.46);
    glVertex2f(.48,.9);
    glVertex2f(.54,.9);
    glVertex2f(.54,.8);
    glVertex2f(.48,.8);
    glPopMatrix();
    glEnd();

    glBegin(GL_TRIANGLES);
    //крыша дома
    glColor3f(.42,.33,.21);
    glVertex2f(-.7,.3);
    glVertex2f(0,.75);
    glVertex2f(.7,.3);
    glEnd();
    glPopMatrix();
}

void drawCircle(Circle circle){
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
      for(float i = 0; i<2*M_PI; i+=M_PI/16) {
          glColor3f(circle.r,circle.g,circle.b);
          glVertex2f((cos(i)/circle.Sx)+circle.Tx, (sin(i)/circle.Sy)+circle.Ty);
       }
    glEnd();
    glPopMatrix();
}

void draw(){
    currentTime = clock();
    float phi = currentTime*0.0005;       //phi = currentTime*<скорость анимации>
    //координаты солнца
    float sun_x = .96 * sin(phi);         //x=<отступ от края>*sin(phi), чем меньше значение отступа, тем дальше от края
    float sun_y = .96 * cos(phi);         //значения "x y" одинаковы - траектория круга, растяжение - овал или эллипс
    //координаты луны
    float moon_x = -.96 * sin(phi);
    float moon_y = -.96 * cos(phi);

    Figure sky, cat;
    Circle sun, moon, cloud_right, cloud_left, cloud_center;

    sky.r=.05; sky.g=.73 * cos(phi) ; sky.b=.92 * cos(phi);
    drawSky(sky);

    if (moon_y > 0) {drawStars(); plotFallingStar();}

    //солнце
    glPushMatrix();
    glTranslatef(sun_x,sun_y,0);
    sun.r=.84; sun.g=.87; sun.b=.03; sun.Sx=5; sun.Sy=5; sun.Tx=0; sun.Ty=0;
    drawCircle(sun);
    glPopMatrix();

    //луна
    glPushMatrix();
    glTranslatef(moon_x,moon_y,0);
    moon.r=.45; moon.g=.45; moon.b=.42; moon.Sx=5; moon.Sy=5; moon.Tx=0; moon.Ty=0;
    drawCircle(moon);
    glPopMatrix();

    glBegin(GL_QUADS);
    //земля
    glColor3f(.91,.81,.1);
    glVertex2f(-1,0);
    glColor3f(.13,.63,.24);
    glVertex2f(1,0);
    glVertex2f(1,-1);
    glColor3f(.91,.81,.1);
    glVertex2f(-1,-1);
    glEnd();

    drawForest();

    //дом, коты(слева направо)
    if (moon_y>0) {drawHouse(.81,.47,.12);} else {drawHouse(.15,.36,.76);}
    cat.r=.76, cat.g=.44, cat.b=.06, cat.Tx=.2, cat.Ty=-1.5, cat.Sx=.35, cat.Sy=.35;
    drawCat(cat);
    cat.r=.29, cat.g=.29, cat.b=.3, cat.Tx=.5, cat.Ty=-1.7, cat.Sx=.35, cat.Sy=.35;
    drawCat(cat);
    cat.r=.15, cat.g=.31, cat.b=.6, cat.Tx=.8, cat.Ty=-1.75, cat.Sx=.35, cat.Sy=.35;
    drawCat(cat);

    //облака
    glPushMatrix();
    cloud_right.r=.71; cloud_right.g=.71; cloud_right.b=.71; cloud_right.Sx=5; cloud_right.Sy=5; cloud_right.Tx=-.625*cos(phi); cloud_right.Ty=.65;
    cloud_left.r=.71; cloud_left.g=.71; cloud_left.b=.71; cloud_left.Sx=7; cloud_left.Sy=7; cloud_left.Tx=-.39*cos(phi); cloud_left.Ty=.6;
    cloud_center.r=.71; cloud_center.g=.71; cloud_center.b=.71; cloud_center.Sx=7; cloud_center.Sy=7; cloud_center.Tx=-.8*cos(phi); cloud_center.Ty=.6;
    drawCircle(cloud_right);
    drawCircle(cloud_left);
    drawCircle(cloud_center);
    glPopMatrix();
}

void initFallingStar(){
    Point p;

    float x = 0.0;
    float xf = 10;
    float h = 0.1;

    while(x<xf){
        x = x+h;
        p.x = x;
        p.y = sqrt(x);

        graph.push_back(p);
    }
}

void plotFallingStar(){
    glPushMatrix();
    glRotatef(25,.1,.1,1);
    //glTranslatef(-.875,-.65,0);            около двери дома
    glTranslatef(-.4,.5,0);
    glScalef(.1,.1,1);
    glBegin(GL_LINE_STRIP);
    for(int i=0; i<graph.size(); i++){
        glColor3f(1,1,1);
        glVertex2f(graph[i].x, graph[i].y);
        }
    glEnd();
    glPopMatrix();
}
