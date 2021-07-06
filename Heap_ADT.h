/*! \file Heap_ADT.h
    \brief Minimum Binary Heap ADT 

    \author Dr.Spiegel

    Adapted by Tyler Laudenslager
*/

// File: Heap_ADT/h
// Array Heap ADT prototypes
// A heap is a tree structure used to implement priority queues

#ifndef Heap_ADT_H
#define Heap_ADT_H

#include <vector>
#include <iostream>

using namespace std;

/*! \brief Builds HeapADT objects
*/

template <class heapEltType> class HeapADT {

public:

 // Constructor
 /*! \brief Constructor
 */
 HeapADT();
 
 // Get for printing
 /*! \brief get data for printing
 */
 vector<heapEltType> getData() const;
 
 // Add an Item to the Binary Heap
 // Pre: The heap is not full
 // Post: Elt is added to the tree in priority order
 /*! \brief insert a value into heap
     \param elt value to insert into heap
     \returns N/A
 */
 void insertToHeap(heapEltType elt);

 // Remove the Top Item of the Heap
 // Pre: The heap is not empty
 // Post: The top element is removed from the heap into Elt & the heap
 //	is rearranged to maintain order
 /*! \brief remove the top value of the heap
     \param elt value removed from top of heap
     \returns N/A

     variable passed to this function will \n
     contain the removed value from the  \n
     top of the heap when function returns.
 */
 void removeFromHeap(heapEltType & elt);

 // Find out if the heap is empty
 // Returns: 0==>Empty 	Nonzero==>Not Empty
 /*! \brief determines if a heap is empty
     \returns 0 if Empty 1 if Not Empty
 */
 int isHeapEmpty();
 
 private:

 vector<heapEltType> heap;
 int eltsInHeap;

 // Order the heap after a new element is inserted
 /*! \brief maintains order after a element is inserted
     \returns N/A
 */
 void reheapUp();

 // Order the heap after an element is removed
 /*! \brief maintains order after a element is removed
     \returns N/A
 */
 void reheapDown();

 // Return the index of a node's parent
 // Returns -1 if the node is the root
 /*! \brief returns index of a node's parent
     \returns (int) an index
 */
 int parentOfNode(int index);

 // Return the index of a node's left child
 // Returns -1 if the left child is NULL
 /*! \brief return the index of a node's left child
     \returns (int) an index
 */
 int leftChild(int index) const;

 // Return the index of a node's right child
 // Returns -1 if the right child is NULL
 /*! \brief return the index of a node's right child
     \returns (int) an index
 */
 int rightChild(int index) const;

 // Adapted to return the index of the smaller of a node's childern
 // Return the Index of the larger of a node's children
 // Return -1 if the node has no children
 /*! \brief return the index of the smaller of a node's childern
     \return (int) an index.
 */
 int minChild(int index);

 // Swap the 2 arguments
 /*! \brief swaps the location of two values
     \returns N/A
 */
 void swap(heapEltType &x,heapEltType &y);
 
};

#endif
