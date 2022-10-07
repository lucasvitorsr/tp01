#ifndef LISTAEMAIL_H
#define LISTAEMAIL_H

#include "Email.hpp"

#include <iostream>
#include <string>

using namespace std;

class ListaEmail {
    public:
        ListaEmail();
        ~ListaEmail();

        void insere(string mensagem, int prioridade);
        void remove();
        void imprime();
        void limpa();

    private:
        int tamanho;
        Email* primeiro;
        Email* ultimo;
};

#endif