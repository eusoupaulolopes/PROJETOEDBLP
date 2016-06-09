#include <string>
#include "listabusca.h"

typedef char** args;

int gerarTabela(std::string origem);
bool Ler_Buscas(int argc, args argv);
bool buscarNaTabela(int argc, args argv, std::string arquivo, ListaB& listaBusca, string dataHora);
bool buscaPorArquivo(int argc, args argv);
bool buscaBOR(ListaB* lista, int tamanho);
bool buscaBAND(ListaB* lista, int tamanho);
bool listaLinhas(string arquivo, char * linhas,ListaB &listaBusca, char* chave, string dataHora);
