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
    string conteudo; //adaptação feita para atender o propósito do projeto
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

bool LIS_InserirFim(Lista lista, string v);
void LIS_Imprimir(Lista lista);
void LIS_Destruir(Lista lista);

// 	FIM: Lista



