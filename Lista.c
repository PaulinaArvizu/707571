/*
 ============================================================================
 Name        : Sesion19-Listas.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct strNode {
	Type data;
	struct strNode *prior, *next;
};
typedef struct strNode *Node;

struct strList {
	Node first;
	Node last;
	int size;
};

List create() {
	List new = (List)malloc(sizeof(struct strList));

	new->first = NULL;
	new->last = NULL;
	new->size = 0;

	return new;
}

void destroy(List who) {
	while(who->size != 0) {
		Remove(who, 0);
	}
	free(who);
}

int size(List who) {
	if(who != NULL)
		return who->size;
	else
		return -1;
}

void add(List who, Type data) {
	if(who == NULL)
		return;

	Node temp = (Node)malloc(sizeof(struct strNode));

	if(who->size == 0) {//la lista esta vacia
		temp->prior = NULL;
		temp->data = data;
		temp->next = NULL;
		who->first = temp;
	} else {
		temp->prior = who->last;
		temp->data = data;
		temp->next = NULL;
		who->last->next = temp;

	}
	who->last = temp;
	who->size++;
}

Type get(List who, int p) {
	if(who == NULL)
		return NULL;

	Node temp = who->first;
	for(int i = 0; i < p; i++)
		temp = temp->next;
	return temp->data;
}

void set(List who, Type data, int p) {
	if(who == NULL && who->size < p)
		return;

	Node temp = (Node)malloc(sizeof(struct strNode));
	temp = who->first;
	for(int i = 0; i < p; i++)
		temp = temp->next;
	temp->data = data;
}

Type Remove(List who, int p) {
	Node current=NULL;
		Type tmp;
		int i=0;
		int s=who->size;
		if(who!=NULL){
			//Buscar el nodo a remover
			if ((p>=0) && (p<s)){
				current=who->first;
				while(i<p){
					current=current->next;
					i++;
				}
			}
			if((p==0)&&(s==1)){
				tmp=current->data;
				who->first=NULL;
				who->last=NULL;
				who->size=0;
				free(current);
				return tmp;
			}else{
				if(p==0) //Se va a eliminar el nodo inicial
				{
					tmp=current->data;
					who->first=current->next;
					who->first->prior=NULL;
					who->size--;
					free(current);
					return tmp;
				}
				else{
					if(p==(s-1))//Se va a eliminar el nodo final
					{
						tmp=current->data;
						who->last=current->prior;
						who->last->next=NULL;
						who->size--;
						free(current);
						return tmp;
					}
					else
					{//El elemento a remover esta en medio
						tmp=current->data;
						current->prior->next=current->next;
						current->next->prior=current->prior;
						free(current);
						return tmp;
					}
				}
			}
		}
		return NULL;
}

void insert(List who, int p, Type value) { //--------- revisar implementacion en moodle (validar si es el primero, ultimo o si va en medio)
	Node temp;
	Node new = (Node)malloc(sizeof(struct strNode));

	if(who->size == 0) {//la lista esta vacia
		new->prior = NULL;
		new->data = value;
		new->next = NULL;
		who->first = new;
	} else {
		temp = who->first;
		for(int i = 0; i < p; i++) // encuentra la posicion
			temp = temp->next;

		who->size++;
		new->data = value;

		if(temp == who->first) {//se inserta en el primero
			new->prior = NULL;
			new->next = temp;
			temp->prior = new;
		} else if(temp == who->last) { //se inserta al ultimo
			temp->next = new;
			new->prior = temp;
			new->next = NULL;
		} else {//se inserta en el medio
			new->prior = temp->prior;
				new->next = temp;
				temp->prior = new;
		}
	}
}
