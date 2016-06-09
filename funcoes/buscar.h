#include <string>
#include "listabusca.h"

typedef char** args;

bool Ler_Buscas(int argc, args argv);
bool buscarNaTabela(int argc, args argv, std::string arquivo, ListaB& listaBusca, std::string dataHora);
bool buscaPorArquivo(int argc, args argv);
bool buscaBOR(ListaB* lista, int tamanho);
bool buscaBAND(ListaB* lista, int tamanho);
bool listaLinhas(string arquivo, char * linhas,ListaB &listaBusca, char* chave, std::string dataHora);
int gerarTabela(std::string origem);
