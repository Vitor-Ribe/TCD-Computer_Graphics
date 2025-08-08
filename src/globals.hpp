// Variáveis globais
#ifndef GLOBALS_H
#define GLOBALS_H

constexpr int WIDTH  = 1000; // largura da janela
constexpr int HEIGHT = 800; // altura da janela

extern float anguloRoda;
extern bool movimentoAtivo;
extern float anguloCabineBalanço;
extern float velocidadeBalanço;
extern bool direcaoBalanço;

extern float anguloAzimute;
extern float anguloElevação;
extern float distanciaCamera;

extern float luzAmbiente[];
extern float luzDifusa[];
extern float posicaoLuz[];


#endif
