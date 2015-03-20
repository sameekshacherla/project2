#ifndef TCB_H
#define TCB_H
#include <ucontext.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 1

typedef struct TCB_t {
	struct TCB_t *next; // Pointer to next element in chain
	struct TCB_t *prev; // Pointer to previous element in chain
	ucontext_t context; // Store information for context switching
} TCB_t;

void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size) {
	//memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
	getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t) stack_size;
	makecontext(&tcb->context, function, 0);// context is now cooked

	return;
}

#endif
