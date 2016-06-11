
#include "estruturas.h"
#include "listar.h"
#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>



using namespace std;



string quebraLinha(string linhaStr, int opcao){

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
	
	switch (opcao){
		case 1:
			return nome;
			break;
		case 3:
			return qtdePalavras;
			break;
		case 2:
			return dataHora;
			break;
		default:
			break;
	}
	return dataHora;
}


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
	if(strcmp(argv[1], "-li")  || (argc != 2)){
		return false;	
	} 

	

	Lista listaPorInsercao = LIS_Criar();
	string linha;
	
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

	LIS_Ordenar(listaPorInsercao,insercao);

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
	if(strcmp(argv[1], "-la") || (argc != 2)){
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
	if(strcmp(argv[1], "-lt")  || (argc != 2)){
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


	LIS_Ordenar(listaQtdePalavras,quantidadePalavras);

	cout << "Arquivos contidos na base de buscas:" << endl;	
	
	LIS_Imprimir(listaQtdePalavras);

	return true;

}


