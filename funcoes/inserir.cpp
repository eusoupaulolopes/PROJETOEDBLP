#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "inserir.h"
#include "estruturas.h"

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
	

	char * banco = (char*)"bancodedados.txt";
	fstream file (banco , ios::out | ios::app); // faz abrir sempre no fim do arquivo
	
	

	std::time_t horaArqInserido = std::time(0);
    
	if(file.is_open()){
		


		for (int i = 2; i < argc; i++){
			validou = copiarArquivo(argv[i]); // TODO

			

			if(validou){

				if(!atualiza(banco, argv[i])){					
					// Aqui vai o teste de atualizar ou inserir no bancodedados.txt..
					file << argv[i] << ";" << horaArqInserido << "\n";	
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
bool copiarArquivo(char* arquivo){
	
	int tamNome = strlen(arquivo);

	char caminho[6+tamNome];
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



bool atualiza(char * banco, char * arquivinho){
	


	setlocale(LC_ALL,"pt_BR"); 
	bool verificaIndicesIguais = false;

	Lista indices = LIS_Criar();
	
	
	string prefixo = arquivinho;
	string linha;


	fstream arquivo;
	arquivo.open(banco,ios::in);
	

	//Construir a lista com cada nó sendo uma string do indice do arquivo referenciado
	while(!arquivo.eof()){
		getline(arquivo,linha);
		//copia os indices de arquivos diferentes de arquivinho para a lista de indices
		if(linha.substr(0, prefixo.size()) != arquivinho){
			LIS_InserirFim(indices,linha);
		}
		else{//Se arquivinho for encontrado na base, manda pra lista arquivinho com hora atualizada.
			verificaIndicesIguais = true;
			std::time_t horadeinsercao = std::time(0);
			string hora = (const char*)horadeinsercao;
			string pontoevirgula = ";";
			string linhaatualizada = arquivinho+pontoevirgula+hora;
			//o que tem da posiçao 0 até tamanho da linha, é substituido pelo conteudo de linhaatualizada
			//linha.replace(0,linha.size(),linhaatualizada); 

			if(LIS_InserirFim(indices,linhaatualizada)){
				cout << "Arquivo " << arquivinho << "já estava na base de buscas.\nSeu registro foi atualizado." <<endl;
			}

		}


	}
	//Impressao de teste
	LIS_Imprimir(indices);

	//Apaga o arquivo de log e insere os indices da lista encadeada que contem os indices atualizados em novo log.
	if(verificaIndicesIguais){
		arquivo.clear();
		arquivo.close();

		arquivo.open(banco,ios::out);

	    for(No i = indices->cabeca; i != indices->cauda; i = i->proximo)
	    {
	        if(i != indices->cabeca)
	        	arquivo << i->indiceArquivo << "\n";
	    }
	    arquivo << endl;

	    return true;
	}
	else{
		return false;
	}



    /*
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

	if(valida){

	}
	devemos trabalhar aqui
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



