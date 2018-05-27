#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
	int x;
	struct Node *pai;
	struct Node *next;
} node;

typedef struct {
	node *first;
} lista;

lista *newLista();
node *newNode(int x, node *pai);
void enqueue(lista *l, node *pai, int x);
void enqueue2(lista *l, node *no);
node *dequeue(lista *l);
int pesquisar(lista *l, int x);

#endif