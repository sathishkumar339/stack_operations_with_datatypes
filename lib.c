#include "stack.h"

stack_t *open_stack(int nmax,int size)
{
	stack_t *s =NULL;
	if((nmax <= MIN_ITEMS) || (nmax >= MAX_ITEMS)) {
	fprintf(stderr,"nmax should be in range of %d .. %d\n",MIN_ITEMS,MAX_ITEMS);
	}	
	
	if(size <= 0) {
		fprintf(stderr,"size is should be greater than 0");
		return NULL;
	}

	if((s = malloc(sizeof *s)) == NULL) {
		fprintf(stderr,"Failed to allocate Memory for stack\n");
		return NULL;
	}

	printf("nmax = %d, size = %d\n",nmax,size);	
	s->start = malloc(nmax * size);
	if(s->start == NULL) {
		fprintf(stderr,"Failed to allocate Memory");
		free(s);
		return NULL;
	}

	s->end = s->start + (nmax * size);
	s->sp = s->start;
	s->nitems = 0;
	s->nmax = nmax;
	s->size = size;

	return s;
}

int push(stack_t *sd, void *data)
{
	if(is_stack_full(sd)) {
		fprintf(stderr,"stack is full, no more to push\n");
		return S_FULL;
	}
	memcpy(sd->sp,data,sd->size);
	sd->sp += sd->size;
	sd->nitems++;
	return S_SUCCESS;
}

int pop(stack_t *sd, void *data)
{
	if(is_stack_empty(sd)) {
		fprintf(stderr,"stack is empty,no items to pop\n");
		return S_EMPTY;
	}
	
	sd->sp -= sd->size;
	memcpy(data,sd->sp,sd->size);
	sd->nitems--;
	return S_SUCCESS;
}

int close_stack(stack_t *sd)
{
	free(sd->start);
	free(sd);
}

				

