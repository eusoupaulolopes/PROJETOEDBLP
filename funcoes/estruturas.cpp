#include <stdlib.h>
#include <iostream>
#include <string>
#include "estruturas.h"

//#define VALOR_QUALQUER "extremos"

No CriarNo(string);
bool DestruirNo(No);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
Lista LIS_Criar()
{
    //Deve haver problema nisso aqui, porque quando vai adcionar o conteudo no No, dá falha de segmentação.
    string VALOR_QUALQUER = "extremo";

    Lista lista = (Lista)malloc(sizeof(tpLista));
    if( lista == NULL )
    {
        return NULL;
    }

    
    lista->tamanho = 0;
    
    //Cuidado! Buraco negro! Quando entra aqui encontra-se o erro! :/
    lista->cauda = CriarNo((string)VALOR_QUALQUER);

    

    if( lista->cauda == NULL )
    {
        return NULL;
    }

    lista->cabeca = CriarNo(VALOR_QUALQUER);
    if( lista->cabeca == NULL )
    {
        return NULL;
    }
    
    lista->cauda->anterior = lista->cabeca;
    lista->cauda->proximo = NULL;

    lista->cabeca->proximo  = lista->cauda;
    lista->cabeca->anterior = NULL;
    
    return lista;
}

/*
 Função que insere um valor no fim da lista. Após a execução desta função, o elemento inserido será o último elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirFim(Lista lista, string v)
{
    No no = CriarNo(v);
    if( no == NULL )
    {
        return false;
    }
    
    No ultimo = lista->cauda->anterior;

    lista->cauda->anterior = no;
    no->proximo = lista->cauda;
    no->anterior = ultimo;    
    ultimo->proximo = no;

    lista->tamanho++;
    return true;
}

/*
    Função que imprime todos os elementos de uma lista.
 */
void LIS_Imprimir(Lista lista)
{
    std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << i->conteudo << "\n";
    }
    std::cout << std::endl;
}

/**
 Função que libera a memória de uma instância da estrutura Lista, liberando a memória de todos os nós encadeados na lista, incluindo os nós cabeça e cauda.
 */
void LIS_Destruir(Lista lista)
{
    No atual = lista->cabeca;
    while( atual != NULL )
    {
        No destruido = atual;
        atual = atual->proximo;
        DestruirNo(destruido);
    }
    free(lista);
}

/*
 Função que aloca a memória para um nó e inicializa os atributos do nó.
 */
No CriarNo(string indice)
{



    No no = new tpNo;
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;

    no->conteudo = indice;
    
    
    return no;
}

/*
 Função que libera a memória alocada para um nó.
 */
bool DestruirNo(No no)
{
    free(no);
    return true;
}


