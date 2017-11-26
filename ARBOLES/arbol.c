#include "arbol.h"

Arbol crearArbol(){
  Arbol arb;
  arb = NULL;
  return arb;
}

Arbol construirArbol(Elemento e, Arbol izq, Arbol der){
  Arbol nuevo;
  
  nuevo = (Arbol) malloc(sizeof(struct nodo));
  nuevo->raiz = e;
  nuevo->izq = izq;
  nuevo->der = der;
  if(!vacioArbol(izq))
    izq->padre = nuevo;
  if(!vacioArbol(der))
    der->padre = nuevo;
  
  return nuevo;
}

Elemento raizArbol(Arbol arb){
  return arb->raiz;
}

Arbol arbolIzq(Arbol arb){
  return arb->izq;
}

Arbol arbolDer(Arbol arb){
  return arb->der;
}

int vacioArbol(Arbol arb){
  return arb == NULL;
}