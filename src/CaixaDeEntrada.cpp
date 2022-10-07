#include "CaixaDeEntrada.hpp"

CaixaDeEntrada::CaixaDeEntrada() {
    listaEmail = new ListaEmail();
    ID = -1;
    prox = NULL;
}

CaixaDeEntrada::CaixaDeEntrada(int _ID) : ID(_ID) {}

CaixaDeEntrada::~CaixaDeEntrada() {delete listaEmail;}

void CaixaDeEntrada::imprime() {listaEmail->remove();}

int CaixaDeEntrada::getId() {return ID;}

void CaixaDeEntrada::recebe(int prioridade, string mensagem) {
    listaEmail->insere(mensagem, prioridade);
}