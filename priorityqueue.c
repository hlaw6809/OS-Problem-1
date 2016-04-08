#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "priorityqueue.h"

PriorityQueue_p PriorityQueue_construct(void) {
	PriorityQueue_p queue = calloc(1, sizeof(PriorityQueue));
	queue->priorities = malloc(PRIORITY_COUNT * sizeof(FIFOq_p));
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		queue->priorities[i] = FIFOq_construct();
	}
	return queue;
}


void PriorityQueue_destruct(PriorityQueue_p queue) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_destruct(queue->priorities[i]);
	}
	free(queue->priorities);
	free(queue);
}


void PriorityQueue_enqueue(PriorityQueue_p queue, PCB_p pcb) {
	int priorityLevel = pcb->priority;
	FIFOq_enqueue(queue->priorities[priorityLevel], pcb);
}


PCB_p PriorityQueue_dequeue(PriorityQueue_p queue) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_p fifoQueue = queue->priorities[i];
		if (!FIFOq_is_empty(fifoQueue)) {
			return FIFOq_dequeue(fifoQueue);
		}
	}
}


int PriorityQueue_is_empty(PriorityQueue_p queue) {
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_p fifoQueue = queue->priorities[i];
		if (!FIFOq_is_empty(fifoQueue)) {
			return 0;
		}
	}
	
	return 1;
}


char * PriorityQueue_toString(PriorityQueue_p queue) {
	char * string = calloc(15000, 1);
	int i;
	for (i = 0; i < PRIORITY_COUNT; i++) {
		FIFOq_p fifoQueue = queue->priorities[i];
		if (!FIFOq_is_empty(fifoQueue)) {
			char * qString = malloc(1000);
			sprintf(qString, "Q%d: %s\n", i, FIFOq_toString(fifoQueue));
			strcat(string, qString);
		}
	}
	return string;
}