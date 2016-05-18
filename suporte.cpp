#include <iostream>
#include <cstdio>
#include <cstring>
#include "funcoes/inserir.h"
#include "suporte.h"

//Função roda o vetor de ponteiros de funções
bool rodarOpcoes(opcao *ops, int tamanhoOps,int argc, args argv){

	for(int i = 0; i< tamanhoOps; i++){
		opcao aux = ops[i];
		if(aux(argc,argv)){
			return true; //executou uma opção
		}
	}
	return false; //não executou

}

//opcoesGerenciamento é um vetor de ponteiros de função do Gerenciamento de Busca
bool opcaoGerenciamento(opcao *opcoesGerenciamento, int tamanhoOpGerenciamento,int argc, args argv ){

	if(rodarOpcoes(opcoesGerenciamento,tamanhoOpGerenciamento,argc,argv)){
		return true;
	}
	return false;
}

//opcoesBusca é um vetor de ponteiros de funço do Modo Busca
bool opcaoModoBusca(opcao *opcoesBusca, int tamanhoOpBusca,int argc, args argv){
	
	if(rodarOpcoes(opcoesBusca,tamanhoOpBusca,argc,argv)){
		return true;
	}
	return false;
}

