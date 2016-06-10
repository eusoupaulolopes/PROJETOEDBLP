#ifndef _LISTA_BUSCA_
#define _LISTA_BUSCA_

#include <string>
#include <cstring>
#include <fstream>

using namespace std;
typedef char** args;

struct tpNoBusca
{
    string nomeArquivo;
    string palavraChave;
    string linha;
    int numeroLinha;
    string hora;
    struct tpNoBusca* proximo;
    struct tpNoBusca* anterior;
};

typedef tpNoBusca * NoB;

struct tpListaBusca
{
    NoB cabeca;
    NoB cauda;
//    string nome;
//    string hora;
    int qtdeElementos;
    int tamanho;

};

typedef tpListaBusca * ListaB;

//Enum para Ordenação da ListaB
enum tipoOrdenar {
    palavraChave,
    linha,
    numeroLinha,
};

/*Enum para Ordenação do vetor de ListaB (opção de impressão)
enum tipo {
    pA,
    pC,
    pI,
};*/


ListaB LIS_CriarB();
bool LIS_InserirFimB(ListaB lista, string nomeArquivo, string palavra, string hora, string linha, int numeroLinha);

void LIS_ImprimirB(ListaB lista);
void LIS_ImprimirTeste(ListaB lista);

string LIS_RemoverInicioB(ListaB lista);
string LIS_RemoverB(ListaB lista, int indice);

int LIS_Buscar_NumeroLinha(ListaB lista, int numeroLinha);
int LIS_Buscar_Chave(ListaB lista, string chave);

void LIS_TrocarB(NoB menor, NoB fixo);
void LIS_OrdenarB(ListaB lista);
void LIS_OrdenarB(ListaB lista, int tipoOrdenar);
//void LIS_OrdenarB(ListaB* lista, int tamanho, int tipo);

void EliminaLinhasIguais(ListaB lista);
ListaB EliminaLinhasSemTodasPalavras(ListaB lista, int numerodepalavras);
#endif