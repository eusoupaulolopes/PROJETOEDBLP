#include "buscar.h"
#include "estruturas.h"
#include <cstring>
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>

using namespace std;

bool Ler_Buscas(int argc, args argv){

	if(!strcmp(argv[1], "-bAND")){
		return buscaBAND(argc, argv);
	}else if (!strcmp(argv[1], "-bOR")){
		return buscaBOR(argc, argv);
	}else{
		return false;
	}
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

bool buscaBAND(int argc, args argv){
	
	setlocale(LC_ALL,"pt_BR"); 
	char * banco = (char *) "bancodedados";
	ifstream file;
	file.open(banco);
	if (file.is_open()){
		std::string linha;
		while(!file.eof()){
			getline(file, linha);
			std::string arquivo = "banco/";
			if(linha != "\0"){
				for (int j = 0; j < (int)linha.size(); j++){
					if(linha[j] == 59){ // o primeiro ; da linha		
						arquivo = arquivo.erase(arquivo.length()-4,4) +".dat";
						buscar(argc, argv, arquivo);						
					}
					arquivo+=linha[j];
				}
			}
		}	
	file.close();
	}
	return true;
}

bool buscaBOR(int argc, args argv){
	//getline(file, linha);		
	
	return true;
}


bool buscar(int argc, args argv, std::string arquivo){
	ifstream file (arquivo, fstream::binary);
	std::string linha;
	std::string nulo = "NULO";
	if (file.is_open()){
		getline(file, linha);
		int tamanho = atoi(linha.c_str());	
		for (int i = 2; i < argc; i++){
			cout << "Procurando por: [" << argv[i] << "] em " << arquivo << endl;
 			Chave chave = TAB_CriarChave(argv[i]);
			int linhaIdeal = Hash(PreHash(chave), tamanho)+1;
			while((linhaIdeal)--){
				getline(file, linha);
			}
			std::size_t foundedWord = linha.find(argv[i]);                
			std::size_t foundedNull = linha.find(nulo);                
			while(foundedWord==string::npos){
				if(foundedNull==string::npos){
					cout << "\t - Não contem a palavra\n" << endl;
					break;
				}
				getline(file, linha);
				foundedWord = linha.find(argv[i]);                
				foundedNull = linha.find(nulo);
				tamanho++;
			}
			if(foundedWord!=string::npos){
				cout << "\t - Contem a palavra segundo a tabela: [" << linha << "]" << endl;
			}
		}
	
		file.close();
	}


/*
	while(!file.eof()){
			
			std::string arquivo = "banco/";
			if(linha != "\0"){
				for (int j = 0; j < (int)linha.size(); j++){
					if(linha[j] == 59){ // o primeiro ; da linha		
					}
					arquivo+=linha[j];
				}
			}
		}
*/
	return true;
}