#include "buscar.h" // coisas de tad
#include "estruturas.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <locale.h>
#include <fstream>
#include <sstream> //atoi
#include "listar.h"

//#define VALOR_QUALQUER "extremos"

No CriarNo(string);
No CriarNo(string,string,string);
No CriarNo(string,string,string,string);

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

bool LIS_InserirFim(Lista lista, string conteudo, string nome, string dataHora, string qtdePalavras)
{
    No no = CriarNo(conteudo,nome,dataHora,qtdePalavras);

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

    DestruirNo(no);
    
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

void LIS_Ordenar(Lista lista, int tipoListar)
{
    // Seleção
    No menor, temp;
    
    for(No i = lista->cabeca->proximo; i != lista->cauda->anterior; i=i->proximo){
        
        menor = i;
        for(No j = i->proximo; j != lista->cauda; j=j->proximo){
            if(tipoListar == alfabeticamente){
                if(j->nome < menor->nome){
                    
                    menor = j;
                }
            }
            if(tipoListar == insercao){
                if(j->dataHora < menor->dataHora){
                    
                    menor = j;
                }
            }
            if(tipoListar == quantidadePalavras){
                if(j->qtdePalavras > menor->qtdePalavras){
                    
                    menor = j;
                }
            }
        }
        
        if(menor != i){ // i não é o menor.
            
            if(i->proximo == menor){ // O menor é o elemento seguinte.
                
                i->anterior->proximo = menor;
                menor->proximo->anterior = i;
                i->proximo = menor->proximo;
                menor->proximo = i;
                menor->anterior = i->anterior;
                i->anterior = menor;
                i = menor;
                
            }else{  // Há outros elementos entre i e o menor.
                
                i->anterior->proximo = menor;
                i->proximo->anterior = menor;
                menor->anterior->proximo = i;
                menor->proximo->anterior = i;
                temp = i->proximo;
                i->proximo = menor->proximo;
                menor->proximo = temp;
                temp = i->anterior;
                i->anterior = menor->anterior;
                menor->anterior = temp;
                i = menor;
            }           
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

No CriarNo(string conteudo,string nome,string dataHora,string palavras){
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
    no->qtdePalavras = palavras;
    
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


// Funções para Tabela de Dispersão

Tabela TAB_CriarTabela(int tamanho){
    
    if (tamanho <= 0 ) 
        return NULL;

    Tabela tabela = new tpTabela;
    tabela->tamanho = tamanho;
    tabela->qtdItens = 0;
    tabela->valores = new Valor[tamanho];
    tabela->chaves = new Chave[tamanho];

    for(int i = 0; i < tabela->tamanho; i++){
        tabela->valores[i] = NULL;
        tabela->chaves[i] = NULL;
    }

    return tabela;
}
void Expandir(Tabela tabela){
    Tabela ntabela = TAB_CriarTabela((1+(tabela->tamanho*2)));    
    
    for (int i = 0; i < tabela->tamanho; i++){
        TAB_Inserir(ntabela, tabela->chaves[i], tabela->valores[i]);    
    }
    
    tabela->tamanho = ntabela->tamanho;
    tabela->valores = ntabela->valores;
    tabela->chaves = ntabela->chaves;    
    
}

void Reduzir(Tabela tabela){
    
    Tabela novaTabela = TAB_CriarTabela(1+(tabela->tamanho/2));

    for (int i = 0; i < tabela->tamanho; i++){        
        TAB_Inserir(novaTabela, tabela->chaves[i], tabela->valores[i]);   
    } 
    
    tabela->tamanho = novaTabela->tamanho;
    tabela->valores = novaTabela->valores;
    tabela->chaves = novaTabela->chaves;    
    
}
bool TAB_Inserir(Tabela tabela, Chave chave, Valor valor)
{
    
    if (tabela == NULL || chave == NULL || valor == NULL || chave == CHAVE_REMOVIDA)
        return false;

    int aux = Hash(PreHash(chave), tabela->tamanho);
    int indice;
    for (int i = 0; i < tabela->tamanho; i++){
        indice = (aux + i) % tabela->tamanho;
        if(tabela->chaves[indice] == NULL || tabela->chaves[indice] == CHAVE_REMOVIDA || (strcmp(tabela->chaves[indice]->chave, chave->chave) == 0)){
            tabela->chaves[indice] = chave;
            if(tabela->valores[indice] == NULL || tabela->valores[indice] == ITEM_REMOVIDO)
                tabela->qtdItens++;            
            if(tabela->valores[indice] == NULL)
                tabela->valores[indice] = valor;                                // AQUI DEVE INCLUIR
            else {
                std::size_t founded = tabela->valores[indice]->conteudo.find(valor->conteudo);                
                    if(founded == string::npos)
                        tabela->valores[indice]->conteudo += "-" + valor->conteudo;     //             
                }                                                               // AQUI                        
            if (tabela->qtdItens*2 >= tabela->tamanho)
                Expandir(tabela);
            return true;
        }
    }
    return false;
}

void TAB_imprimir(Tabela tabela)
{
    for (int i = 0; i < tabela->tamanho; i++){
        std::cout << "T[" << i << "] = ";
        Valor valor = tabela->valores[i];
        Chave chave = tabela->chaves[i];
        if ( valor == NULL){
            std::cout << "NULO\n"; 
        }else if (valor == ITEM_REMOVIDO){
            std::cout << "REMOVIDO\n"; 
        }else{
            std::cout << chave->chave << " : " << valor->conteudo << std::endl;
        }
    }
}

void gerarArquivoTabela(char* auxTabela, Tabela tabela)
{
    std::string texto;
    fstream file (auxTabela , ios::out | ios::app);
    if(file.is_open()){
        file << tabela->tamanho <<"\n";
        for (int i = 0; i < tabela->tamanho; i++){
            //file << std::to_string(i).c_str() << " ";
            Valor valor = tabela->valores[i];
            Chave chave = tabela->chaves[i];
            if ( valor == NULL){
                file << "NULO\n"; 
            }else if (valor == ITEM_REMOVIDO){
                file << "REMOVIDO\n"; 
            }else{
                std::string aux(chave->chave);
                file << aux << " : " << valor->conteudo << "\n";
            }
        }
    } 
    
    file.close();

}

short Hash(long valor, int n)
{
    int indice = (valor & 0x7FFFFFFF) % n;
    return indice;
}

long PreHash(Chave chave)
{
    char * str = chave->chave;
    
    long hash = 0;
    
    int c;
    
    while ( (c = *str++) )
    {
       
        hash += c;
    }
    
    return hash;
}

Chave TAB_CriarChave(const char * c)
{
    Chave chave = new tpChave;
    chave->chave = new char[strlen(c)+1];

    strcpy(chave->chave, c);

    return chave;
}

Valor TAB_CriarValor(const char* c)
{
    Valor valor = new tpValor;
    
    valor->conteudo = c;
    
    return valor;
}

