#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "skynet.h"

int main() {
	int matriz[3][3] = {1, 2, 3,
				  		4, 5, 6,
				 	 	0, 7, 8};

	clock_t inicio, fim;
	double passado;

	inicio = clock();
	start(matriz);
	fim = clock();
	passado = (double) (((fim - inicio) / (CLOCKS_PER_SEC / 1000))) / 1000;

	printf("Tempo gasto: %.3lfs\n", passado);

	return 10;
}