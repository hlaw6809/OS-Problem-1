#ifndef FIFO
#define FIFO

#include <stdio.h>
#include <stdlib.h>


/**
 *control_block
 */
typedef struct PCB {
   int priority;

} PCB;

/**
 *The node struct:
 * pcb and pointer to point to next node.
 */

 typedef struct Node {
 	PCB pcb;
 	struct Node* next;
 } Node;


 /*
  * FIFOQueue struct
  */

 typedef struct FIFOQueue {
 	Node* head;
 	Node* tail;
 	int size; //size of the FIFOQueue
 } FIFOQueue;
 
 typedef FIFOQueue * FIFOQueue_p;

 /*
  * FIFOQueue Methods
  */

 FIFOQueue_p FIFOq_contsruct ();
 void FIFOq_deconstruct (FIFOQueue_p);
 void FIFOq_enqueue (FIFOQueue_p, PCB);
 PCB FIFOq_dequeue (FIFOQueue_p);
 PCB peek (FIFOQueue_p);
 char * FIFOq_toString (FIFOQueue_p);
 int FIFOq_is_empty(FIFOQueue_p);


#endif
