#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "listar.h"
#include "estruturas.h"


using namespace std;

void quebraString(string str,Lista listaPorInsercao);


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

	basedebuscas.open("bancodedados",ios::in);

	
	if(basedebuscas.is_open()){
	
		while(!basedebuscas.eof()){
			getline(basedebuscas,linha);
			if(linha != "\0")
				quebraString(linha,listaPorInsercao);

			
		}
	}else{
		cout << "\tNão foi possivel encontrar a base de buscas, ou estava vazia!" << endl;
	}

	cout << "Arquivos contidos na base de buscas:" << endl;	
	LIS_Imprimir(listaPorInsercao);



	return true;

}

void quebraString(string str, Lista listaPorInsercao){

	char* linha = new char[str.length()];

	strcpy(linha,str.c_str());
	
	char* auxNome;
	char* auxDataHora;

	auxNome = strtok(linha,";");
	auxDataHora = strtok(NULL,";");

	string nome(auxNome);
	string dataHora(auxDataHora);

	LIS_InserirFim2(listaPorInsercao,str,nome,dataHora);
	
}

