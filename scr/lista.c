#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

lista *newLista() {
	lista *l = (lista*) malloc(sizeof(lista));
	l->first = NULL;

	return l;
}

node *newNode(int x, node *pai) {
	node *new_node = (node*) malloc(sizeof(node));
	new_node->x = x;
	new_node->pai = pai;
	new_node->next = NULL;

	return new_node;
}

void enqueue(lista *l, node *pai, int x) {
	if(l->first == NULL) {
		l->first = newNode(x, NULL);
	} else {
		node *aux = l->first;

		while(aux->next != NULL) {
			aux = aux->next;
		}

		aux->next = newNode(x, pai);
	}
}

void enqueue2(lista *l, node *no) {
	if(l->first == NULL) {
		l->first = no;
	} else {
		node *aux = l->first;

		while(aux->next != NULL) {
			aux = aux->next;
		}
		no->next = NULL;
		aux->next = no;
	}
}

node *dequeue(lista *l) {
	if(l->first == NULL) {
		printf("LISTA VAZIA\n");
		getch();
		return NULL;
	} else {
		node *aux = l->first;
		l->first = aux->next;
		return aux;
	}
}

int pesquisar(lista *l, int x) {
	node *aux = l->first;

	while(aux != NULL) {
		if(aux->x == x)
			return 1;
		aux = aux->next;
	}

	return 0;
}