#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "listar.h"
#include "estruturas.h"

string quebraString(string str,Lista listaPorInsercao);

bool listarInsercao(int argc, args argv){

	setlocale(LC_ALL,"pt_BR"); 


	// verifica se a função chamada é listar
	if(strcmp(argv[1], "-li")){


		return false;	
	} 

	

	Lista listaPorInsercao = LIS_Criar();
	string linha;
	string horaInsercao;
	//char* horaInsercao = new char[14];	//14 é o tamanho da string hora: AAAAMMDDHHMMSS
	fstream basedebuscas;

	basedebuscas.open("bancodedados.txt",ios::in);

	
	if(basedebuscas.is_open()){
	
		while(!basedebuscas.eof()){
			getline(basedebuscas,linha);

			horaInsercao = quebraString(linha,listaPorInsercao);


			//int hora = atoi(horaInsercao) atoi converte string para int

			
			
		}
	}
	cout << "Arquivos contidos na base de buscas:" << endl;
	LIS_Imprimir(listaPorInsercao);

	return true;

}

string quebraString(string str,Lista listaPorInsercao){

	char* linha = new char[str.length()];

	strcpy(linha,str.c_str());
	
	char* auxNome;
	char* auxDataHora;

	auxNome = strtok(linha,";");
	auxDataHora = strtok(NULL,";");

	string nome(auxNome);
	string dataHora(auxDataHora);

	LIS_InserirFim(listaPorInsercao,str,nome,dataHora);


	/*
	//const char * linha = str.c_str(); //transforma str em const char*

	
	char* nome;
	char* hora;
	//strtok quebra string através dos delimitadores
	nome = strtok(linha,";");
	//tem que colocar NULL para continuar do fim do primeiro token
	//hora = strtok(NULL,";");

	string s(c);*/

	return nome;
}

