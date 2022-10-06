#ifndef LISTACAIXADEENTRADA_H
#define LISTACAIXADEENTRADA_H

#include "CaixaDeEntrada.hpp"

#include <iostream>

#define TipoItem int

using namespace std;

class ListaCaixaDeEntrada {

    public: 
        ListaCaixaDeEntrada();
        ~ListaCaixaDeEntrada();

        void insere(TipoItem ID);
        bool remove(int ID);
        bool existeId(int ID);
        void limpa();

    private:
        int tamanho;
        CaixaDeEntrada* primeiro;
        CaixaDeEntrada* ultimo;
        CaixaDeEntrada* posiciona(int ID);
};

#endif