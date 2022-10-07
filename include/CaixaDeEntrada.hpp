#ifndef CAIXADEENTRADA_H
#define CAIXADEENTRADA_H

#include "ListaEmail.hpp"

#include <cstddef>

class CaixaDeEntrada {
        
    private:
        int ID;
        CaixaDeEntrada *prox;

    public:
        CaixaDeEntrada();
        ~CaixaDeEntrada();
        CaixaDeEntrada(int _ID);
        void recebe(int prioridade, string mensagem);
        void imprime();

        int getId();

        ListaEmail *listaEmail;

    friend class ListaCaixaDeEntrada;
};

#endif