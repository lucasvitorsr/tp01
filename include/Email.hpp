#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <cstddef>

using namespace std;

class Email {

    private:
        string mensagem;
        int prioridade;
        Email *prox;

    public:
        Email();
        ~Email();
        Email(string _mensagem, int _prioridade);

        string getMensagem();
        int getPrioridade();

    friend class ListaEmail;
};

#endif