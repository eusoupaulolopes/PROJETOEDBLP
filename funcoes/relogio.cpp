#include <cstring>
#include <ctime>
#include <stdlib.h>    
#include <time.h>
#include <iostream>
#include "relogio.h"



long int meuRelogio(){
	srand (time(NULL));
	std::clock_t start;
    start = clock();
    return start;
}


void fimRelogio(long int tempoInicial){
	std::cout << "Sua pesquisa demorou " << (std::clock() - tempoInicial) / (double)(CLOCKS_PER_SEC /100) << " ms"<< std::endl;
}


//(std::clock() - hangar.avioes[temp].tEntrada) / (double)(CLOCKS_PER_SEC / 1000)