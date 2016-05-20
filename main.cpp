#include <iostream>
#include <cstdio>
#include <cstring>
#include "suporte.h"
#include "funcoes/inserir.h"
#include "funcoes/estruturas.h"

using namespace std;


//Ponteio dessa função está na frente do vetor para que verifique se o numero de argumentos é valido
bool validarArgumentos(int argc, args argv){
	
	bool aux = !(argc==3 || argc == 5);
	if(aux){
		cout << "Número de argumentos inválido!" << endl;
	}
	return aux;

}


int main(int argc, char** argv){


	opcao opcoes[1]; 

	//opcoes[0] = validarArgumentos;
	opcoes[0] = inserir;
	

	/*opcao opcoesBusca[1];
	opcoesBusca[0] = inserir;

	opcao opcoesGerenciamento[1];
	opcoesGerenciamento[0] = inserir;*/


	if(!rodarOpcoes(opcoes,1,argc,argv)){
		cout << "Opção nao reconhecida!" << endl;
	}
	
	return 0;
}
