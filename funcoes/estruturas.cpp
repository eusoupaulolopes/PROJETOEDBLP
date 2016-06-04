#include <stdlib.h>
#include <iostream>
#include <string>
#include "estruturas.h"
#include "listar.h"

//#define VALOR_QUALQUER "extremos"

No CriarNo(string);
No CriarNo(string,string,string);
bool DestruirNo(No);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
Lista LIS_Criar()
{
    string VALOR_QUALQUER = "extremo";

    Lista lista = (Lista)malloc(sizeof(tpLista));
    if( lista == NULL )
    {
        return NULL;
    }

    
    lista->tamanho = 0;
    
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
bool LIS_InserirFim(Lista lista, string conteudo)
{
    No no = CriarNo(conteudo);
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

bool LIS_InserirFim(Lista lista, string conteudo, string nome, string dataHora)
{
    No no = CriarNo(conteudo,nome,dataHora);

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
 Função que remove um valor no início da lista.
 */
string LIS_RemoverInicio(Lista lista)
{
    string menosum = "menosum";
    if (lista->cabeca->proximo == lista->cauda){
        return menosum;
    }
    else{
        No primeiro = lista->cabeca->proximo;

        lista->cabeca->proximo = primeiro->proximo;
        primeiro->proximo->anterior = lista->cabeca;
        
        string valorremovido = primeiro->conteudo;

        DestruirNo(primeiro);

        lista->tamanho--;

        return valorremovido;
    }
}

/*
 Função que remove um valor numa determinada posição da lista.
 */
string LIS_Remover(Lista lista, int indice)
{    
    string menosum = "menosum";
    if (indice > lista->tamanho || indice <= 0){  
        return menosum;
    }
    
    if(lista->tamanho == 0){
        return menosum;
    }
    if (indice == 1){
        return LIS_RemoverInicio(lista);
    }
    
    No no = lista->cabeca->proximo;

    while (--indice){   
        no = no->proximo;
    }

    string valorremovido = no->conteudo;

    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;
    lista->tamanho--;

    return valorremovido;
}

int LIS_Buscar(Lista lista, string chave)
{
    No no = lista->cabeca->proximo;
    for (int i=0; i < lista->tamanho; i++){
        if (no->conteudo.substr(0,chave.size()) == chave){
            return i+1;
        }
        no = no->proximo;
    }

    return -1;
}

//Selection Sort
void LIS_Trocar(No menor, No fixo){
    
    No tmp1 = menor->proximo;
    No tmp2 = fixo->anterior;
    No tmp3 = fixo->proximo;
    No tmp4 = menor->anterior;

    if (fixo->proximo == menor) {//Nós vizinhos
        fixo->anterior->proximo = menor;
        menor->proximo->anterior = fixo;

        fixo->proximo = menor->proximo;
        menor->proximo = fixo;

        menor->anterior = fixo->anterior;
        fixo->anterior = menor;
    }
    else {//Nós com algum elemento entre eles
        fixo->anterior->proximo = menor;
        menor->proximo->anterior = fixo;

        fixo->proximo = tmp1;
        menor->proximo = tmp3;

        menor->anterior = tmp2;
        fixo->anterior = tmp4;
    }

}

void LIS_Ordenar(Lista lista, int tipoListar)
{
    No menor;


    //Seleção do menor
    for(No fixo = lista->cabeca->proximo; fixo != lista->cauda->anterior; fixo=fixo->proximo){
        menor = fixo;

        //cout << "to por aqui!" << menor->nome << endl;


        for(No iter=fixo->proximo; iter != lista->cauda; iter=iter->proximo){
            if(tipoListar == alfabeticamente){
                if(iter->nome < menor->nome){
                    menor = iter;
                }
            }
            if(tipoListar == quantidadePalavras){
                if(iter->qtdePalavras < menor->qtdePalavras){
                    menor = iter;
                }
            }


        }

        //Trocar se menor é diferente do no pré-fixado
        if(menor!=fixo){
            LIS_Trocar(menor,fixo);
            fixo=menor;
        }
    }
}

/*
    Função que imprime todos os elementos de uma lista.
*/
void LIS_Imprimir(Lista lista)
{
    //std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << "\t-  \""<< i->nome <<"\"\n";
    }
    std::cout << std::endl;
}
/* PARA TESTAR inserir.cpp e remover.cpp
void LIS_Imprimir(Lista lista)
{
    //std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << "\t-  \""<< i->conteudo <<"\"\n";
    }
    std::cout << std::endl;
}*/

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
    no->nome = "";
    no->dataHora = "";

    no->conteudo = indice;
    
    
    return no;
}

No CriarNo(string conteudo,string nome,string dataHora){
    No no = new tpNo;
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;

    no->conteudo = conteudo;
    no->nome = nome;
    no->dataHora = dataHora;
    
    
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


/*
    Função que ordena a lista. (Obs.: Implemente os algoritmos: selection sort, insertion sort e bubble sort.)
 */

