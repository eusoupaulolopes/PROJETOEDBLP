#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "estruturas.h"
#include "listar.h"


using namespace std;

void quebraLinha(string linhaStr, Lista lista){

	char* linha = new char[linhaStr.length()];

	strcpy(linha,linhaStr.c_str());
	
	char* auxNome;
	char* auxDataHora;
	char* auxqtdePalavras;

	auxNome = strtok(linha,";");
	auxDataHora = strtok(NULL,";");
	auxqtdePalavras = strtok(NULL," ;");

	string nome(auxNome);
	string dataHora(auxDataHora);
	string qtdePalavras(auxqtdePalavras);

	LIS_InserirFim(lista,linhaStr,nome,dataHora,qtdePalavras);
	
}

bool listarInsercao(int argc, args argv){

	setlocale(LC_ALL,"pt_BR"); 


	// verifica se a função chamada é listar
	if(strcmp(argv[1], "-li")){
		return false;	
	} 

	

	Lista listaPorInsercao = LIS_Criar();
	string linha;
	//string horaInsercao;
	//char* horaInsercao = new char[14];	//14 é o tamanho da string hora: AAAAMMDDHHMMSS
	
	fstream basedebuscas;
	basedebuscas.open("bancodedados",ios::in);

	
	if(basedebuscas.is_open()){
	
		while(!basedebuscas.eof()){
			getline(basedebuscas,linha);
			if(linha != "\0")
				quebraLinha(linha,listaPorInsercao);

			
		}
	}else{
		cout << "\tNão foi possivel encontrar a base de buscas, ou estava vazia!" << endl;
	}

	cout << "Arquivos contidos na base de buscas:" << endl;	
	LIS_Imprimir(listaPorInsercao);



	return true;

}



/*
 Função que lista os arquivos da base de busca em ordem alfabética
 @param argc - tamanho do vetor de argumentos
 @param argv - vetor de argumentos do terminal
 @return true se listou com sucesso, false caso a opção escolhida não seja -la
*/
bool listarAlfabeticamente(int argc, args argv){
	setlocale(LC_ALL,"pt_BR"); 


	// verifica se a função chamada é listar
	if(strcmp(argv[1], "-la")){
		return false;	
	} 


	Lista listaAlfabetica = LIS_Criar();
	string linha;

	fstream basedebuscas;
	basedebuscas.open("bancodedados",ios::in);

	
	if(basedebuscas.is_open()){
	
		while(!basedebuscas.eof()){
			
			getline(basedebuscas,linha);

			if(linha != "\0")
				quebraLinha(linha,listaAlfabetica);			
		}

	}else{
		cout << "\tNão foi possivel encontrar a base de buscas, ou estava vazia!" << endl;
	}

	LIS_Ordenar(listaAlfabetica,alfabeticamente);

	cout << "Arquivos contidos na base de buscas:" << endl;	
	
	LIS_Imprimir(listaAlfabetica);



	return true;

}


/*
 Função que lista os arquivos da base de busca em ordem descrescente de quantidade de palavras do conteudo
 @param argc - tamanho do vetor de argumentos
 @param argv - vetor de argumentos do terminal
 @return true se listou com sucesso, false caso a opção escolhida não seja -lt
*/
bool listarQtdePalavras(int argc, args argv){
	setlocale(LC_ALL,"pt_BR"); 

	// verifica se a função chamada é listar
	if(strcmp(argv[1], "-lt")){
		return false;	
	} 


	Lista listaQtdePalavras = LIS_Criar();
	string linha;

	fstream basedebuscas;
	basedebuscas.open("bancodedados",ios::in);

	
	if(basedebuscas.is_open()){
	
		while(!basedebuscas.eof()){
			
			getline(basedebuscas,linha);

			if(linha != "\0")
				quebraLinha(linha,listaQtdePalavras);
		}

	}else{
		cout << "\tNão foi possivel encontrar a base de buscas, ou estava vazia!" << endl;
	}

	LIS_Imprimir(listaQtdePalavras);


	LIS_Ordenar(listaQtdePalavras,quantidadePalavras);

	cout << "Arquivos contidos na base de buscas:" << endl;	
	
	LIS_Imprimir(listaQtdePalavras);

	return true;

}


