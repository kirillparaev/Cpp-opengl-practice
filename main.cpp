#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <ctime>
#include <vector>
#include <drawLib.h>

void renderScene(void);

void animateScene(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, animateScene, 1);
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна здесь жить

    draw();

    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    initFallingStar();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("output");
    glutDisplayFunc(renderScene);
    glutTimerFunc(1000/60,animateScene,1);
    glutMainLoop();
    return 0;
}
