#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FIFO.h"


//Enqueue
 void FIFOq_enqueue (FIFOQueue_p queue, PCB pcb) {
 	//create a new node
 	Node* newNode = (Node*) malloc (sizeof(Node));
 	newNode->pcb = pcb; //assign pcb to new node
 	newNode->next = NULL;

 	if(queue->head == NULL) { //no head
 		queue->head = newNode; //assign the newNode to head
 	} else {
 		queue->tail->next = newNode;
 	}

 	queue->tail = newNode;
 	queue->size++;
 }

//Dequeue
 PCB FIFOq_dequeue (FIFOQueue_p queue) {

     Node* head = queue->head; //returns the first pcb
     PCB pcb;

    if(isempty(queue)) {
        printf("empty list. \n");
    } else {
        pcb = head->pcb;
 	      //moves head pointer to the next node
 	    queue->head = head->next;
 	      //decrease size
 	    queue->size--;

 	    //DONT FORGET TO FREE THE MEMORY
 	    free(head);
    }

    return pcb;

 }

//Peek
 PCB peek (FIFOQueue_p queue){
 	PCB currPcb = queue->head->pcb;
 	return currPcb;
 }

//is empty
int FIFOq_is_empty(FIFOQueue_p queue) {

    if(queue->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

//displays pcb size if there's any queue (Did it to test)
 void FIFOq_toString (FIFOQueue_p queue) {

 	printf("\nDisplay function: \n" );

 	//if list is empty
 	if(isempty(queue)) {
 		printf("empty list. \n");
 	} else { //else
	 	PCB currPcb = queue->head->pcb;
 		int size = queue->size;
 		printf("queue size: %d \n", queue->size); //try with size
 		int i;
 		for(i = 0; i < size; i++) {
 			if(i > 0)
 				printf(", ");
 			printf("PCB priority number: %d \n", currPcb.priority);
 			queue->head = queue->head->next;
 		}
 	}
 	printf("\n\n");
 }


 //creat new processess (create and fill in the contents of a PCB)
 PCB* createPcb(int prior) {
 	PCB *newPcb;
 	newPcb = (PCB *)malloc(sizeof(PCB));
 	newPcb->priority = prior;
 	return newPcb;
 }

//creates and initialize queue.
FIFOQueue_p FIFOq_contsruct() {
	FIFOQueue_p queue = malloc(sizeof(FIFOQueue));
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void FIFOq_destruct(FIFOQueue_p queue) {
	
}


int main () {
	Queue priorityQueue = initializeQueue();
	int userprioNumb;

	printf("Enter a priority number: \n");
	scanf("%d", &userprioNumb);

		if(userprioNumb >= 0) {
			PCB *pcb = createPcb(userprioNumb);
			priorityQueue.enqueue(&priorityQueue, *pcb);

            printf("\nAfter Enqueue:");
            priorityQueue.display(&priorityQueue);

            printf("After Dequeue: \n");
            priorityQueue.dequeue(&priorityQueue);


		} else {
			printf("program ends\n");
		}
}
