#ifndef _LISTA_PARA_BUSCAS_
#define _LISTA_PARA_BUSCAS_

#include <string>
#include "listabusca.h"

typedef char** args;

int gerarTabela(std::string origem);
bool Ler_Buscas(int argc, args argv);
bool buscarNaTabela(int argc, args argv, std::string arquivo, ListaB& listaBusca, string dataHora);
bool buscaPorArquivo(int argc, args argv);
bool buscaBOR(ListaB* lista, int tamanho);
//bool buscaBAND(ListaB* lista, int tamanho, int numerodepalavras);
bool buscaBAND(ListaB* lista, int tamanho, int numerodepalavras, int argc, args argv);
bool listaLinhas(string arquivo, char * linhas,ListaB &listaBusca, char* chave, string dataHora);
int inicioPalavrasBusca(int argc, args argv);
//void opcaoImpressao(ListaB* lista,int iniciopalavras, int tamanho, args argv);
#endif