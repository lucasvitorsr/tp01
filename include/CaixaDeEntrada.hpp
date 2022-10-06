#ifndef CAIXADEENTRADA_H
#define CAIXADEENTRADA_H

#include <cstddef>

class CaixaDeEntrada {
        
    private:
        int ID;
        CaixaDeEntrada *prox;

    public:
        CaixaDeEntrada();
        ~CaixaDeEntrada();
        CaixaDeEntrada(int _ID);

        int getId();

    friend class ListaCaixaDeEntrada;
};

#endif