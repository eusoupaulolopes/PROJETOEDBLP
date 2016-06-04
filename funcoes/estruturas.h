//
//  estruturas.h
//  Estruturas de Dados

// 	INICIO: Lista

//  Created by Eiji Adachi Medeiros Barbosa on 31/03/16.
//  Copyright (c) 2016 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#include <string>
#include <cstring>
#include <fstream>

using namespace std;
// Esta é a estrutura para um nó de uma lista duplamente encadeada. Não a modifique!
struct tpNo
{
    string conteudo; //adaptação feita para atender o propósito do projeto
    string nome;
    string dataHora;
    int qtdePalavras;
    struct tpNo* proximo;
    struct tpNo* anterior;
};

typedef tpNo * No;


// Esta é a estrutura para uma lista com sentinelas.
struct tpLista
{
    No cabeca;
    No cauda;
    int tamanho;
};

typedef tpLista * Lista;

// Estruturas TAD

typedef char** args;

typedef struct tpValor{
	
	std::string conteudo;
} *Valor;


typedef struct tpChave{
	char * chave;
} * Chave;

typedef struct tpTabela {
	Valor * valores;
	Chave * chaves;
	int tamanho;
	int qtdItens;
} *Tabela;

void TAB_imprimir(Tabela tabela);
Tabela TAB_CriarTabela(int);
Chave TAB_CriarChave(const char * c);
Valor TAB_CriarValor(const char* c);
bool TAB_Inserir(Tabela tabela, Chave chave, Valor valor);
short Hash(long valor, int n);
long PreHash(Chave chave);

const Valor ITEM_REMOVIDO = ((Valor)(-11));
const Chave CHAVE_REMOVIDA = ((Chave)(-17));




Lista LIS_Criar();
void LIS_Imprimir(Lista lista);
void gerarArquivoTabela(char* auxTabela, Tabela tabela);
void LIS_Destruir(Lista lista);
string LIS_RemoverInicio(Lista lista);
string LIS_Remover(Lista lista, int indice);
int LIS_Buscar(Lista lista, string chave);
bool LIS_InserirFim(Lista lista, string conteudo);
bool LIS_InserirFim2(Lista lista, string conteudo, string nome, string dataHora);
// 	FIM: Lista



