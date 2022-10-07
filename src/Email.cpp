#include "Email.hpp"

Email::Email() {
    mensagem = "";
    prioridade = -1;
    prox = NULL;
}

Email::Email(string _mensagem, int _prioridade) : mensagem(_mensagem), prioridade(_prioridade) {
    prox = NULL;
}

Email::~Email() {}

string Email::getMensagem() {return mensagem;}

int Email::getPrioridade() {return prioridade;}
