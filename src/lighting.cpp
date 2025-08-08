#include <GL/glut.h>

void inicializaIluminacao() {
    glEnable(GL_LIGHTING);  // Habilita o uso da iluminação

    // Configuração da luz ambiente
    float luzAmbiente[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float luzDifusa[] = {0.8f, 0.8f, 0.8f, 1.0f};  // Luz branca suave
    float luzEspecular[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Reflexão especular (brilho)
    float posicaoLuz[] = {5.0f, 5.0f, 10.0f, 1.0f};  // Posição da luz

    // Configuração da luz 0 (fonte de luz)
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    glEnable(GL_LIGHT0);  // Habilita a fonte de luz 0

    // Configuração global do ambiente da cena
    float luzGlobalAmbiente[] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalAmbiente);

    // Habilita a definição automática de material com a função glColor
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Ativa o teste de profundidade
    glEnable(GL_DEPTH_TEST);
}