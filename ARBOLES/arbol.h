#ifndef _ARBOL_H
#define _ARBOL_H

#include <stdio.h>


typedef int Elemento;

struct nodo{
  Elemento raiz;
  struct nodo* izq;
  struct nodo* der;
  struct nodo* padre;
};

typedef struct nodo* Arbol;


Arbol crearArbol();

Arbol construirArbol(Elemento e, Arbol iz, Arbol der);

Elemento raizArbol(Arbol lst);

Arbol arbolIzq(Arbol arb);

Arbol arbolDer(Arbol arb);

int vacioArbol(Arbol arb);

#endif