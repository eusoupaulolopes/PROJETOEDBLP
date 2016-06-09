#include <string>
#include "listabusca.h"

typedef char** args;

int gerarTabela(std::string origem);
bool Ler_Buscas(int argc, args argv);
bool buscarNaTabela(int argc, args argv, std::string arquivo, ListaB& listaBusca);
bool busca(int argc, args argv);
bool buscaBOR(int argc, args argv);

bool listaLinhas(string arquivo, char * linhas,ListaB &listaBusca, char* chave);