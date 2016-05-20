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
    Função que busca a posição de uma determinada chave numa lista.
    @param lista - lista em que será feita a busca
    @param chave - chave a ser buscada na lista
    @return índice que indica a posição do elemento cujo valor é igual a chave. Retorna -1 caso a chave não seja encontrada na lista.
 */
int LIS_Buscar(Lista lista, string chave)
{
	No no = lista->cabeca->proximo;
	for (int i=0; i < lista->tamanho; i++){
		if (no->indiceArquivo == chave){
			i++;
			return i;
		}
		no = no->proximo;
	}

    return -1;
}

/*
 Função que retorna o valor de um elemento na lista que está na posição indicada pelo parâmetro i.
 @param lista - lista em que será feita a busca
 @param i - indica a posição do elemento cujo valor se deseja retornar
 @return valor do elemento na i-esima posição da lista. Retorna NULL se não existir elemento na i-esima posição
 */
string LIS_PegarValor(Lista lista, int i )
{
	No no = lista->cabeca->proximo;
	if (i > lista->tamanho || i < 0)
    	return NULL;
    else{
    	for (int j=1; j <=i; j++){
    		if (j == i)
    			return no->indiceArquivo;
    		no = no->proximo;    		
    	} 
    }
}

/*
 Função que insere um valor no início da lista. Após a execução desta função, o elemento inserido será o primeiro elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirInicio(Lista lista, string v)
{
    No no = CriarNo(v);
    if( no == NULL )
    {
        return false;
    }
    
    No primeiro = lista->cabeca->proximo;

    lista->cabeca->proximo = no;
    no->anterior = lista->cabeca;
    no->proximo = primeiro;
    primeiro->anterior = no;

    lista->tamanho++;
    
    return true;
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
 Função que insere um valor numa determinada posição da lista. Após a execução desta função, o elemento inserido será o i-esimo elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @param i - indica a posição que o novo elemento ocupará após a inserção
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_Inserir(Lista lista, string v, int i)
{
    No novo = CriarNo(v);
    if( novo == NULL ){
        return false;
    }
    
    No no = lista->cabeca;

	if (i > lista->tamanho+1 || i <= 0){  
    	return false;
	}
	
	if(i == lista->tamanho+1){
		return LIS_InserirFim(lista,v);
	}
	if(lista->tamanho == 0){
        return LIS_InserirInicio(lista,v);
    }
    
    while (--i){   
        no = no->proximo;
    }
    
    novo->anterior = no;
    novo->proximo = no->proximo;
    no->proximo->anterior = novo;
    no->proximo = novo;
    lista->tamanho++;

    return true;
}

/*
 Função que remove um valor no início da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna NULL caso a lista esteja vazia.
 */
string LIS_RemoverInicio(Lista lista)
{
    if (lista->cabeca->proximo == lista->cauda){
    	return NULL;
    }
    else{
	    No primeiro = lista->cabeca->proximo;

	    lista->cabeca->proximo = primeiro->proximo;
	    primeiro->proximo->anterior = lista->cabeca;
	    
        string valorremovido = primeiro->indiceArquivo;

		DestruirNo(primeiro);

	    lista->tamanho--;

        return valorremovido;
    }
}

/*
 Função que remove um valor no fim da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna NULL caso a lista esteja vazia.
 */
string LIS_RemoverFim(Lista lista)
{
    if (lista->tamanho == 0){
    	return NULL;
    }
    else{
	    No ultimo = lista->cauda->anterior;

	    lista->cauda->anterior = ultimo->anterior;
	    ultimo->anterior->proximo = lista->cauda;
	    string valorremovido = ultimo->indiceArquivo;

		DestruirNo(ultimo);

	    lista->tamanho--;

        return valorremovido;
    }
    
}

/*
 Função que remove um valor numa determinada posição da lista.
 @param lista - lista em que será feita a remoção
 @param indice - indica a posição na lista do elemento que se deseja remover
 @return retorna o valor do elemento removido. Retorna NULL caso a lista esteja vazia, ou caso o índice não aponte para uma posição válida da lista.
 */
