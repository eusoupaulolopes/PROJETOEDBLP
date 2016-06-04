#ifndef _FUNCOES_LISTAR_
#define _FUNCOES_LISTAR_

#include <cstring>

#include <iostream>

enum tipoListar {
	alfabeticamente,
	quantidadePalavras,
};

typedef char** args;

void quebraLinha(string linhaStr, Lista lista);
bool listarInsercao(int argc, args argv);
bool listarAlfabeticamente(int argc, args argv);
bool listarQtdePalavras(int argc, args argv);

//char* quebraString(string str);

#endif