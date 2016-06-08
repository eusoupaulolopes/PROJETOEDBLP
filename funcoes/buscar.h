#include <string>

typedef char** args;

int gerarTabela(std::string origem);
bool Ler_Buscas(int argc, args argv);
bool buscar(int argc, args argv, std::string arquivo);
bool buscaBAND(int argc, args argv);
bool buscaBOR(int argc, args argv);

bool listaLinhas(std::string arquivo, char * linhas);
