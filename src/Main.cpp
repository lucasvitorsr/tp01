#include <iostream>
#include <string>
#include <fstream>

#include "ListaCaixaDeEntrada.hpp"
#include "memlog.hpp"
#include "msgassert.h"

using namespace std;

/*
    * Funcao: remove
    * Descricao: Remove um elemento da lista de caixas de entrada
    * Entrada: um ponteiro para o elemento a ser removido
*/
void remove(ListaCaixaDeEntrada* caixasDeEntrada, int ID) {
    if(caixasDeEntrada->remove(ID)) {
        cout << "CONTA " << ID << " REMOVIDA" << endl;
    }
    else{
        cout << "CONTA " << ID << " NAO EXISTE" << endl;
    }
}


/*
    * Funcao: cadastras
    * Descricao: Cria uma nova caixa de entrada
    * Entrada: um ponteiro para a lista de caixas de entrada e o ID da nova caixa de entrada
*/
void cadastra(ListaCaixaDeEntrada* caixasDeEntrada, int ID) {
    if(caixasDeEntrada->existeId(ID)){
        cout << "ERRO: CONTA " << ID << " JA EXISTENTE" << endl; 
    }
    else{
        caixasDeEntrada->insere(ID);
        cout << "OK: CONTA " << ID << " CADASTRADA" << endl;
    }
}

/*
    * Funcao: entrega
    * Descricao: Envia uma mensagem para uma caixa de entrada
    * Entrada: um ponteiro para a lista de caixas de entrada, o ID da caixa de entrada e a mensagem a ser enviada
*/
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

/*
    * Funcao: consulta
    * Descricao: Consulta a caixa de entrada de um usuario
    * Entrada: um ponteiro para a lista de caixas de entrada e o ID da caixa de entrada a ser consultada
*/
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

/*
    * Funcao: lerComando
    * Descricao: Le um comando do arquivo de entrada e chama a função correspondente
    * Entrada: Nome do arquivo de entrada e um ponteiro para a lista de caixas de entrada
*/
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
                erroAssert(prioridade >= 0 && prioridade <= 9, "Prioridade invalida");
                
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
                
            else{
                erroAssert(false, "Comando invalido");
            }
        }
    }
    else{
         erroAssert(false, "Arquivo nao encontrado");
    }
}

/*
    * Funcao: main
    * Descricao: Funcao principal do programa
    * Entrada: Nome do arquivo de entrada
*/
int main(int argc, char *argv[]) {

    char* nomeLog = argv[2];
    iniciaMemLog(nomeLog);

    ListaCaixaDeEntrada* caixasDeEntrada = new ListaCaixaDeEntrada();
    lercomando(caixasDeEntrada, argv[1]);
    delete caixasDeEntrada;

    return finalizaMemLog();
}