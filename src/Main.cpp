#include <iostream>
#include <string>
#include <fstream>

#include "ListaCaixaDeEntrada.hpp"

using namespace std;

void remove(ListaCaixaDeEntrada* caixasDeEntrada, int ID) {
    if(caixasDeEntrada->remove(ID)) {
        cout << "CONTA " << ID << " REMOVIDA" << endl;
    }
    else{
        cout << "CONTA " << ID << " NAO EXISTE" << endl;
    }
}

void cadastra(ListaCaixaDeEntrada* caixasDeEntrada, int ID) {
    if(caixasDeEntrada->existeId(ID)){
        cout << "ERRO: CONTA " << ID << " JA EXISTENTE" << endl; 
    }
    else{
        caixasDeEntrada->insere(ID);
        cout << "OK: CONTA " << ID << " CADASTRADA" << endl;
    }
}

void entrega(int ID, string mensagem, int prioridade, ListaCaixaDeEntrada* caixasDeEntrada) {
    CaixaDeEntrada* destinatario = caixasDeEntrada->posiciona(ID);
    if(destinatario != NULL) {
        destinatario->recebe(prioridade, mensagem);
        cout << "OK: MENSAGEM PARA " << ID << " ENTREGUE" << endl;
    }
    else{
        cout << "CONTA " << ID << " NAO EXISTE" << endl;
    }
}

void consulta(int ID, ListaCaixaDeEntrada* caixasDeEntrada){
    CaixaDeEntrada* consultado = caixasDeEntrada->posiciona(ID);
    if(consultado != NULL){
        cout << "CONSULTA " << ID << ": ";
        consultado->imprime();
    }
    else{
        cout << "ERRO: CONTA " << ID << " NAO EXISTE" << endl;
    }
}

void lercomando(ListaCaixaDeEntrada* caixasDeEntrada, string nomeArquivo) {
    ifstream arquivo (nomeArquivo);
    if(arquivo){
        string comando;
        while(arquivo >> comando) {
            int ID;
            arquivo >> ID;

            if(comando == "CADASTRA") {
                cadastra(caixasDeEntrada, ID);
            }
            else if(comando == "REMOVE") {
                remove(caixasDeEntrada, ID);
            }
            else if(comando == "ENTREGA") {
                int prioridade;
                arquivo >> prioridade;
                
                string mensagem, aux;
                arquivo >> aux;
                while(aux != "FIM") {
                    mensagem += aux + " ";
                    arquivo >> aux;
                }

                entrega(ID, mensagem, prioridade, caixasDeEntrada);
            }
            else if(comando == "CONSULTA"){
                consulta(ID, caixasDeEntrada);
            }
        }
    }
    else{ // excecao
         
    }
}

int main(int argc, char *argv[]) {
    ListaCaixaDeEntrada* caixasDeEntrada = new ListaCaixaDeEntrada();

    lercomando(caixasDeEntrada, argv[1]);

    delete caixasDeEntrada;
    return 0;
}