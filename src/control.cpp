#include "globals.hpp"


// Função para tratar entrada do teclado
void keyboard(unsigned char key, int x, int y) {
    // Rotaciona a câmera ao redor da roda gigante (horizontal)
    if (key == 'a' || key == 'A') {
        anguloAzimute -= 0.05f;  // Move a câmera para a esquerda (ânguloAzimute)
    }
    if (key == 'd' || key == 'D') {
        anguloAzimute += 0.05f;  // Move a câmera para a direita (ânguloAzimute)
    }

    // Inclina a câmera para cima/baixo (vertical)
    if (key == 'w' || key == 'W') {
        anguloElevação += 0.05f;  // Inclina a câmera para cima
        if (anguloElevação > 1.5f) anguloElevação = 1.5f;  // Limita a rotação para cima
    }
    if (key == 's' || key == 'S') {
        anguloElevação -= 0.05f;  // Inclina a câmera para baixo
        if (anguloElevação < -1.5f) anguloElevação = -1.5f;  // Limita a rotação para baixo
    }

    // Aproxima ou afasta a câmera
    if (key == 'e' || key == 'E' || key == '=') {
        distanciaCamera -= 0.2f;  // Aproxima a câmera
        if (distanciaCamera < 2.0f) distanciaCamera = 2.0f;  // Limite mínimo de aproximação
    }
    if (key == 'q' || key == 'Q' || key == '-') {
        distanciaCamera += 0.2f;  // Afasta a câmera
    }

    // Parar o movimento da roda com 'L'
    if (key == 'l' || key == 'L') {
        movimentoAtivo = !movimentoAtivo;
    }
}