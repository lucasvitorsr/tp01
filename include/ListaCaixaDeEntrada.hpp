#ifndef LISTACAIXADEENTRADA_H
#define LISTACAIXADEENTRADA_H

#include "CaixaDeEntrada.hpp"

#include <iostream>

using namespace std;

class ListaCaixaDeEntrada {

    public: 
        ListaCaixaDeEntrada();
        ~ListaCaixaDeEntrada();

        void insere(int ID);
        bool remove(int ID);
        bool existeId(int ID);
        void limpa();
        CaixaDeEntrada* posiciona(int ID);

    private:
        int tamanho;
        CaixaDeEntrada* primeiro;
        CaixaDeEntrada* ultimo;
};

#endif