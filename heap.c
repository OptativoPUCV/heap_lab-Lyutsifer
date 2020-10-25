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


void* heap_top(Heap* hip){
    fflush (stdin);
    if (hip==NULL || hip->heapArray==NULL || hip->size == 0) return NULL;
    void * auxVar= hip->heapArray[0].data;
    return auxVar;
}



void heap_push(Heap* hip, void* data, int priority){

  if (hip== NULL || hip->heapArray== NULL || hip->capac== 0 || data== NULL) return;
  if (hip->capac == hip->size){
    hip->heapArray= (heapElem*) realloc (hip->heapArray , hip->capac * 2+1*sizeof(heapElem) );
    hip->capac*= 2; hip->capac++;
  }
  int posi= hip->size;
  hip->heapArray[posi].priority= priority;
  hip->heapArray[posi].data= data;
  hip->size++;
  if (posi<= 0 ) return;
  int auxPrio2= hip->heapArray[(posi - 1)/2].priority;

  while (priority > auxPrio2){
    //Nodo que guarda data del padre (pos-1)/2
    heapElem * auxNodo = (heapElem*) malloc(sizeof(heapElem));
    auxNodo->data= hip->heapArray[(posi -1)/2].data;
    auxNodo->priority= hip->heapArray[(posi -1)/2].priority;
    //Se reemplaza el nodo nuevo en la posicion del padre
    hip->heapArray [(posi-1) / 2].data= data;
    hip->heapArray [(posi-1) / 2].priority= priority;
    //El padre pasa a la posicion del nuevo nodo, i = size-1
    hip->heapArray[(posi)].priority = auxNodo->priority;
    hip->heapArray[(posi)].data = auxNodo->data;
    //Nueva posicion del nodo
    posi= (posi-1) / 2;
    if (posi<=0 ) break;
    auxPrio2= hip->heapArray[(posi - 1)/2].priority;
     
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
