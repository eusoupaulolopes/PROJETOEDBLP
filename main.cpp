#include <iostream>
#include <cstdio>
#include <cstring>
#include "suporte.h"
#include "funcoes/inserir.h"
#include "funcoes/remover.h"
#include "funcoes/estruturas.h"
#include "funcoes/listar.h"
#include "funcoes/buscar.h"


using namespace std;


//Ponteio dessa função está na frente do vetor para que verifique se o numero de argumentos é valido
bool validarArgumentos(int argc, args argv){
	bool aux = true;
	if (argc == 2){
		if (strcmp(argv[1], "-li") || strcmp(argv[1], "-ta") || strcmp(argv[1], "-la")){
			aux = false;
		}
	}	
	return aux;

}


int main(int argc, char** argv){


	opcao opcoes[7]; 

	//opcoes[0] = validarArgumentos;
	opcoes[0] = inserir;
	opcoes[1] = remover;
	opcoes[2] = listarInsercao;
	opcoes[3] = listarAlfabeticamente;
	opcoes[4] = listarQtdePalavras;
	opcoes[5] = Ler_Buscas;

	if(!rodarOpcoes(opcoes,6,argc,argv)){
		cout << "Opção nao reconhecida!" << endl;
	}
	
	return 0;
}
