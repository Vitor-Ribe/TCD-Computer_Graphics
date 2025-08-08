#include <GL/glut.h>

void defineCorMetalica() {

    // Define propriedades metálicas
    float matAmbiente[] = {0.3f, 0.3f, 0.3f, 1.0f};  // Cor ambiente
    float matDifusa[] = {0.7f, 0.7f, 0.7f, 1.0f};  // Cor difusa (cinza metálico)
    float matEspecular[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Reflexão especular (brilho)
    float brilho = 50.0f;  // Quanto maior, mais brilhante

    // Aplica as propriedades de material
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDifusa);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matEspecular);
    glMaterialf(GL_FRONT, GL_SHININESS, brilho);
}