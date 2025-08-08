#include "globals.hpp"

// Variáveis globais
float anguloRoda = 0.0f;
bool movimentoAtivo = true; // Determina se a Roda gigante está girando ou não
float anguloCabineBalanço = 0.0f;  // Controla o balanço das cabines
float velocidadeBalanço = 0.2f;  // Controla a velocidade de oscilação das cabines
bool direcaoBalanço = true;  // Alterna a direção do balanço

float anguloAzimute = 0.0f;  // Ângulo para mover a câmera ao redor da roda (horizontal)
float anguloElevação = 0.0f;  // Ângulo para inclinar a câmera para cima/baixo (vertical)
float distanciaCamera = 6.0f;  // Distância da câmera para a roda

float luzAmbiente[] = {0.2f, 0.2f, 0.2f, 1.0f};
float luzDifusa[]   = {0.8f, 0.8f, 0.8f, 1.0f};
float posicaoLuz[]  = {5.0f, 5.0f, 10.0f, 1.0f};
