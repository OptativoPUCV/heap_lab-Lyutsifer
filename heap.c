#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* arrai){
    fflush (stdin);
    if (arrai==NULL || arrai->heapArray==NULL || arrai->size == 0) return NULL;
    void * auxVar= arrai->heapArray[0].data;
    return auxVar;
}



void heap_push(Heap* arrai, void* data, int priority){

  if (arrai== NULL || arrai->heapArray== NULL || arrai->capac== 0 || data== NULL) return;
  if (arrai->capac == arrai->size){
    arrai->heapArray= (heapElem*) realloc (arrai->heapArray , arrai->capac * 2 *sizeof(heapElem) );
  }
  int posi= arrai->size-1;
  arrai->heapArray[posi].priority= priority;
  arrai->heapArray[posi].data= data;
  int auxPrio2= arrai->heapArray[(posi - 1)/2].priority;

  while (priority > auxPrio2){
    //Nodo que guarda data del padre (pos-1)/2
    heapElem * auxNodo = (heapElem*) malloc(sizeof(heapElem));
    auxNodo->data= arrai->heapArray[(posi -1)/2].data;
    auxNodo->priority= arrai->heapArray[(posi -1)/2].priority;
    //Se reemplaza el nodo nuevo en la posicion del padre
    arrai->heapArray [(posi-1) / 2].data= data;
    arrai->heapArray [(posi-1) / 2].priority= priority;
    //El padre pasa a la posicion del nuevo nodo, i = size-1
    arrai->heapArray[(posi)].priority = auxNodo->priority;
    arrai->heapArray[(posi)].data = auxNodo->data;
    //Nueva posicion del nodo
    posi= (posi-1) / 2;
    if (posi<0 || (posi-1 /2) < 0) break;
    auxPrio2= arrai->heapArray[(posi - 1)/2].priority;
     
  }
  return;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * nHeap= (Heap*) malloc (sizeof(Heap));
  nHeap->heapArray= (heapElem*) malloc (3 * sizeof (heapElem));
  nHeap->size= 0;
  nHeap->capac= 3;
   return nHeap;
}
