#include "ListaEmail.hpp"

ListaEmail::ListaEmail() {
    primeiro = new Email();
    ultimo = primeiro;
}

void ListaEmail::insere(string mensagem, int prioridade) {
    Email* aux = primeiro;
    while(aux->prox != NULL && aux->prox->prioridade >= prioridade) {
        aux = aux->prox;
    }
    
    Email *nova = new Email(mensagem, prioridade);
    nova->prox = aux->prox;
    aux->prox = nova;
    tamanho++;
}

void ListaEmail::remove() {
    if (tamanho == 0)
        cout << "CAIXA DE ENTRADA VAZIA" << endl;
    else {
        Email *p;
        p = primeiro->prox;
        primeiro->prox = p->prox;
        tamanho--;
        cout << p->mensagem << endl;
        delete p;
        if(primeiro->prox == NULL)
            ultimo = primeiro;
    }
}

void ListaEmail::imprime() {
    Email *p = primeiro->prox;
    while(p != NULL) {
        cout << p->mensagem << " " << p->prioridade << endl;
        p = p->prox;
    }
}

void ListaEmail::limpa() {
    Email *p;

    p = primeiro->prox;
    while (p != NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

ListaEmail::~ListaEmail() {
    limpa();
    delete primeiro;
}