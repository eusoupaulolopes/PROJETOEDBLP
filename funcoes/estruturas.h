#ifndef _ESTRUTURAS_
#define _ESTRUTURAS_


#include <string>
#include <cstring>
#include <fstream>

using namespace std;
typedef char** args;

struct tpNo
{
    string conteudo;
    string nome;
    string dataHora;
    string qtdePalavras;
    struct tpNo* proximo;
    struct tpNo* anterior;
};

typedef tpNo * No;

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
bool LIS_InserirFim(Lista lista, string conteudo, string nome, string dataHora, string qtdePalavras);

void LIS_Trocar(No menor, No fixo);
void LIS_Ordenar(Lista lista, int tipoListar);
// 	FIM: Lista

// Estruturas TAD

typedef struct tpValor{
	
	std::string conteudo;
} *Valor;


typedef struct tpChave{
	char * chave;
} * Chave;

typedef struct tpTabela {
	Valor * valores;
	Chave * chaves;
	int tamanho;
	int qtdItens;
} *Tabela;

void TAB_imprimir(Tabela tabela);
void gerarArquivoTabela(char* auxTabela, Tabela tabela);
Tabela TAB_CriarTabela(int);
Chave TAB_CriarChave(const char * c);
Valor TAB_CriarValor(const char* c);
bool TAB_Inserir(Tabela tabela, Chave chave, Valor valor);
short Hash(long valor, int n);
long PreHash(Chave chave);

const Valor ITEM_REMOVIDO = ((Valor)(-11));
const Chave CHAVE_REMOVIDA = ((Chave)(-17));


#endif
