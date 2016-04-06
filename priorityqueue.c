#include <stdlib.h>

PriorityQueue_p PriorityQueue_construct(void) {
	PriorityQueue_p queue = calloc(1, sizeof(PriorityQueue));
	return queue;
}

void PriorityQueue_destruct(PriorityQueue_p queue) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_destruct(queue->priorities[i]);
	}
	free(queue);
}

PriorityQueue_p PriorityQueue_dequeue(PriorityQueue_p queue) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_p fifoQueue = queue->priorities[i];
		if (!FIFOq_is_empty(fifoQueue)) {
			return FIFOq_dequeue(fifoQueue);
		}
	}
}

void PriorityQueue_enqueue(PriorityQueue_p queue, PCB_p pcb) {
	int priorityLevel = pcb.priority;
	FIFOq_enqueue(queue->priorities[priorityLevel], pcb);
}

int PriorityQueue_is_empty(PriorityQueue_p) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_p fifoQueue = queue->priorities[i];
		if (!FIFOq_is_empty(fifoQueue)) {
			return 0;
		}
	}
	
	return 1;
}

char * PriorityQueue_toString(PriorityQueue) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_p fifoQueue = queue->priorities[i];
		if (!FIFOq_is_empty(fifoQueue)) {
			return FIFOq_toString(fifoQueue);
		}
	}
}