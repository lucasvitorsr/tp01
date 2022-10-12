/*
 *
 * @file ListaEmail.hpp
 * @brief  Classe que representa uma lista de emails
 * @author Lucas Vitor da Silva Ramos
 * @version 1.0
 * @date 2022-10-10
 * @copyright Lucas Vitor da Silva Ramos
 *
*/

#ifndef LISTAEMAIL_H
#define LISTAEMAIL_H

#include "Email.hpp"

#include <iostream>
#include <string>

using namespace std;


/*
 * @brief  Classe que representa uma lista de emails
*/
class ListaEmail {
    public:

        /*
         * @brief  Construtor da classe
        */
        ListaEmail();

        /*
         * @brief  Destrutor da classe
        */
        ~ListaEmail();

        /*
         * @brief  Insere um email na lista
         * @param  mensagem Mensagem do email
         * @param  prioridade Prioridade do email
        */
        void insere(string mensagem, int prioridade);

        /*
         * @brief  Remove um email da lista
        */
        void remove();

        /*
         * @brief  Imprime o primeiro email da lista
        */
        void imprime();

        /*
         * @brief  Limpa a lista
        */
        void limpa();

    private:
        int tamanho;
        Email* primeiro;
        Email* ultimo;
};

#endif