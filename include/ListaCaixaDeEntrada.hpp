/*
 *
 * @file ListaCaixaDeEntrada.hpp
 * @brief  Classe que representa um email
 * @author Lucas Vitor da Silva Ramos
 * @version 1.0
 * @date 2022-10-10
 * @copyright Lucas Vitor da Silva Ramos
 *
 */


#ifndef LISTACAIXADEENTRADA_H
#define LISTACAIXADEENTRADA_H

#include "CaixaDeEntrada.hpp"

#include <iostream>

using namespace std;


/*
 * @brief  Classe que representa uma lista de caixas de entrada
 */
class ListaCaixaDeEntrada {

    public: 

        /*
         * @brief  Construtor da classe
        */
        ListaCaixaDeEntrada();

        /*
         * @brief  Destrutor da classe
        */
        ~ListaCaixaDeEntrada();

        /*
         * @brief  Insere uma caixa de entrada na lista
         * @param  nome Nome da caixa de entrada
        */
        void insere(int ID);
        
        /*
         * @brief  Remove uma caixa de entrada da lista
         * @param ID id da caixa de entrada
        */
        bool remove(int ID);

        /*
         * @brief  Confere se a caixa de entrada existe
         * @param ID id da caixa de entrada
         * @return true se a caixa de entrada existe
        */
        bool existeId(int ID);

        /*
         * @brief  Limpa a lista
        */
        void limpa();

        /*
         * @brief  Posiciona o ponteiro na caixa de entrada
         * @param ID id da caixa de entrada
         * @returen CaixaDeEntrada* ponteiro para a caixa de entrada
        */
        CaixaDeEntrada* posiciona(int ID);

    private:
        int tamanho;
        CaixaDeEntrada* primeiro;
        CaixaDeEntrada* ultimo;
};

#endif