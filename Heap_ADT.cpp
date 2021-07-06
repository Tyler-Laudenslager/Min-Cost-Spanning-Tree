/*! \file Heap_ADT.cpp
    \brief Minimum Binary Heap ADT Implementation

    \author Dr.Spiegel

    Adapted by Tyler Laudenslager
*/

// File: Heap_ADT.cpp
// Array Heap ADT implementation

#include <queue> 
#include "Heap_ADT.h"
#include "Edge.h"

//Constructor - sets eltsInHeap to zero
template <class heapEltType> 
	HeapADT<heapEltType>::HeapADT() : eltsInHeap(0)
{eltsInHeap=0;}

 // Get for printing
 template <class heapEltType> 
	vector<heapEltType>  HeapADT<heapEltType>::getData() const
 { return(heap);}
 
//insert value into the heap
template <class heapEltType>
	void HeapADT<heapEltType>::insertToHeap(heapEltType elt)
{//heap[eltsInHeap++]=elt;
 heap.push_back(elt);
 eltsInHeap++;
 if (eltsInHeap>1)
   reheapUp();
}

//removes value from the top of the heap
template <class heapEltType>
 void HeapADT<heapEltType>::removeFromHeap(heapEltType &elt)
{elt=heap[0];
 heap[0]=heap[--eltsInHeap];
 // Keep heap fully used
 heap.pop_back();
 reheapDown();
}

//returns true if heap is empty else false
template <class heapEltType>
	int HeapADT<heapEltType>::isHeapEmpty()
{return((eltsInHeap==0));
}

//maintains the heap adt invariant with the lowest value on top
template <class heapEltType>
 void HeapADT<heapEltType>::reheapUp()
{int eltIndex=eltsInHeap-1;
 while(eltIndex>=0 && heap[eltIndex]<heap[parentOfNode(eltIndex)]) {
  swap(heap[eltIndex],heap[parentOfNode(eltIndex)]);
  eltIndex=parentOfNode(eltIndex);
 }
}

//maintains the heap adt invariant with the lowest value on top
template <class heapEltType>
 void HeapADT<heapEltType>::reheapDown()
{int eltIndex=0,MaxIndex,Done=0;
 do {
  MaxIndex=minChild(eltIndex);
  if (MaxIndex>0 && heap[eltIndex]>heap[MaxIndex])  {
   swap(heap[eltIndex],heap[MaxIndex]);
   eltIndex=MaxIndex;
  }
  else Done=1;
 } while (!Done);
}

//returns index of the parent of a node
template <class heapEltType>
 int HeapADT<heapEltType>::parentOfNode(int Index)
{if (Index>0)
  return((Index-1)/2);
 return(-1);
}

//returns the index of the left child
template <class heapEltType>
 int HeapADT<heapEltType>::leftChild(int Index) const
{if (Index*2+1<eltsInHeap)
  return(Index*2+1);
 return(-1);
}

//returns the index of the right child
template <class heapEltType>
 int HeapADT<heapEltType>::rightChild(int Index) const
{if (Index*2+2<eltsInHeap)
  return(Index*2+2);
 return(-1);
}

//returns the lesser of the two childern
template <class heapEltType>
 int HeapADT<heapEltType>::minChild(int Index)
{if (leftChild(Index)>0 && rightChild(Index)>0) {
  if (heap[leftChild(Index)]<heap[rightChild(Index)])
   return(leftChild(Index));
  return(rightChild(Index));
 }
 if (leftChild(Index)>0) return(leftChild(Index));
 if (rightChild(Index)>0) return(rightChild(Index));
 return(-1);
}


//swaps the locations of two values
template <class heapEltType>
 void HeapADT<heapEltType>::swap(heapEltType &x,heapEltType &y)
{heapEltType temp;
 temp=x;
 x=y;
 y=temp;
} 

//absolutely necessary line
template class HeapADT<Edge>;
