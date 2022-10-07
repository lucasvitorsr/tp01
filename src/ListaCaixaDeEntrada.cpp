#include "ListaCaixaDeEntrada.hpp"

ListaCaixaDeEntrada::ListaCaixaDeEntrada() {
    primeiro = new CaixaDeEntrada();
    ultimo = primeiro;
}

void ListaCaixaDeEntrada::insere(int ID) {
    CaixaDeEntrada *nova;
    nova = new CaixaDeEntrada();
    nova->ID = ID;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
}

CaixaDeEntrada* ListaCaixaDeEntrada::posiciona(int ID){
    CaixaDeEntrada *p = primeiro;
    while(p->prox != NULL && p->prox->ID != ID) {
        p = p->prox;
    }

    if(ultimo == p && p->ID != ID) {
        return NULL;
    }
    return p;
}

bool ListaCaixaDeEntrada::existeId(int ID) {
    if (tamanho == 0)
        return false;
        // "ERRO: Lista vazia!";

    CaixaDeEntrada *p;
    p = primeiro->prox;
    while (p != NULL) {
        if (p->ID == ID) {
            return true;
        }
        p = p->prox;
    }
    return false;
}

bool ListaCaixaDeEntrada::remove(int ID) {
    CaixaDeEntrada *p = posiciona(ID);
    if(p->prox == NULL){
        return false;
    }

    CaixaDeEntrada *q = p->prox;
    p->prox = q->prox;
    tamanho--;
    delete q;
    if(p->prox == NULL)
        ultimo = p;

    return true;
}

void ListaCaixaDeEntrada::limpa() {
    CaixaDeEntrada *p;

    p = primeiro->prox;
    while (p != NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

ListaCaixaDeEntrada::~ListaCaixaDeEntrada() {
    limpa();
    delete primeiro;
}