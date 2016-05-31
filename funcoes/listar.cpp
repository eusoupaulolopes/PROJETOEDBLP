#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "listar.h"
#include "estruturas.h"

char* quebraString(string str);

bool listarInsercao(int argc, args argv){

	setlocale(LC_ALL,"pt_BR"); 


	// verifica se a função chamada é listar
	if(strcmp(argv[1], "-li") !=0){


		return false;	
	} 

	

	Lista listaPorInsercao = LIS_Criar();
	string linha;
	char* horaInsercao = new char[14];	//14 é o tamanho da string hora: AAAAMMDDHHMMSS
	fstream basedebuscas;

	basedebuscas.open("bancodedados.txt",ios::in);

	cout << "Hello\n" << endl;
	if(basedebuscas.is_open()){

		while(!basedebuscas.eof()){
			getline(basedebuscas,linha);

			horaInsercao = quebraString(linha);

			//int hora = atoi(horaInsercao) atoi converte string para int

			LIS_InserirFim(listaPorInsercao,horaInsercao);
			
		}
	}

	LIS_Imprimir(listaPorInsercao);

	return true;

}

char* quebraString(string str){

	char* linha = new char[str.length()];
	
	//const char * linha = str.c_str(); //transforma str em const char*

	
	char* nome;
	char* hora;
	//strtok quebra string através dos delimitadores
	nome = strtok(linha,";");
	//tem que colocar NULL para continuar do fim do primeiro token
	hora = strtok(NULL,";");

	return hora;
}

