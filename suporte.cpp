#include <iostream>
#include <cstdio>
#include <cstring>
#include "funcoes/inserir.h"
#include "suporte.h"

using namespace std;


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