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
    string indiceArquivo; //adaptação feita para atender o propósito do projeto
    int contadorAcessos;
    struct tpNo* proximo;
    struct tpNo* anterior;
};

typedef tpNo * No;

// Esta é a estrutura para uma lista com sentinelas. Não a modifique!
struct tpLista
{
    No cabeca;
    No cauda;
    int tamanho;
};

typedef tpLista * Lista;


Lista LIS_Criar();

int LIS_Buscar(Lista lista, string chave);
string LIS_PegarValor(Lista lista, int i );

bool LIS_InserirInicio(Lista lista, string v);
bool LIS_InserirFim(Lista lista, string v);
bool LIS_Inserir(Lista lista, string v, int i);

string LIS_RemoverInicio(Lista lista);
string LIS_RemoverFim(Lista lista);
string LIS_Remover(Lista lista, int indice);

//Selection Sort
void LIS_Trocar(No menor, No fixo);
void LIS_Ordenar(Lista lista);

Lista LIS_Intercalar(Lista lista1, Lista lista2);

bool LIS_InserirOrdenado(Lista lista, string v);
No LIS_BuscarMF(Lista lista, string v);
No LIS_BuscarCF(Lista lista, string v);

void LIS_Imprimir(Lista lista);
void LIS_Destruir(Lista lista);

// 	FIM: Lista



