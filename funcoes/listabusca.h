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
    int tamanho;
};

typedef tpListaBusca * ListaB;

ListaB LIS_CriarB();
bool LIS_InserirFimB(ListaB lista, string nomeArquivo, string palavra, string hora, string linha, int numeroLinha);
void LIS_ImprimirB(ListaB lista);

#endif