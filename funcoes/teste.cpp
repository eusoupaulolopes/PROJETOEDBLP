#include "teste.h"
#include "estruturas.h"
#include "listabusca.h"
#include <cstring>
#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>
#include <limits>

using namespace std;


fstream& GoToLine(std::fstream& file, int num);
int contadorLinhas(fstream& file);

/*
 Função que valida a entrada no terminal e escolhe a busca apropriada 
 @param argc - tamanho do vetor de argumentos
 @param argv - vetor de argumentos do terminal
 @return busca apropriada, false caso a opção escolhida não seja -bAND ou -bOR
 */

bool Ler_Buscas(int argc, args argv){

	if(!strcmp(argv[1], "-bAND")){
		return busca(argc, argv);
	}else if (!strcmp(argv[1], "-bOR")){
		return busca(argc, argv);
	}else{
		return false;
	}
}

bool busca(int argc, args argv){

	setlocale(LC_ALL,"pt_BR"); 
	char * banco = (char *) "bancodedados";
	fstream file;
	file.open(banco);
	if (!file.is_open()){
		cout << "Não foi possivel abrir " << banco << endl;
		return false;
	}

	int numeroLinhas = contadorLinhas(file);
	//Criação de um vetor de listas, em que cada lista corresponde a um arquivo da base de buscas
    ListaB listaBusca[numeroLinhas];
    for(int i=0; i<2;i++){
     	listaBusca[i] = LIS_CriarB();
    }
    int a=0;

    std::string linha;
	while(!file.eof()){
		getline(file, linha);
		if(linha != "\0"){

			std::string arquivoDat = "banco/";
			std::string nome(strtok((char*)linha.c_str(),";"));
			nome = nome.erase(nome.length()-4,4)+".dat";
			arquivoDat+=nome;

			buscarNaTabela(argc, argv, arquivoDat, listaBusca[a]);

		}

		LIS_ImprimirB(listaBusca[a]);
		a++;
	}	

	file.close();

	if(!strcmp(argv[1], "-bAND")){
		cout << "Eu to na Band!" << endl;
	}

	if(!strcmp(argv[1], "-bOR")){
		cout << "Eu to no BOR!" << endl;
	}


	return true;

}

int contadorLinhas(fstream& file){
	int cont = 0;
	while(!file.eof()){
		file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cont++;
	}
	file.seekg(std::ios::beg);
	return cont;
}

/*
 Função que não sei como se chama, quando descobrir coloco um nome melhor
 @param argc - tamanho do vetor de argumentos
 @param argv - vetor de argumentos do terminal
 @return true caso tenha aberto corretamento o arquivo e designado a busca, false caso o arquivo nao exista na base
 */

bool buscarNaTabela(int argc, args argv, std::string arquivo, ListaB& listaBusca){
	fstream file (arquivo);
	file.seekg(0);
	


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
		
		GoToLine(file, linhaIdeal);	
		getline(file,linha);
		
		std::size_t foundedWord = linha.find(argv[i]);                
		std::size_t foundedNull = linha.find(nulo);                
		
		//Se não achar a chave e != de nulo prossiga
		while(foundedWord==string::npos){
			if(foundedNull!=string::npos){
				cout << "\t - Não contem a palavra\n" << endl;
				string linhaFail = "\t - Não contem a palavra\n";
				LIS_InserirFimB(listaBusca,arquivo,argv[i],arquivo,linhaFail,-1);
				break;
			}
			getline(file, linha);
			foundedWord = linha.find(argv[i]);                
			foundedNull = linha.find(nulo);
			
		}
		// Se achou a palavra
		if(foundedWord!=string::npos){
			// Descarto tudo antes do ':' 
			strtok((char*)linha.c_str(),":");		
			char* auxLinhas = strtok(NULL,":");
			// Atribuo a linhas a uma string e envio a listagem				
			listaLinhas(arquivo, auxLinhas,listaBusca,argv[i]);
		}
		file.seekg(0);
	}
	file.close();
	
	return true;
}



/*
 Função que recebe um arquivo contido na base de buscas, e a linha desejada nesse arquivo
 FONTE: //http://stackoverflow.com/questions/5207550/in-c-is-there-a-way-to-go-to-a-specific-line-in-a-text-file/5207600#5207600
 @param file - arquivo a percorrer
 @param num - linha desejada no arquivo
 @return file com o ponteiro armadao na linha desejada
 */
std::fstream& GoToLine(std::fstream& file, int num){
	file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}


/*
 Função que recebe um caminho para arquivo contido na base de buscas e as linhas a navegar nesses arquivos
 @param arquivo - localização do arquivo na base
 @param linhas - todas as linhas a buscar no arquivo
 @return true se o arquivo foi aberto e as linhas tratadas; false caso o arquivo nao exista
 */
bool listaLinhas(string arquivo, char * linhas,ListaB &listaBusca, char* chave){
	string arquivoAux = arquivo.erase(arquivo.length()-4,4) +".txt";
	char* nlinha = std::strtok(linhas ,"-");
	fstream arquivoTXT(arquivoAux);

	// Verifica se o arquivo foi aberto corretamente
	if(!arquivoTXT.is_open()){
		return false;
	}

	while(nlinha != NULL){	
		string linhaAux;
		GoToLine(arquivoTXT, atoi(nlinha));
		getline(arquivoTXT,linhaAux);

		//falta colocar a hora
		LIS_InserirFimB(listaBusca,arquivoAux,chave,arquivoAux,linhaAux,atoi(nlinha));

		

		cout << "\t>>> Encontrado na linha " << nlinha << " -> " << linhaAux << endl;
		nlinha = strtok(NULL,"-");			
	}

	arquivoTXT.close();	
	return true;			
	


}