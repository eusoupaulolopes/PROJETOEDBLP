#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "inserir.h"

#include <ctime>


using namespace std;

bool inserir(int argc, args argv){
	setlocale(LC_ALL,"pt_BR"); 
	bool validou = false;


	// verifica se a função chamada é inserir
	if(strcmp(argv[1], "-i")){
		std::cout << "não foi possivel inserir no arquivo" << std::endl;
		std::cout << argv[1] << std::endl;
		return false;	
	} 
	
	char * banco = "bancodedados.txt";
	fstream file (banco , ios::out | ios::app); // faz abrir sempre no fim do arquivo
	
	std::time_t nomequetala = std::time(0);
    
	if(file.is_open()){
		for (int i = 2; i < argc; i++){
			validou = copiarArquivo(argv[i]); // TODO					
			if(validou){				
				if(!atualiza(banco, argv[i])){					
					// Aqui vai o teste de atualizar ou inserir no bancodedados.txt..
					file << argv[i] << ";" << nomequetala << "\n";	
				}
			}else{
				std::cout << (std::string) "Não foi encontrado arquivo: " + argv[i] << std::endl;
			}
		}

		file.close();
		return true;
	}else{
		std::cout << "Foram encontrado falhas na inserção do arquivo" << std::endl;
	}
	return false;
}

/*
@TODO melhorar a como pego o caminho do arquivo. fazendo atualizações
*/
bool atualiza(char * banco, char * arquivinho){
	int contador = 0;
	bool valida = false;
	std::string prefixo = arquivinho;
	std::string linha;
	fstream arquivo;
	arquivo.open(banco);
	//std::time_t mininomequetala = std::time(0);	
	while(arquivo >> linha){
		contador++;	
		if (linha.substr(0, prefixo.size()) == arquivinho){
			
			valida = true;
		}
	}
	/* devemos trabalhar aqui
	if(valida){ 
		arquivo.close();
		arquivo.open(banco);
		std::string *lista = new std::string[contador];
		int i = 0;
		while(!arquivo.eof()){
			cout << "vendo" << linha << endl;
			getline(arquivo, linha);
			
			if (linha.substr(0, prefixo.size()) != arquivinho){
				cout << "inserindo linha" << endl;				
				lista[i] = linha;

			}
			i++;
		}
		for (int i = 0; i < contador; i++){
			cout << lista[i] << endl;
		}
		return true;
	}
	return false;
	*/
}

bool copiarArquivo(char* arquivo){
	char caminho[50];
	strcpy(caminho, "banco/");
	strcat(caminho, arquivo);
	
	ifstream origem (arquivo, fstream::binary);

	if(origem){
		
		ofstream destino (caminho, fstream::trunc|fstream::binary);
		destino << origem.rdbuf ();
		return true;
	}
	
	return false;
	
}

