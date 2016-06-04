//
//  estruturas.h
//  Estruturas de Dados

// 	INICIO: Lista

//  Created by Eiji Adachi Medeiros Barbosa on 31/03/16.
//  Copyright (c) 2016 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

#include <string>

using namespace std;
// Esta é a estrutura para um nó de uma lista duplamente encadeada. Não a modifique!
struct tpNo
{
    string conteudo;
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



// INICIO: Lista
Lista LIS_Criar();
void LIS_Imprimir(Lista lista);
void LIS_Destruir(Lista lista);
string LIS_RemoverInicio(Lista lista);
string LIS_Remover(Lista lista, int indice);
int LIS_Buscar(Lista lista, string chave);
bool LIS_InserirFim(Lista lista, string conteudo);
bool LIS_InserirFim(Lista lista, string conteudo, string nome, string dataHora);
void LIS_Trocar(No menor, No fixo);
void LIS_Ordenar(Lista lista, int tipoListar);
// 	FIM: Lista



