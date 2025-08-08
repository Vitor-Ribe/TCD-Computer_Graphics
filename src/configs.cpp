#include <GL/glut.h>

// Função reshape para configurar a viewport e a projeção
void reshape(int w, int h) {
    if (h == 0) h = 1; // Evita divisão por zero
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w/h, 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}