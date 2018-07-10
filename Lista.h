/*
 * Lista.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Paulina
 */

#ifndef LISTA_H_
#define LISTA_H_

typedef void * Type;
typedef struct strList *List;

List create();
void destroy(List);
int size(List);
void add(List, Type);
Type get(List, int p);
void set(List, Type, int p);
Type Remove(List, int p);
void insert(List, int p, Type value);


#endif /* LISTA_H_ */
