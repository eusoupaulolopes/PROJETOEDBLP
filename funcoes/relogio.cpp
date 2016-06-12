#include <cstring>
#include <ctime>
#include <stdlib.h>    
#include <time.h>
#include <iostream>
#include "relogio.h"


/*
 Função usada para capturar a hora do relogio do computador
 @param 
 @return longint start com o momento do clock do computador
 */

long int meuRelogio(){
	srand (time(NULL));
	std::clock_t start;
    start = clock();
    return start;
}



/*
 Função usada para calcular o tempo entre tempo inicial e um dado momento
  e exibir a diferenca de tempo em milisegundos
 @param tempoInicial long int com um dado momento do clock do computador
 @return void
 */
void fimRelogio(long int tempoInicial){
	std::cout << "Sua pesquisa demorou " << (std::clock() - tempoInicial) / (double)(CLOCKS_PER_SEC /100) << " ms"<< std::endl;
}


