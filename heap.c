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
  arrai->heapArray[arrai->size-1].priority= priority;
  arrai->heapArray[arrai->size-1].data= data;
  
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
