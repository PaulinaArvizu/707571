/*
 ============================================================================
 Name        : Tarea5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Graph.h"

boolean cmp(Type, Type);
void print(Type);

int main(void) {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	FILE *archivo = fopen("RETWEETS.csv", "rb");
	char *c = (char*)malloc(18*sizeof(char));
	char *temp = (char*)malloc(sizeof(char));

	Graph g1 = graph_create(cmp);

	if(archivo != NULL)
		while(!feof(archivo)) {
			fread(c, sizeof(char), 18, archivo);
			graph_addVertex(g1, c);
			fread(temp, sizeof(char), 1, archivo);
		}

	graph_print(g1, print);

	return EXIT_SUCCESS;
}

void print(Type data) {
	char *c = (char*)data;
	printf("%s -> ", c);
}

boolean cmp(Type data1, Type data2) {
	char *c1 = (char*)data1;
	char *c2 = (char*)data2;
	if(c1 == c2)
		return true;
	else
		return false;
}
