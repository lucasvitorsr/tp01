/*
 *
 * @file CaixaDeEntrada.hpp
 * @brief  Classe que representa um email
 * @author Lucas Vitor da Silva Ramos
 * @version 1.0
 * @date 2022-10-10
 * @copyright Lucas Vitor da Silva Ramos
 *
 */


#ifndef CAIXADEENTRADA_H
#define CAIXADEENTRADA_H

#include "ListaEmail.hpp"

#include <cstddef>


/*
 * @brief  Classe que representa um email
 */
class CaixaDeEntrada {
        
    private:
        int ID;
        CaixaDeEntrada *prox;

    public:

        /*
         * @brief  Construtor da classe
         */
        CaixaDeEntrada();

        /*
         * @brief  Destrutor da classe
         */
        ~CaixaDeEntrada();

        /*
         * @brief  Construtor da classe
         * @param  _ID ID da caixa de entrada
         */
        CaixaDeEntrada(int _ID);


        /*
         * @brief  Recebe um email e o insere na caixa de entrada
         * @param prioridade Prioridade do email
         * @param mensagem Mensagem do email
         */
        void recebe(int prioridade, string mensagem);

        /*
         * @brief  Imprime o primeiro email da caixa de entrada
         */
        void imprime();

        /*
         * @brief Get Id da caixa de entrada
         * @return Id da caixa de entrada
         */
        int getId();

        ListaEmail *listaEmail;

    friend class ListaCaixaDeEntrada;
};

#endif