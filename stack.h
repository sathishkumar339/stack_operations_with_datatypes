#ifndef __STACK_H
#define __STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack_t {
	void *start;
	void *end;
	void *sp;
	int nitems;
	int nmax;
	int size;
}stack_t;

stack_t *open_stack(int nmax, int size);
int push(stack_t *sd,void *data);
int pop(stack_t *sd,void *data);
int close_stack(stack_t *sd);
int PRINT(void *num, int option);
int SCANF(void *num, int option);
int help();

#define is_stack_full(sd) ((sd->nitems) == (sd->nmax))
#define is_stack_empty(sd) ((sd->nitems) == 0)

#define S_FULL (-1)
#define S_EMPTY (-2)
#define S_FAIL (0)
#define S_SUCCESS (1)

#define MIN_ITEMS (0)
#define MAX_ITEMS (1000)

enum {
	PUSH_OP = 1,
	POP_OP,
	EXIT_OP
};
#endif
