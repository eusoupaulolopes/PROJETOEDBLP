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
						cout << ">>> Abrindo: " << arquivo << endl;
						buscar(argc, argv, arquivo);
						break;						
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

	if (!file.is_open()){
		cout << "Erro na abertura do arquivo" << endl;
		return false;
	}

	std::string linha;
	std::string nulo = "NULO";
	getline(file, linha);
	int tamanho = atoi(linha.c_str());

	for (int i = 2; i < argc; i++){
		cout << " > Procurando por: [" << argv[i] << "]" << endl;
 		Chave chave = TAB_CriarChave(argv[i]);
		int linhaIdeal = Hash(PreHash(chave), tamanho)+2;
		cout << linhaIdeal << endl;
		while(--linhaIdeal){
			getline(file,linha); // para chegar na linha correta da TAD
		}
		
		std::size_t foundedWord = linha.find(argv[i]);                
		std::size_t foundedNull = linha.find(nulo);                
	
		while(foundedWord==string::npos){
			if(foundedNull!=string::npos){
				cout << "\t - Não contem a palavra\n" << endl;
				break;
			}
			getline(file, linha);
			foundedWord = linha.find(argv[i]);                
			foundedNull = linha.find(nulo);
			
		}

		if(foundedWord!=string::npos){
			strtok((char*)linha.c_str(),":");		
			char* auxLinhas = strtok(NULL,":");				
			listaLinhas(arquivo, auxLinhas); 
		}
		file.seekg(0);
	}
	file.close();
	
	return true;
}


// quebra o conteudo da TAD em linhas visualizaveis
bool listaLinhas(string arquivo, char * linhas){
	string arquivoAux = arquivo.erase(arquivo.length()-4,4) +".txt";
	char* nlinha = std::strtok(linhas ,"-");
	ifstream arquivoTXT (arquivoAux.c_str(), fstream::binary);

	// Verifica se o arquivo foi aberto corretamente
	if(!arquivoTXT.is_open()){
		return false;
	}

	while(nlinha != NULL){	

		string linhaAux;
		int cont = 0;

		// Para não voltar ao inicio do arquivo e percorrer novamente uso um contador que persiste a posição que encontrou o ultimo termo
		while(atoi(nlinha) != cont){
			getline(arquivoTXT, linhaAux);						
			cont++;
		}

		cout << "\t>>> Encontrado na linha " << nlinha << " :: " << linhaAux << endl;
		nlinha = strtok(NULL,"-");			
	}

	arquivoTXT.close();	
	return true;			
	


}