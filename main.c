#include "priorityqueue.h"
#include "pcb.h"
#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>

void randomizePCB(PCB_p pcb) {
	int pid = rand();
	PCB_set_pid(pcb, pid);
	int priority = rand() % 16;
	pcb->priority = priority;
	pcb->pc = rand();
	pcb->state = ready;
}

void pcbTest() {
	printf("Starting PCB test:\n");
	PCB_p pcb = PCB_construct();
	PCB_init(pcb);
	printf("Initial PCB:\n%s\n",PCB_toString(pcb));
	randomizePCB(pcb);
	printf("Modified PCB:\n%s\n",PCB_toString(pcb));
	PCB_destruct(pcb);
	printf("Ending PCB test\n\n");
}

void fifoTest() {
	printf("Starting FIFO Queue test:\n");
	FIFOq_p queue = FIFOq_construct();
	
	int size = (rand() % (30 - 20)) + 20;
	PCB_p * pcbs = malloc(size * sizeof(PCB_p));
	
	printf("\nEnqueueing\n");
	int i;
	for (i = 0; i < size; i++) {
		pcbs[i] = PCB_construct();
		PCB_init(pcbs[i]);
		randomizePCB(pcbs[i]);
		FIFOq_enqueue(queue, pcbs[i]);
		printf("Q:%s : ", FIFOq_toString(queue));
		printf("%s\n\n", PCB_toString(pcbs[i]));
	}
	
	printf("\nDequeueing\n");

	for (i = 0; i < size; i++) {
		printf("Q:%s : ", FIFOq_toString(queue));
		printf("%s\n", PCB_toString(pcbs[i]));
		
		PCB_p pcb = FIFOq_dequeue(queue);
		
		printf("Q:%s : ", FIFOq_toString(queue));
		printf("%s\n", PCB_toString(pcbs[i]));
		
		printf("contents: %s\n\n", PCB_toString(pcb));
		
		free(pcb);
	}
	
	printf("Ending FIFO Queue test\n\n");
	free(pcbs);
	FIFOq_destruct(queue);
}

void testPriority() {
	printf("Starting Priority Queue test:\n");
	PriorityQueue_p queue = PriorityQueue_construct();
	int size = 100;
	
	PCB_p * pcbs = malloc(size * sizeof(PCB_p));
	
	int i;
	for (i = 0; i < size / 10; i++) {
		printf("\nStarting Round %d\n", i);
		
		//Add PCBs
		int j;
		for (j = 0; j < 10; j++){
			pcbs[i] = PCB_construct();
			PCB_init(pcbs[i]);
			randomizePCB(pcbs[i]); 
			PriorityQueue_enqueue(queue, pcbs[i]);
		}
		printf("\nQueue After Enqueues:\n%s", PriorityQueue_toString(queue));
		
		//Remove PCBs
		int toRemove = (rand() % (6 - 4)) + 4;
		printf("\nDequeued PCBs:\n");
		for (j = 0; j < toRemove; j++) {
			PCB_p pcb = PriorityQueue_dequeue(queue);
			printf("%s\n", PCB_toString(pcb));
			free(pcb);
		}
		
		printf("\nQueue After Deueue:\n%s", PriorityQueue_toString(queue));
	}
	
	free(pcbs);
	PriorityQueue_destruct(queue);
	printf("Ending Priority Queue test\n");
}

int main(char *args) {
	pcbTest();
	fifoTest();
	testPriority();
	return 0;
}