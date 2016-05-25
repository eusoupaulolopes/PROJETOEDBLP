#include <iostream>
#include <cstring>
#include <fstream>
#include "estruturas.h"
#include "remover.h"

using namespace std;


bool remover(int argc, args argv){
	

	// verifica se a função chamada é remover
	if(strcmp(argv[1], "-r")){

		return false;	
	} 


	for(int i=2; i < argc; i++){
		if(remocao(argv[i]))
			cout <<"Arquivo \"" << argv[i] << "\" removido da base de buscas." << endl;
		else
			cout <<"Arquivo \"" << argv[i] << "\" não estava na base de buscas." << endl;

	}

	return true;

}

bool removeArquivo(char* arquivo){
	
	int tamNome = strlen(arquivo);
	char caminho[6+tamNome];
	strcpy(caminho, "banco/");
	strcat(caminho, arquivo);	

	//remove retorna 0 quando remove com sucesso
	if(remove(caminho) == 0){

		return true;
	}
	return false;
}

bool remocao(char* nomedoarquivo){
	
	Lista listaLog = LIS_Criar();
	string linhaLog;
	string prefixo = nomedoarquivo;
	bool verificaExistenciaArquivo = false;


	fstream arquivoLog;
	arquivoLog.open("bancodedados.txt",ios::in);


	if(arquivoLog.is_open()){
		
		//Construir a lista com cada nó sendo uma string do indice do arquivo referenciado
		while(!arquivoLog.eof()){
			getline(arquivoLog,linhaLog);
			//O que não for igual ao arquivo que se deseja remover
			//copia os indices de arquivos do arquivo de Log para a listaLog
			if(linhaLog.substr(0,prefixo.size()) != nomedoarquivo){
				
				LIS_InserirFim(listaLog,linhaLog);
			}
			else{ //Senao, nao adciona na lista e remove
				//bool removeu = removeArquivo(nomedoarquivo);
				//cout << "valor de removeu: " << removeu << endl;
				if(removeArquivo(nomedoarquivo)){
					verificaExistenciaArquivo = true;
				}
			}
		}

	}

	arquivoLog.close();

	if(verificaExistenciaArquivo){

		remove("bancodedados.txt");
		fstream novobanco ("bancodedados.txt" , ios::out | ios::app);

	    for(No i = listaLog->cabeca; i != listaLog->cauda; i = i->proximo)
	    {
	        if(i != listaLog->cabeca)
	        	novobanco << i->conteudo;
	    }
	    
	    novobanco.close();
	    return true;
	}
	else{
		return false;
	}

}




