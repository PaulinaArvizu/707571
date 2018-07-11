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
#include <String.h>
#include "Lista.h"
#include "Graph.h"

boolean cmpTwot(Type, Type);
void printTwot(Type);
boolean cmpPersona(Type, Type);
void printPersona(Type);

typedef struct {
	char* nombre;
	char* nacimiento;
	char* categoria;
}Person;

typedef struct {
	char* titulo;
	char* estreno;
	char* tagline;
}Movie;

typedef struct {
	Person person;
	Movie movie;
}edgePersonMovie;

typedef struct {
	char *twot;
	boolean retwot;
}Twot;

int main(void) {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	FILE *archivo = fopen("RETWEETS.csv", "rb");
	char *c = (char*)malloc(19*sizeof(char));
	char *temp = (char*)malloc(sizeof(char));
	Twot *t = (Twot*)malloc(sizeof(Twot));
	Twot *rt = (Twot*)malloc(sizeof(Twot));

	Graph g1 = graph_create(cmpTwot);

	if(archivo != NULL){
		while(!feof(archivo)) {
			char *te, *te2;
			fread(c, sizeof(char), 18, archivo);
			c[18] = '\0';

			te = strdup(c);
			t->twot = te;
			t->retwot = false;

			graph_addVertex(g1, t);

			fread(temp, sizeof(char), 1, archivo);

			fread(c, sizeof(char), 18, archivo);
			fread(temp, sizeof(char), 1, archivo);

			c[18] = '\0';
			te2 = strdup(c);
			rt->twot = te2;
			rt->retwot = true;

			graph_addVertex(g1, rt);
			graph_addEdge(g1, t, rt);

		}
	}

	graph_print(g1, printTwot);

	return EXIT_SUCCESS;
}

boolean cmpTwot(Type data1, Type data2) {
	Twot *t1 = (Twot*)data1;
	Twot *t2 = (Twot*)data2;
	if(strcmp(t1->twot, t2->twot) == 0)
		return true;
	else
		return false;
}

boolean cmpPersona(Type data1, Type data2) {
	Person *p1 = (Person*)data1;
	Person *p2 = (Person*)data2;

	if(strcmp(p1->nombre, p2->nacimiento) == 0)
			return true;
		else
			return false;
}

boolean cmpMovie(Type data1, Type data2) {
	Movie *m1 = (Movie*)data1;
	Movie *m2 = (Movie*)data2;

	if(strcmp(m1->titulo, m2->titulo) == 0)
			return true;
		else
			return false;
}

void printTwot(Type data) {
	Twot *t = (Twot*)data;
	printf("%s -> ", t->twot);
}

void printPersona(Type data) {

}
