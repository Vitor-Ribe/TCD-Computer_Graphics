#include "globals.hpp"
#include <GL/glut.h>

// Função de animação
void timer(int value) {
    if (movimentoAtivo) {
        // Atualiza o ângulo de rotação da roda
        anguloRoda += 0.5f;
        if (anguloRoda > 360.0f)
            anguloRoda -= 360.0f;

        // Atualiza o balanço das cabines
        if (direcaoBalanço) {
            anguloCabineBalanço += velocidadeBalanço;
            if (anguloCabineBalanço > 5.0f) direcaoBalanço = false;  // Limita o ângulo do balanço
        } else {
            anguloCabineBalanço -= velocidadeBalanço;
            if (anguloCabineBalanço < -5.0f) direcaoBalanço = true;
        }

        // Reinicia a velocidade do balanço quando o movimento é reativado
        if (velocidadeBalanço < 0.2f) {
            velocidadeBalanço = 0.2f;  // Restabelece a velocidade do balanço ao valor inicial
        }
    } else {
        // Se o movimento for pausado, desacelere o balanço até ele parar suavemente
        if (velocidadeBalanço > 0.0f) {
            velocidadeBalanço -= 0.0005f;  // Reduz a velocidade do balanço gradualmente, mais lentamente
        }
        
        // Continua atualizando o ângulo de balanço mesmo após a desaceleração
        if (direcaoBalanço) {
            anguloCabineBalanço += velocidadeBalanço;
            if (anguloCabineBalanço > 5.0f) direcaoBalanço = false;
        } else {
            anguloCabineBalanço -= velocidadeBalanço;
            if (anguloCabineBalanço < -5.0f) direcaoBalanço = true;
        }
    }

    // Se a velocidade ficar muito baixa, pare o balanço
    if (velocidadeBalanço < 0.01f) {
        velocidadeBalanço = 0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);  // Aproximadamente 60 FPS
}