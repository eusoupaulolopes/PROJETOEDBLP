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


	ofstream file ("bancodedados.txt" , ios::out | ios::app);
	
	std::time_t nomequetala = std::time(0);
    
	if(file.is_open()){
		for (int i = 2; i < argc; i++){
			validou = copiarArquivo(argv[i]); // TODO
			if(validou){
				// Aqui vai o teste de atualizar ou inserir no bancodedados.txt..
				file << argv[i] << ";" << nomequetala << "\n";	
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
