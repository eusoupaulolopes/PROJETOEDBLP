#ifndef _FUNCAO_INSERIR_
#define _FUNCAO_INSERIR_

#include <fstream>
#include <iostream>
typedef char** args;

using namespace std;



bool atualiza(char* base, char* nomeArquivo);
char* horaDataInsercao();
bool copiarArquivoParaPasta(char* arquivo);
bool fazAtualizacao(char * base, char * nomeArquivo);
bool apenasInsere(char * base, char * nomeArquivo, int argc, int posicao);
bool inserir(int argc, args argv);

#endif