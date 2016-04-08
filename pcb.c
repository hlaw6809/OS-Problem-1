/*
 * pcb.c
 *
 *  Created on: Apr 4, 2016
 *      Author: Bun Kak
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcb.h"


/* allocate memory for a struct and returns a pcb pointer to heap allocation.
 */
PCB_p PCB_construct (void) {
	  //Node *newNode = malloc(sizeof(Node)) cos Node is a struct, not pointer
	  //PCB_p is a pointer
	  PCB_p pcb = malloc(sizeof(struct PCB));
	  return pcb;
}


/* deallocates pcb from the heap.
 */
void PCB_destruct (PCB_p pcbPointer) {
		free(pcbPointer);
		pcbPointer = NULL;
}


/* sets default values for member data.
 * pcbPointer is a pointer to heap allocation for pcb.
 * return an integer equal 1 if the parameter pcbPointer is not null and
 *        successfully set pcb value to default. Otherwise, return 0 for failure.
 */
int PCB_init (PCB_p pcbPointer) {
	static int pid;
	int succeed = 0;
	if (pcbPointer != NULL) {
		pcbPointer->pid = pid;
		pcbPointer->state = new;
		pcbPointer->priority = 15;
		pcbPointer->pc = 0;
		succeed = 1;
		pid++;
	}
	return succeed;
}


/* set PCB's process ID.
 * pcbPointer is a pointer to heap allocation for pcb.
 * return an integer equal 1 if the parameter pcbPointer is not null and
 *        successfully set pcb process ID #. Otherwise, return 0 for failure.
 */
int PCB_set_pid (PCB_p pcbPointer, unsigned long pid) {
		int succeed = 0;
		if (pcbPointer != NULL) {
			pcbPointer->pid = pid;
			succeed = 1;
		}
		return succeed;
}


/* returns pid of the process.
 * pcbPointer is a pointer to heap allocation for pcb.
 * return an unsigned long represent the process ID #.
 *        Otherwise, return 0 null pointer paramenter.
 */
unsigned long PCB_get_pid (PCB_p pcbPointer) {
	unsigned long id = 0;
	if (pcbPointer != NULL) {
		id = pcbPointer->pid;
	}
	return id;
}


/* returns a string representing the contents of the pcb.
 * pcbPointer is a pointer to heap allocation for pcb.
 */
char * PCB_toString (PCB_p pcbPointer) {

		// get enum string
		char str[12];
		if (pcbPointer->state == new) {
			strcpy(str, ENUM_STRING[new]);
		}	else if (pcbPointer->state == ready) {
			strcpy(str, ENUM_STRING[ready]);
		}	else if (pcbPointer->state == running) {
			strcpy(str, ENUM_STRING[running]);
		}	else if (pcbPointer->state == interrupted) {
			strcpy(str, ENUM_STRING[interrupted]);
		}	else if (pcbPointer->state == waiting) {
			strcpy(str, ENUM_STRING[waiting]);
		}	else if (pcbPointer->state == halted) {
			strcpy(str, ENUM_STRING[halted]);
		}

		//build a complete string
		char * fullStr = malloc(100);
		sprintf(fullStr, "Process ID: %lu. Process State: %s, Priority: %d. PC: %lu",
				pcbPointer->pid, str, pcbPointer->priority, pcbPointer->pc);
		return fullStr;
}



























