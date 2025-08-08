#include <GL/glut.h>
#include "globals.hpp"
#include "draw.hpp"
#include <math.h>


// Função de renderização da cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Converte os ângulos esféricos para coordenadas cartesianas para controlar a posição da câmera
    float cameraX = distanciaCamera * cos(anguloElevação) * sin(anguloAzimute);
    float cameraY = distanciaCamera * sin(anguloElevação);  // Controla a altura (elevação)
    float cameraZ = distanciaCamera * cos(anguloElevação) * cos(anguloAzimute);

    // Configuração da câmera
    gluLookAt(cameraX, cameraY, cameraZ,   // Posição da câmera com base nos ângulos
              0.0, 0.0, 0.0,   // Para onde a câmera aponta (centro da roda)
              0.0, 1.0, 0.0);  // Vetor "up" (mantido fixo no eixo Y)

    glPushMatrix();
        glRotatef(anguloRoda, 0.0f, 0.0f, 1.0f);
        desenhaRoda();
    glPopMatrix();

    desenhaBase();

    glutSwapBuffers();
}