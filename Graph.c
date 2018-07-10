/*
 * Graph.c
 *
 *  Created on: Jul 4, 2018
 *      Author: Paulina
 */
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#include "Graph.h"

struct strNode {
	int id;
	Type data;
	List vertexList;
};
typedef struct strNode Node;

struct strGraph {
	Node **array;
	int orden;//num. vertices
	int size;//num. aristas
	CMP cmp;
};

Graph graph_create(CMP comparator) {
	Graph new = (Graph)malloc(sizeof(struct strGraph));

	new->array = (Node**)malloc(sizeof(Node*));
	new->array = NULL;
	new->orden = 0;
	new->size = 0;
	new->cmp = comparator;

	return new;
}

void graph_destroy(Graph g) {
	free(g->array);
	free(g);
}

Type clone(Type data) {
	Type new = (Type)malloc(sizeof(Type));
	new = data;
	return new;
}

Node *newNode(Type data, int id) {
	Node *new = (Node*)malloc(sizeof(Node));
	new->id = id;
	new->data = data;
	new->vertexList = create();

	return new;
}

boolean vertex_exists(Graph g, Type data) {
	boolean exists = false;
		for(int i = 0; i< g->orden; i++) {
			exists = g->cmp(g->array[i]->data, data);
			if(exists)
				return exists;
		}
		return exists;
}

boolean graph_addVertex(Graph g, Type data) {
	boolean exists = vertex_exists(g, data);
	if(exists)
		return false;
	g->array = (Node**)realloc(g->array, sizeof(Node)*(g->orden + 1));
	g->array[g->orden] = newNode(clone(data), g->orden);
	g->orden++;
	//g->array = (Node**)realloc(g->array, sizeof(Node)*(g->orden + 1));

	return true;
}

boolean graph_addEdge(Graph g, Type source, Type sink) {
	int i = 0, j = 0;
	if(!vertex_exists(g, source) || !vertex_exists(g, sink))
		return false;
	while(g->array[i]->data != source)
		i++;//encuentra el source
    for(j = 0; j < size(g->array[i]->vertexList); j++)
        if(get(g->array[i]->vertexList, j) == sink)
            return false;
    add(g->array[i]->vertexList, sink); //Se usa el id como indicador de posicion en las funciones de busqueda de la lista para despues agregar la arista en caso de no encontrarla.
    g->size++;
    return true;
}

unsigned long graph_vertexCount(Graph g) {
	return g->orden;
}

unsigned long graph_edgeCount(Graph g) {
	return g->size;
}

unsigned long graph_outDegree(Graph g, Type source) {
    int i = 0;
    while(g->array[i]->data != source)
        i++;
    return size(g->array[i]->vertexList);
}

boolean graph_hasEdge(Graph g, Type source, Type sink) {
    int i = 0;

    while(g->array[i]->data != source)
        i++;
    for(int j = 0; j < size(g->array[i]->vertexList); j++) {
        if(get(g->array[i]->vertexList, j) == sink )
            return true;
    }
    return false;
}

boolean graph_print(Graph g, Print p) {
	for(int i = 0; i < g->size; i++) {
		p(g->array[i]->data);
		for(int j = 0; j < size(g->array[i]->vertexList); j++)
			p(get(g->array[i]->vertexList, j));
		printf("\n");
	}
	return true;
}
