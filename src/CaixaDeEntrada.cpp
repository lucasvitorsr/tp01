#include "CaixaDeEntrada.hpp"

CaixaDeEntrada::CaixaDeEntrada() {
    ID = -1;
    prox = NULL;
}

CaixaDeEntrada::CaixaDeEntrada(int _ID) : ID(_ID) {}

CaixaDeEntrada::~CaixaDeEntrada() {}

int CaixaDeEntrada::getId() {return ID;}
