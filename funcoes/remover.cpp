#include <iostream>
#include <cstring>
#include <fstream>
#include "estruturas.h"
#include "remover.h"

using namespace std;


bool remover(int argc, args argv){
	

	// verifica se a função chamada é remover
	if(strcmp(argv[1], "-r")){
		std::cout << "Não é a mamãe!" << std::endl;
		std::cout << argv[1] << std::endl;
		return false;	
	} 


	for(int i=2; i < argc; i++){
		if(buscaLog(argv[i]))
			cout << argv[i]	<< " foi encontrado" << endl;

	}

	return true;

}

bool buscaLog(char* nomedoarquivo){
	
	Lista listaLog = LIS_Criar();
	string linhaLog;
	string prefixo = nomedoarquivo;
	bool verificaExistenciaArquivo;


	fstream arquivoLog;
	arquivoLog.open("bancodedados.txt",ios::in);


	if(arquivoLog.is_open()){

		
		//Construir a lista com cada nó sendo uma string do indice do arquivo referenciado
		while(!arquivoLog.eof()){
			getline(arquivoLog,linhaLog);
			//copia os indices de arquivos diferentes de arquivinho para a lista de indices
			if(linhaLog.substr(0,prefixo.size()) != nomedoarquivo){
				cout << "Coloca na lista!" << endl;
			}
			else{
				cout << "nao coloca na lista, pois vai ser removido" << endl;
			}



/*
			if(linhaLog.substr(0, prefixo.size()) != nomedoarquivo){
				LIS_InserirFim(listaLog,linhaLog);
			}
			else{
				verificaExistenciaArquivo = true;
				
				cout << "Arquivo " << nomedoarquivo << " foi removido com sucesso!" <<endl;
				break;
			}*/
		}
		arquivoLog.close();
		return true;
	}

	return false;


}




