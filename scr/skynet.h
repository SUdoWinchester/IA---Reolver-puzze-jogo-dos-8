#include "lista.h"

#ifndef LISTCAD_H
#define LISTCAD_H

void start(int mat[3][3]);
int check(int cod);
void gerarEstados(lista *aberto, lista *fechado, node *no);
int compactar();
void descompactar(int cod);
void solucao(node *no);

#endif