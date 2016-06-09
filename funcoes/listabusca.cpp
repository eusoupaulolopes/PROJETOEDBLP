#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <locale.h>
#include <sstream> //atoi
#include "listabusca.h"

NoB CriarNoB(string,string,string,string,int);
bool DestruirNoB(NoB);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
ListaB LIS_CriarB()
{
    string VALOR_QUALQUER = "extremo";

    ListaB lista = (ListaB)malloc(sizeof(tpListaBusca));
    if( lista == NULL )
    {
        return NULL;
    }

    
    lista->tamanho = 0;
    
    lista->cauda = CriarNoB((string)VALOR_QUALQUER,(string)VALOR_QUALQUER,(string)VALOR_QUALQUER,(string)VALOR_QUALQUER,-10000);
    

    if( lista->cauda == NULL )
    {
        return NULL;
    }

    lista->cabeca = CriarNoB((string)VALOR_QUALQUER,(string)VALOR_QUALQUER,(string)VALOR_QUALQUER,(string)VALOR_QUALQUER,-10000);
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
bool LIS_InserirFimB(ListaB lista, string nomeArquivo, string palavra, string hora, string linha, int numeroLinha)
{
    NoB no = CriarNoB(nomeArquivo,palavra,hora,linha,numeroLinha);
    if( no == NULL )
    {
        return false;
    }
    
    NoB ultimo = lista->cauda->anterior;

    lista->cauda->anterior = no;
    no->proximo = lista->cauda;
    no->anterior = ultimo;    
    ultimo->proximo = no;

    lista->tamanho++;
    return true;
}

/*
 Função que insere um valor no fim da lista. Após a execução desta função, o elemento inserido será o último elemento da lista.
 @param lista - lista em que será feita a busca
 @param chave - valor a ser buscado na lista
 @return se encontrar a chave, devolve a posição em que ela se encontra na lisa, caso contrário retorna -1
 */

int LIS_Buscar_NomeArquivo(ListaB lista, string nomeArquivo)
{
    NoB no = lista->cabeca->proximo;
    for (int i=0; i < lista->tamanho; i++){
        if (no->nomeArquivo == nomeArquivo){
            return i+1;
        }
        no = no->proximo;
    }

    return -1;
}

int LIS_Buscar_Chave(ListaB lista, string chave)
{
    NoB no = lista->cabeca->proximo;
    for (int i=0; i < lista->tamanho; i++){
        if (no->palavraChave == chave){
            return i+1;
        }
        no = no->proximo;
    }

    return -1;
}

/*
 Função que remove um valor no início da lista.
 */

string LIS_RemoverInicioB(ListaB lista)
{
    string menosum = "menosum";
    if (lista->cabeca->proximo == lista->cauda){
        return menosum;
    }
    else{
        NoB primeiro = lista->cabeca->proximo;

        lista->cabeca->proximo = primeiro->proximo;
        primeiro->proximo->anterior = lista->cabeca;
        
        string valorremovido = primeiro->nomeArquivo;

        DestruirNoB(primeiro);

        lista->tamanho--;

        return valorremovido;
    }
}

/*
 Função que remove um valor numa determinada posição da lista.
 */
string LIS_RemoverB(ListaB lista, int indice)
{    
    string menosum = "menosum";
    if (indice > lista->tamanho || indice <= 0){  
        return menosum;
    }
    
    if(lista->tamanho == 0){
        return menosum;
    }
    if (indice == 1){
        return LIS_RemoverInicioB(lista);
    }
    
    NoB no = lista->cabeca->proximo;

    while (--indice){   
        no = no->proximo;
    }

    string valorremovido = no->linha;

    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;

    DestruirNoB(no);

    lista->tamanho--;

    return valorremovido;
}

/*
    Função que imprime todos os elementos de uma lista.
*/
void LIS_ImprimirB(ListaB lista)
{
   
    for(NoB i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {        
        if(i == lista->cabeca->proximo && i->numeroLinha > 0){
             std::cout << "Foram encontradas " << lista->tamanho << " linhas no arquivo \"" << i->nomeArquivo << "\"" << std::endl;
        }
        else if(i == lista->cabeca->proximo && i->numeroLinha <= 0){
             std::cout << "Foram encontradas 0 linha(s) no arquivo \"" << i->nomeArquivo << "\"" << std::endl;
        }

        if(i->numeroLinha != -1){
            std::cout << "\t- linha " << i->numeroLinha << ": \"" << i->linha <<"\"\n";
        }

    }
    std::cout << std::endl;
}

void LIS_ImprimirTeste(ListaB lista)
{
   
    std::cout << "Tamanho da lista: " << lista->tamanho << std::endl;
    for(NoB i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {

        std::cout << "Nome do arquivo: " << i->nomeArquivo <<std::endl;
        std::cout << "Hora: " << i->hora << std::endl;
        std::cout << "Palavra buscada: " << i->palavraChave << std::endl;
        std::cout << "linha " << i->numeroLinha <<" - \"" << i->linha << "\"" <<std::endl;

    }
    std::cout << std::endl;
}

NoB CriarNoB(string nomeArquivo, string palavra, string hora, string linha, int numeroLinha){
    
    NoB no = new tpNoBusca;
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;

    no->nomeArquivo = nomeArquivo;
    no->palavraChave = palavra;
    no->hora = hora;
    no->linha = linha;
    no->numeroLinha = numeroLinha;
    
    return no;
}

/*
 Função que libera a memória alocada para um nó.
 */
bool DestruirNoB(NoB no)
{
    free(no);
    return true;
}