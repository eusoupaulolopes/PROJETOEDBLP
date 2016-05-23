#include <string>

using namespace std;

struct tpNo
{
    
    string conteudo; //adaptação feita para atender o propósito do projeto
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


Lista LIS_Criar();
bool LIS_InserirFim(Lista lista, string v);
void LIS_Imprimir(Lista lista);
void LIS_Destruir(Lista lista);





