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


void heap_pop(Heap* hip){
    if (hip==NULL || hip->heapArray==NULL) return;
    if (hip->size==0 || hip->capac==0) return;
    //case 1
    if (hip->size== 1){
      hip->size--;
      return;
    }
    switchNode(hip);
    heapElem * nodeAux= (heapElem*) malloc (sizeof(heapElem));

    int posi= 0;
    //FormulaHijos 2x+1 / 2x+2         StandBy (posi*2) +1 == (posi*2) +2
    // (2*posi) + 1 < hip->size || (2*posi) + 2 < hip->size )
    while ( (2*posi) + 1 < hip->size || (2*posi) + 2 < hip->size ){ 

      nodeAux->priority= hip->heapArray[posi].priority;
      nodeAux->data= hip->heapArray[posi].data;

      if ( nodeAux->priority < hip->heapArray[posi*2+1].priority ){

          hip->heapArray[posi].priority= hip->heapArray[posi*2 +1].priority;
          hip->heapArray[posi].data= hip->heapArray[posi*2 +1].data;
          hip->heapArray[posi*2 +1].priority= nodeAux->priority;
          hip->heapArray[posi*2 +1].data= nodeAux->data;
          posi= (posi*2)+1;
      }
      else if ( nodeAux->priority < hip->heapArray[posi*2+2].priority ){

          hip->heapArray[posi].priority= hip->heapArray[posi*2 +2].priority;
          hip->heapArray[posi].data= hip->heapArray[posi*2 +2].data;
          hip->heapArray[posi*2 +2].priority= nodeAux->priority;
          hip->heapArray[posi*2 +2].data= nodeAux->data;
          posi= (posi*2)+2;
      }
      else break;
    }
    return;
}

Heap* createHeap(){
    Heap * nHeap= (Heap*) malloc (sizeof(Heap));
    nHeap->heapArray= (heapElem*) malloc (3 * sizeof (heapElem));
    nHeap->size= 0;
    nHeap->capac= 3;
    return nHeap;
}

void switchNode(Heap * hip){
  heapElem * nodeAux= (heapElem*) malloc (sizeof(heapElem));
  nodeAux->data= hip->heapArray[0].data;
  nodeAux->priority= hip->heapArray[0].priority;

  hip->heapArray[0].priority= hip->heapArray[hip->size-1].priority;
  hip->heapArray[0].data = hip->heapArray[hip->size-1].data;
  
  hip->heapArray[hip->size-1].priority= nodeAux->priority;
  hip->heapArray[hip->size-1].data= nodeAux->data;

  hip->size--;
  return;
}