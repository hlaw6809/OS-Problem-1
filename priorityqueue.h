#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "pcb.h"
#include "fifoqueue.h"

#define PRIORITY_COUNT 16;

typedef struct priorityqueue {
	FIFOq_p priorities[PRIORITY_COUNT];
} PriorityQueue;

typedef PriorityQueue * PriorityQueue_p;

PriorityQueue_p PriorityQueue_construct(void);

void PriorityQueue_destruct(PriorityQueue_p);

PriorityQueue_p PriorityQueue_dequeue(PriorityQueue_p);

void PriorityQueue_enqueue(PriorityQueue_p, PCB_p pcb);

int PriorityQueue_is_empty(PriorityQueue_p);

char * PriorityQueue_toString(PriorityQueue);

#endif // PRIORITY_QUEUE_H_