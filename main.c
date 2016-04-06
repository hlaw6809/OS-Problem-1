#include "priorityqueue.h"
#include "pcb.h"


int main(char *args) {
	printf("Starting contructing Priority Queue\n");
	PriorityQueue_p queue = PriorityQueue_construct();
	printf("Finishing constructing Priority Queue\n\n");
	
	PCB_p pcb1 = PCB_construct();
	PCB_init(pcb1);
	PCB_set_pid(pcb1, 1);
	pcb1->priority = 12;
	PriorityQueue_enqueue(queue, pcb1);
	
	PCB_p pcb2 = PCB_construct();
	PCB_init(pcb2);
	PCB_set_pid(pcb2, 2);
	pcb2->priority = 9;
	PriorityQueue_enqueue(queue, pcb2);
	
	printf("Testing to string\n");
	char * string = PriorityQueue_toString(queue);
	printf(string);
	free(string);
	
	PCB_p dequeuedPCB = PriorityQueue_dequeue(queue);
	printf("Dequeued PCB %u\n", dequeuedPCB->pid);
	PCB_destruct(dequeuedPCB);
	
	dequeuedPCB = PriorityQueue_dequeue(queue);
	printf("Dequeued PCB %u\n", dequeuedPCB->pid);
	PCB_destruct(dequeuedPCB);
	
	PCB_p pcb3 = PCB_construct();
	PCB_init(pcb3);
	PCB_set_pid(pcb3, 3);
	pcb3->priority = 15;
	PriorityQueue_enqueue(queue, pcb3);
	
	dequeuedPCB = PriorityQueue_dequeue(queue);
	printf("Dequeued PCB %u\n\n", dequeuedPCB->pid);
	PCB_destruct(dequeuedPCB);
	
	printf("Starting destructing Priority Queue\n");
	PriorityQueue_destruct(queue);
	printf("Finishing destructing Priority Queue\n");
	return 0;
}