#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "inserir.h"
#include <ctime>

 

using namespace std;

bool inserir(int argc, args argv){
	setlocale(LC_ALL,"pt_BR"); 


	// verifica se a função chamada é inserir
	char* val = "-i";
	if(strcmp(argv[1], val)){
		std::cout << "não foi possivel inserir no arquivo" << std::endl;
		std::cout << argv[1] << std::endl;
		return false;	
	} 


	ofstream file ("bancodedados.txt" , ios::out | ios::app);
	
	std::time_t nomequetala = std::time(0);
    
	if(file.is_open()){

		file << argv[2] << ";" << nomequetala << "\n";
		file.close();
		copiarArquivo(argv); // TODO
		return true;
	}else{
		std::cout << "não foi possivel inserir no arquivo" << std::endl;

	}
	return false;

}

/*
@TODO melhorar a como pego o caminho do arquivo.
*/

bool copiarArquivo(args argv){
	char caminho[50];
	strcpy(caminho, "banco/");
	strcat(caminho, argv[2]);
	
	ifstream origem (argv[2], fstream::binary);
	ofstream destino (caminho, fstream::trunc|fstream::binary);
	destino << origem.rdbuf ();
	return true;
}
