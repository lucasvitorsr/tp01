/*
 *
 * @file Email.hpp
 * @brief  Classe que representa um email
 * @author Lucas Vitor da Silva Ramos
 * @version 1.0
 * @date 2022-10-10
 * @copyright Lucas Vitor da Silva Ramos
 *
 */

#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <cstddef>

using namespace std;


/*
 * @brief  Classe que representa um email
*/
class Email {

    private:
        string mensagem;
        int prioridade;
        Email *prox;

    public:

        /*
         * @brief  Construtor da classe
        */
        Email();
        
        /*
         * @brief  Destrutor da classe
        */
        ~Email();
        
        /*
         * @brief  Construtor da classe
         * @param  _mensagem Mensagem do email
         * @param  _prioridade Prioridade do email
        */
        Email(string _mensagem, int _prioridade);

        /*
         * @brief  Retorna a mensagem do email
         * @return Mensagem do email
        */
        string getMensagem();
        
        /*
         * @brief  Retorna a prioridade do email
         * @return Prioridade do email
        */
        int getPrioridade();

    friend class ListaEmail;
};

#endif