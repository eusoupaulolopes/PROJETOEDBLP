#include <fstream>
#include <cstring>
#include <locale.h>
#include <iostream>
#include "inserir.h"
#include "estruturas.h"
#include "buscar.h"
#include <ctime>

using namespace std;

bool inserir(int argc, args argv){
	
	setlocale(LC_ALL,"pt_BR"); 
	bool validou = false;
	
	// verifica se a função chamada é inserir
	if(strcmp(argv[1], "-i")){
		
		return false;	
	}

	char * banco = (char*)"bancodedados";
	fstream file (banco , ios::out | ios::app); // faz abrir sempre no fim do arquivo
	
	std::time_t horadeinsercao;
	struct tm * timeinfo;
	std::time(&horadeinsercao);
	char buffer[80];
	timeinfo = localtime(&horadeinsercao);
	strftime(buffer,80,"%Y%m%d%H%M%S", timeinfo);	    
	if(file.is_open()){
		for (int i = 2; i < argc; i++){
			validou = copiarArquivo(argv[i]); // TODO
			
			if(validou){
				int tamNome = strlen(argv[i]);
				char caminho[6+tamNome];
				strcpy(caminho, "banco/");
				strcat(caminho, argv[i]);
				int palavras = gerarTabela(caminho); // Conta as palavras e gera tabela de dispersao
				
				if(!atualiza(banco, argv[i])){					
					// Aqui vai o teste de atualizar ou inserir no bancodedados..
					cout << "Arquivo: " << argv[i] << " inserido na base de buscas." <<endl;					
					if (i != argc-1){
						file << argv[i] << ";" << buffer << ";" << palavras << "\n";
					}else{
						
						file << argv[i] << ";" << buffer << ";" << palavras;

						if(argc == 3){
							file << "\n";
						}
						
					}
					

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

bool copiarArquivo(char* arquivo){
	
	int tamNome = strlen(arquivo);
	char caminho[6+tamNome];
	strcpy(caminho, "banco/");
	strcat(caminho, arquivo);

	gerarTabela(caminho);
	
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
		else{
			verificaIndicesIguais = true;
			
			// humanizando o tempo
			std::time_t horadeinsercao;
			struct tm * timeinfo;
			std::time(&horadeinsercao);
			char buffer[80];
			timeinfo = localtime(&horadeinsercao);
			strftime(buffer,80,"%Y%m%d%H%M%S", timeinfo);

			int tamNome = strlen(arquivinho);
			char caminho[6+tamNome];
			strcpy(caminho, "banco/");
			strcat(caminho, arquivinho);
			
			int palavras = gerarTabela(caminho); // Conta as palavras e gera tabela de dispersao

			string pontoevirgula = ";";
			string linhaatualizada = arquivinho+pontoevirgula+buffer+pontoevirgula+std::to_string(palavras).c_str();
			
			//o que tem da posiçao 0 até tamanho da linha, é substituido pelo conteudo de linhaatualizada
			//linha.replace(0,linha.size(),linhaatualizada); 
			if(LIS_InserirFim(indices,linhaatualizada)){
				cout << "Arquivo " << arquivinho << " já estava na base de buscas.\n\tSeu registro foi atualizado." <<endl;
			}
		}
	}

	//Apaga o arquivo de log e insere os indices da lista encadeada que contem os indices atualizados em novo log.
	if(verificaIndicesIguais){
		arquivo.close();
		remove(banco);
		fstream novobanco (banco , ios::out | ios::app);


	    for(No i = indices->cabeca; i != indices->cauda; i = i->proximo)
	    {
	        if(i != indices->cabeca){
	        	cout << i->conteudo << endl;
	        	if(i->proximo == indices->cauda){
	        		novobanco << i->conteudo;
	        	}
	        		
	        	else{
	        		novobanco << i->conteudo << '\n';
	        	}
	        }
	    }
	    
	    novobanco.close();
	    return true;
	}
	else{
		return false;
	}

}



