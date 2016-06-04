#include "buscar.h"
#include "estruturas.h"
#include <cstring>
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

bool Ler_Base(int argc, args argv){


	if(strcmp(argv[1], "-b")){
	
		return false;	
	}	
	setlocale(LC_ALL,"pt_BR"); 
	char * banco = (char *) "bancodedados";
	ifstream file;
	file.open(banco);
	//char* termo = std::strtok((char *)linha.c_str() ," .,;!?()[]");


	if (file.is_open()){
		std::string linha;
		while(!file.eof()){
			getline(file, linha);
			std::string arquivo = "banco/";
			if(linha != "\0"){
				for (int j = 0; j < linha.size(); j++){
					if(linha[j] == 59){ // o primeiro ; da linha		
					}
					arquivo+=linha[j];
				}
			}
		}
	file.close();
	}

	return true;
}

int gerarTabela(std::string origem){
	Tabela tabela = TAB_CriarTabela(100);
	std::string palavra;
	char * aux = new char[origem.length() +1];
	std::strcpy(aux, origem.c_str());
	ifstream arquivo (aux, fstream::binary);
	
	if (arquivo.is_open()){
		
		std::string linha;
		int contadorLinha = 0;
		int contadorPalavras = 0;
			
		while(!arquivo.eof()){
			contadorLinha++;
			getline(arquivo, linha);
			char* termo = std::strtok((char *)linha.c_str() ," .,;!?()[]");
			
			while(termo != NULL){
				contadorPalavras++;
				Chave chave = TAB_CriarChave(termo);
				Valor valor = TAB_CriarValor(std::to_string(contadorLinha).c_str());
				TAB_Inserir(tabela, chave, valor);
				termo = strtok(NULL," .,;!?()[]");	
			}
		}arquivo.close();

		string arquivotabela = origem.erase(origem.length()-4,4) +".dat";
		char * auxTabela = new char[arquivotabela.length() +1];
		std::strcpy(auxTabela, arquivotabela.c_str());
		
		gerarArquivoTabela(auxTabela, tabela);		
		return contadorPalavras;
	} 	
	return -1;
}
