/*
 * Graph.h
 *
 *  Created on: Jul 4, 2018
 *      Author: Paulina
 */

#ifndef GRAPH_H_
#define GRAPH_H_

typedef enum {false, true} boolean;
typedef struct strGraph* Graph;

typedef boolean(*CMP)(Type, Type);
typedef void(*Print)(Type);

Graph graph_create(CMP comparator);

void graph_destroy(Graph g);

boolean graph_addVertex(Graph g, Type data);

boolean graph_addEdge(Graph g, Type source, Type sink);

unsigned long graph_vertexCount(Graph g);

unsigned long graph_edgeCount(Graph g);

unsigned long graph_outDegree(Graph g, Type source);

boolean graph_hasEdge(Graph g, Type source, Type sink);

boolean graph_print(Graph g, Print p);

#endif /* GRAPH_H_ */
