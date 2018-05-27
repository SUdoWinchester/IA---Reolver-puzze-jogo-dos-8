#include<stdio.h>
#include<stdlib.h>
#include "skynet.h"
#include "lista.h"

int matrizAux[3][3];
int codFinal = 123456780;
int countNo = 0;
int countProf = 0;

void start(int mat[3][3]) {
	lista *aberto = newLista();
	lista *fechado = newLista();

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			matrizAux[i][j] = mat[i][j];

	enqueue(aberto, NULL, compactar());

	node *aux;
	while(aberto->first != NULL) {
		aux = dequeue(aberto);
		if(check(aux->x) == 1)
			break;
		else {
			gerarEstados(aberto, fechado, aux);
			enqueue2(fechado, aux);
		}
	}
	solucao(aux);
	printf("\n\nNumero de nos criados = %d\n", countNo);
	printf("Profundidade da Solucao = %d\n", countProf);
}

int check(int cod) {
	if(cod == codFinal)
		return 1;
	else
		return 0;
}

void gerarEstados(lista *aberto, lista *fechado, node *no) {
	descompactar(no->x);

	//coordenadas do 0
	int x, y;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(matrizAux[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
	}

	int temp[3][3], aux;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			temp[i][j] = matrizAux[i][j];
		}
	}

	//mover 0 para cima
	if(x != 0) {
		aux = matrizAux[x-1][y];
		matrizAux[x-1][y] = 0;
		matrizAux[x][y] = aux;

		if(pesquisar(aberto, compactar()) != 1 && pesquisar(fechado, compactar()) != 1) {
			enqueue(aberto, no, compactar());
			countNo++;
		}
	}

	//mover 0 para direita
	if(y != 2) {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				matrizAux[i][j] = temp[i][j];
			}
		}

		aux = matrizAux[x][y+1];
		matrizAux[x][y+1] = 0;
		matrizAux[x][y] = aux;

		if(pesquisar(aberto, compactar()) != 1 && pesquisar(fechado, compactar()) != 1) {
			enqueue(aberto, no, compactar());
			countNo++;
		}

	}

	//mover 0 para baixo
	if(x != 2) {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				matrizAux[i][j] = temp[i][j];
			}
		}

		aux = matrizAux[x+1][y];
		matrizAux[x+1][y] = 0;
		matrizAux[x][y] = aux;

		if(pesquisar(aberto, compactar()) != 1 && pesquisar(fechado, compactar()) != 1) {
			enqueue(aberto, no, compactar());
			countNo++;
		}
	}

	//mover 0 para esquerda
	if(y != 0) {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				matrizAux[i][j] = temp[i][j];
			}
		}

		aux = matrizAux[x][y-1];
		matrizAux[x][y-1] = 0;
		matrizAux[x][y] = aux;

		if(pesquisar(aberto, compactar()) != 1 && pesquisar(fechado, compactar()) != 1) {
			enqueue(aberto, no, compactar());
			countNo++;
		}
	}
}

int compactar() {
	int cod = 0;
	int valor = 100000000;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cod += matrizAux[i][j] * valor;
			valor = valor/10;
		}
	}

	return cod;
}

void descompactar(int cod) {
	int valor = 100000000;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			matrizAux[i][j] = cod/valor;
			cod = cod - ((cod/valor)*valor);
			valor = valor/10;
		}
	} 
}


void solucao(node *no) {
	if(no == NULL) {
		return ;
	} else {
		countProf++;
		solucao(no->pai);
		descompactar(no->x);

		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(matrizAux[i][j] != 0) {
					printf("%d\t", matrizAux[i][j]);
				} else {
					printf(" \t");
				}
			}
			printf("\n");
		}
		printf("\n\n");
		no = no->pai;
	}
}