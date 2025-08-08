#include <GL/glut.h>
#include "globals.hpp"
#include "colors.hpp"


void desenhaJanela() {
    glColor4f(0.5, 0.8, 1.0, 0.4); // cor azul claro com 50% de opacidade

    glBegin(GL_QUADS);
      glVertex3f(-0.2, -0.15, 0.0);
      glVertex3f( 0.2, -0.15, 0.0);
      glVertex3f( 0.2,  0.15, 0.0);
      glVertex3f(-0.2,  0.15, 0.0);
    glEnd();
}

void desenhaJanelasCabine() {
    // Janela frontal
    glPushMatrix();
      glTranslatef(0.0, 0.18, 0.2); // posiciona na frente da cabine
      desenhaJanela();
    glPopMatrix();

    // Janela traseira
    glPushMatrix();
      glTranslatef(0.0, 0.18, -0.2); // posiciona atrás da cabine
      glRotatef(180, 0, 1, 0);  // Rotaciona 180 graus em torno do eixo Y para manter a orientação correta
      desenhaJanela();
    glPopMatrix();

    // Janela lateral esquerda
    glPushMatrix();
      glTranslatef(-0.2, 0.18, 0.0); // posiciona à esquerda
      glRotatef(-90, 0, 1, 0);  // Rotaciona -90 graus em torno do eixo Y
      desenhaJanela();
    glPopMatrix();

    // Janela lateral direita
    glPushMatrix();
      glTranslatef(0.2, 0.18, 0.0); // posiciona à direita
      glRotatef(90, 0, 1, 0);   // Rotaciona 90 graus em torno do eixo Y
      desenhaJanela();
    glPopMatrix();
}

// Função para desenhar uma cabine com cor
void desenhaCabine(float r, float g, float b) {
    
    // Corpo principal da cabine
    glPushMatrix();
      glColor3f(r, g, b);
      glScalef(1.0, 0.6, 1.0);  // Escala para formar um retângulo
      glutSolidCube(0.45);
    glPopMatrix();
    
    // Teto ou capota da cabine
    glPushMatrix();
      glTranslatef(0.0, 0.3, 0.0); // Move para a parte superior
      glColor3f(r * 0.5, g * 0.5, b * 0.5); // Um tom um pouco diferente para diferenciar o teto
      glScalef(1.0, 0.15, 1.0);
      glutSolidCube(0.45);
    glPopMatrix();
    
    // Janelas da cabine
    desenhaJanelasCabine();
}

void desenhaEixoCentral(){
    GLUquadric* quadratic = gluNewQuadric();

    // Desenha Eixo
    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);  // Cor metálica mais escura para o eixo
        glTranslatef(0.0, 0.0, -0.41);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);  // Alinha o cilindro no eixo Z
        gluCylinder(quadratic, 0.1, 0.1, 0.81, 20, 10);  // Eixo com raio 0.1 e altura 0.3
    glPopMatrix();

    // Desenha a tampa inferior
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.41f);  // Coloca a tampa inferior na posição correta
        gluDisk(quadratic, 0.0f, 0.1, 20, 20); // Disco com o raio da base
    glPopMatrix();

    // Desenha a tampa superior
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.4f);  // Coloca a tampa inferior na posição correta
        gluDisk(quadratic, 0.0f, 0.1, 20, 20); // Disco com o raio da base
    glPopMatrix();

    gluDeleteQuadric(quadratic);
}

void desenhaAros(){
    glColor3f(0.7f, 0.7f, 0.7f); // cor metalica para os aros
    
    // Desenha o primeiro aro (frontal)
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.3f); // Leve translação no eixo Z
        glutSolidTorus(0.05, 2.0, 20, 60);
    glPopMatrix();

    // Desenha o segundo aro (traseiro)
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, -0.3f); // Leve translação no eixo Z, na direção oposta
        glutSolidTorus(0.05, 2.0, 20, 60);
    glPopMatrix();
}

void desenhaCabosdeAco(float angulo){
    glPushMatrix();
        // Frente
        glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        glTranslatef(0.0, 0.0, 0.3);
        glScalef(0.5f, 5.6f, 0.5f);  // Faz uma haste fina e alongada
        glColor3f(0.7f, 0.7f, 0.7f); // Cor metálica
        glRotatef(90, 1.0f, 0.0f, 0.0f); // Rotaciona o cilindro
        // Cria uma quadrica para desenhar o cilindro
        GLUquadric* quadrica = gluNewQuadric();
        gluCylinder(quadrica, 0.05, 0.05, 0.35, 20, 10);  // Cilindro fino (raio 0.05, altura 0.3)
        // Libera a memória alocada pela quadrica
        gluDeleteQuadric(quadrica);

        // fundo
        glTranslatef(0, -1.2, -0.1);
        glScalef(1.0f, 1.0f, 1.3f);  // Faz uma haste fina e alongada
        glColor3f(0.7f, 0.7f, 0.7f); // Cor metálica
        glRotatef(90, 0.0f, 0.0f, 1.0f); // Rotaciona o cilindro
        // Cria uma quadrica para desenhar o cilindro
        GLUquadric* quadrica0 = gluNewQuadric();
        gluCylinder(quadrica0, 0.05, 0.05, 0.35, 20, 10);  // Cilindro fino (raio 0.05, altura 0.3)
        // Libera a memória alocada pela quadrica
        gluDeleteQuadric(quadrica0);
    glPopMatrix();
}

