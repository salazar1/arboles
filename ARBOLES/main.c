#include "arbol.h"
#include <stdio.h>

void preorden(Arbol arb){
  if(!vacioArbol(arb)){
    printf("%d ", raizArbol(arb));
    preorden(arbolIzq(arb));
    preorden(arbolDer(arb));
  }
}

void posorden(Arbol arb){
  if(!vacioArbol(arb)){
    posorden(arbolIzq(arb));
    posorden(arbolDer(arb));
    printf("%d ", raizArbol(arb));
  }
}

void inorden(Arbol arb){
  if(!vacioArbol(arb)){
    inorden(arbolIzq(arb));
    printf("%d ", raizArbol(arb));
    inorden(arbolDer(arb));
  }
}

int contarElementos(Arbol arb){
  if(vacioArbol(arb)){
    return 0;
  }
  else
    return contarElementos(arbolIzq(arb)) + contarElementos(arbolDer(arb)) + 1;
}

int contarHojas(Arbol arb){
  if(vacioArbol(arb))
    return 0;
  if(vacioArbol(arbolIzq(arb)) && vacioArbol(arbolDer(arb))){
    return 1;
  }
  else
    return contarHojas(arbolIzq(arb)) + contarHojas(arbolDer(arb));
}

int contarPosibilidades(Arbol arb){
  if(vacioArbol(arb))
    return 0;
  else if(vacioArbol(arbolIzq(arb)) && vacioArbol(arbolDer(arb))){
    return 2;
  }
  else if(!vacioArbol(arbolIzq(arb)) && vacioArbol(arbolDer(arb)))
    return 1 + contarPosibilidades(arbolIzq(arb));
  else if(!vacioArbol(arbolDer(arb)) && vacioArbol(arbolIzq(arb)))
    return 1 + contarPosibilidades(arbolDer(arb));
  else
    return contarPosibilidades(arbolIzq(arb)) + contarPosibilidades(arbolDer(arb));
}

Arbol insertarNodo(Arbol arb, Elemento e, int pos){
  if(vacioArbol(arb) && pos == 1)
    return construirArbol(e, crearArbol(), crearArbol());
  else if(vacioArbol(arb))
    return arb;
  else{
    int n = contarPosibilidades(arbolIzq(arb));
    
    if( pos <= n){
      arb = construirArbol(raizArbol(arb),
                           insertarNodo(arbolIzq(arb), e, pos),
                           arbolDer(arb));
    }
    else{
      arb = construirArbol(raizArbol(arb),
                           arbolIzq(arb),
                           insertarNodo(arbolDer(arb), e, pos- n));
    }
    
    return arb;
  }
}

int main(){
  Arbol a1, a2, a3, a4;
  a1 = construirArbol(5,
                      construirArbol(10,
                                     construirArbol(21, 
                                                    construirArbol(1, 
                                                                   crearArbol(),
                                                                   crearArbol()),
                                                    crearArbol()),
                                     construirArbol(7, 
                                                    construirArbol(19, 
                                                                   crearArbol(),
                                                                   crearArbol()),
                                                    construirArbol(6, 
                                                                   crearArbol(),
                                                                   crearArbol()))),
                      construirArbol(3,
                                     construirArbol(12, 
                                                    construirArbol(23, 
                                                                   crearArbol(),
                                                                   crearArbol()),
                                                    crearArbol()),
                                     crearArbol()));
  a2 = construirArbol(11,
                      construirArbol(8, 
                                     crearArbol(),
                                     crearArbol()),
                      construirArbol(17, 
                                     crearArbol(),
                                     crearArbol()));
  a3 = construirArbol(2, a1, a2);
  
  a4 = insertarNodo(a3, 24, 10);
  
  printf("Cantidad elementos Árbol a1 = %d\n", contarElementos(a1));
  printf("Cantidad elementos Árbol a2 = %d\n", contarElementos(a2));
  printf("Cantidad elementos Árbol a3 = %d\n", contarElementos(a3));
  printf("Cantidad elementos Árbol a4 = %d\n", contarElementos(a4));
  printf("Cantidad hojas Árbol a1 = %d\n", contarHojas(a1));
  printf("Cantidad hojas Árbol a2 = %d\n", contarHojas(a2));
  printf("Cantidad hoja Árbol a3 = %d\n", contarHojas(a3));
  printf("Cantidad posibilidades Árbol a1 = %d\n", contarPosibilidades(a1));
  printf("Cantidad posibilidades Árbol a2 = %d\n", contarPosibilidades(a2));
  printf("Cantidad posibilidades Árbol a3 = %d\n", contarPosibilidades(a3));
  
  preorden(a1);
  printf("\n");
  posorden(a1);
  printf("\n");
  inorden(a1);
  printf("\n");
  
  preorden(a4);
  printf("\n");
  posorden(a4);
  printf("\n");
  inorden(a4);
  printf("\n");
}