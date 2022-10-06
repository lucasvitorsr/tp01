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
        cout << "CONTA " << ID << " JA EXISTENTE" << endl; 
    }
    else{
        caixasDeEntrada->insere(ID);
        cout << "CONTA " << ID << " CADASTRADA" << endl;
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