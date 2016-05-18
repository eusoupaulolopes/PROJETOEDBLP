#ifndef _FUNCOES_COMUNS_
#define _FUNCOES_COMUNS_

//Ponteiro de função para o vetor de ponteiros
typedef bool (*opcao) (int argc, char **argv);

//typedef para vetor de char
typedef char** args;


bool rodarOpcoes(opcao *ops, int tamanhoOps,int argc, args argv);
bool opcaoGerenciamento(opcao *opcoesGerenciamento, int tamanhoOpGerenciamento,int argc, args argv );
bool opcaoModoBusca(opcao *opcoesBusca, int tamanhoOpBusca,int argc, args argv);

#endif