void desenhaEixoCabines(){
    glPushMatrix();
        glTranslatef(0.0, 0.0, -0.3);
        glColor3f(0.7f, 0.7f, 0.7f); // Cor metálica
        GLUquadric* quadrica1 = gluNewQuadric();    // Cria uma quadrica para desenhar o cilindro
        gluCylinder(quadrica1, 0.05, 0.05, 0.6, 20, 10);  // Cilindro fino (raio 0.05, altura 0.3)
        gluDeleteQuadric(quadrica1);    // Libera a memória alocada pela quadrica
    glPopMatrix();
}

// Função para desenhar a roda e posicionar as cabines
void desenhaRoda() {
    // Define o reflexo metálico
    defineCorMetalica();
    // Desenha os aros da roda gigante
    desenhaAros();
    // Desenha o eixo central da roda gigante (cilindro no centro)
    desenhaEixoCentral();

    const int numCabines = 10;
    for (int i = 0; i < numCabines; i++) {
        float angulo = i * (360.0f / numCabines);
        
        // Desenha uma haste que conecta os aros ao eixo
        desenhaCabosdeAco(angulo);        

        glPushMatrix();
            glRotatef(angulo, 0.0f, 0.0f, 1.0f);
            glTranslatef(2.0, 0.0, 0.0);
            
            // Aplica o balanço nas cabines antes de desenhá-las
            glRotatef(anguloCabineBalanço, 0.0f, 0.0f, 1.0f);

            glRotatef(-angulo, 0.0f, 0.0f, 1.0f);
            glRotatef(-anguloRoda, 0, 0, 1); // Mantém as cabines na vertical

            // Desenha uma haste que conecta a cabine aos aros
            desenhaEixoCabines();           
        
            switch(i) {
                case 0: desenhaCabine(0.0f, 1.0f, 1.0f); break; // ciano
                case 1: desenhaCabine(0.0f, 1.0f, 0.0f); break; // verde
                case 2: desenhaCabine(0.0f, 0.0f, 1.0f); break; // azul
                case 3: desenhaCabine(1.0f, 1.0f, 0.0f); break; // amarelo
                case 4: desenhaCabine(0.6f, 0.1f, 0.6f); break; // roxo
                case 5: desenhaCabine(1.0f, 0.0f, 1.0f); break; // rosa
                case 6: desenhaCabine(0.0f, 1.0f, 0.0f); break; // verde
                case 7: desenhaCabine(0.0f, 0.0f, 1.0f); break; // azul
                case 8: desenhaCabine(1.0f, 0.5f, 0.0f); break; // laranja
                case 9: desenhaCabine(1.0f, 1.0f, 0.0f); break; // amarelo
            }
        glPopMatrix();
    }
}

void desenhaPe(GLfloat p) {
    glPushMatrix();
        glTranslatef(0.0f, -2.6f, p); // Posiciona o pé
        glScalef(3.5f, 0.2f, 0.4f); // Faz um paralelepípedo para representar o pé
        glutSolidCube(1.0);
    glPopMatrix();
}

void desenhaColunasBase(GLfloat rot1, GLfloat rot2, GLfloat transl1){
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, transl1);  // Translada para o lado esquerdo e para baixo
        glRotatef(rot1, 1.0f, 0.0f, 0.0f);  // Rotação 1
        glRotatef(rot2, 0.0f, 1.0f, 0.0f);  // Rotacão 2
        
        GLUquadric* quadricaBase1 = gluNewQuadric();
        gluCylinder(quadricaBase1, 0.1, 0.1, 3.0, 20, 10);  // Cilindro com altura de 3.0
        gluDeleteQuadric(quadricaBase1);
    glPopMatrix();
}

void desenhaBase() {
    glColor3f(0.5f, 0.5f, 0.5f);  // Cor para a base
    desenhaPe(0.75);    // Pé direito
    desenhaPe(-0.75);   // Pé esquerdo

    // Base frontal
    desenhaColunasBase(80.0, 30.0, 0.3);    // Desenha o primeiro cilindro (perna da base)
    desenhaColunasBase(80.0, -30.0, 0.3);   // Desenha o segundo cilindro (perna da base)
    
    // Base traseira
    desenhaColunasBase(100.0, 30.0, -0.3);  // Desenha o primeiro cilindro (perna da base)
    desenhaColunasBase(100.0, -30.0, -0.3); // Desenha o segundo cilindro (perna da base)
}