string LIS_Remover(Lista lista, int indice)
{    
	if (indice > lista->tamanho || indice <= 0){  
    	return NULL;
	}
	
	if(lista->tamanho == 0){
        return NULL;
    }
    if (indice == 1){
    	return LIS_RemoverInicio(lista);
    }
	
	No no = lista->cabeca;

    while (--indice){   
        no = no->proximo;
    }

    string valorremovido = no->indiceArquivo;

    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;
    lista->tamanho--;

    return valorremovido;
}

/*
    Função que ordena a lista. (Obs.: Implemente os algoritmos: selection sort, insertion sort e bubble sort.)
 */

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

void LIS_Ordenar(Lista lista)
{
    No menor;
    //Seleção do menor
    for(No fixo = lista->cabeca->proximo; fixo != lista->cauda->anterior; fixo=fixo->proximo){
        menor = fixo;

        for(No iter=fixo->proximo; iter != lista->cauda; iter=iter->proximo){
            if(iter->indiceArquivo < menor->indiceArquivo){
                menor = iter;
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
    Função que intercala duas listas ordenadas, retornando uma nova lista contendo a intercalação das duas listas de entrada.
 */
Lista LIS_Intercalar(Lista lista1, Lista lista2)
{
	Lista listaIntercalada = LIS_Criar();

    No i = lista1->cabeca->proximo;
    No j = lista2->cabeca->proximo;

    while((i!=lista1->cauda) && (j!=lista2->cauda)){
        if(i->indiceArquivo < j->indiceArquivo){
            LIS_InserirFim(listaIntercalada,i->indiceArquivo);
            i=i->proximo;
        } else{
            LIS_InserirFim(listaIntercalada,j->indiceArquivo);
            j=j->proximo;
        }
    }

    while(i!=lista1->cauda){
        LIS_InserirFim(listaIntercalada,i->indiceArquivo);
        i=i->proximo;
    }

    while(j!=lista2->cauda){
        LIS_InserirFim(listaIntercalada,j->indiceArquivo);
        j=j->proximo;
    }

    return listaIntercalada;

	
}

bool LIS_InserirOrdenado(Lista lista, string v){

	No auxiliar = lista->cabeca->proximo;

	int i=1;

	while(v > auxiliar->indiceArquivo && auxiliar != lista->cauda){
		auxiliar =auxiliar->proximo;
		i++;
	}
	LIS_Inserir(lista,v,i);

	return true;
}

No LIS_BuscarMF(Lista lista, string v){
	
	No auxiliar;

	for(auxiliar = lista->cabeca->proximo; auxiliar != lista->cauda; auxiliar = auxiliar->proximo){
		
		if (auxiliar->indiceArquivo == v){

			auxiliar->anterior->proximo = auxiliar->proximo;
			auxiliar->proximo->anterior = auxiliar->anterior;
			auxiliar->anterior = lista->cabeca;
			auxiliar->proximo = lista->cabeca->proximo;
			lista->cabeca->proximo->anterior = auxiliar;
			lista->cabeca->proximo = auxiliar;


			return auxiliar;
		}
	}

    return NULL;	

}

No LIS_BuscarCF(Lista lista, string v){
	No auxiliar,no;

	for(auxiliar = lista->cabeca->proximo; auxiliar != lista->cauda; auxiliar = auxiliar->proximo){
		
		if (auxiliar->indiceArquivo == v){
			auxiliar->contadorAcessos++;
			no = auxiliar->anterior;

			while(auxiliar->contadorAcessos > no->contadorAcessos  && no != lista->cabeca){
				no = no->anterior;
			}

			auxiliar->anterior->proximo = auxiliar->proximo;
			auxiliar->proximo->anterior = auxiliar->anterior;

			auxiliar->anterior = no;
			auxiliar->proximo = no->proximo;
			no->proximo->anterior = auxiliar;
			no->proximo = auxiliar;

			return auxiliar;
		}
	}

    return NULL;
}


/*
    Função que imprime todos os elementos de uma lista.
 */
void LIS_Imprimir(Lista lista)
{
    std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << i->indiceArquivo << "\n";
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



    No no = (No) malloc( sizeof( tpNo ) );
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;
    
    cout << "Achei! D=" << endl;

    no->indiceArquivo = indice;
    
    
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


