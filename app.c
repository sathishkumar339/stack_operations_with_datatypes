#include<stdio.h>
#include "stack.h"

int main() {

	int choice,nmax,dtype,numsize ;
	stack_t *sd;
	void *num;	

	printf("Press 1 to store integer\nPress 2 to store Float\nPress 3 to store char\nPress 4 to store Double\n");
	scanf("%d",&dtype);
	
	if(dtype == 1) {
		num = malloc( sizeof(int));
		numsize = sizeof(int);
	} else if (dtype == 2) {
		num = malloc (sizeof(float));
		numsize = sizeof(float);
	}	else if (dtype == 3) {
		num = malloc (sizeof(char));
		numsize = sizeof(char);
	} else if (dtype == 4) {
		num = malloc(sizeof(double));
		numsize = sizeof(double);
	} else {
		printf("Invalid Option\n");
		main();
	}	
	if(num == NULL) {
		printf("Failed to malloc\n");
		exit(1);
	}

	printf("Enter no of items to Push : \t");
	scanf("%d",&nmax);

	if((nmax <= MIN_ITEMS) || (nmax >= MAX_ITEMS)) {
		fprintf(stderr,"No of Items should be between %d .. %d \n",MIN_ITEMS,MAX_ITEMS);
		free(num);
		main();
	}

	sd = open_stack(nmax, numsize);
	if(sd == NULL) {
		fprintf(stderr,"Failed to open stack\n");
		free(num);
		exit(1);
	}

	while(1) {
		help();
		printf("Enter your choice :\t");	
		scanf("%d",&choice);
		
		switch (choice) {
		case PUSH_OP:
				printf("stack is Full sd->nitems = %d,sd->nmax = %d\n",sd->nitems,sd->nmax);
			if(is_stack_full(sd)) {
				printf("stack is Full\n");
			}	else {
				SCANF(num,dtype);
				push(sd,num);
			}
			break;

		case POP_OP:
			if(is_stack_empty(sd)) {
				fprintf(stderr,"stack is empty\n");
			} else {
				pop(sd,num);
				PRINT(num,dtype);
			}
			break;

		case EXIT_OP:
			free(num);
			close_stack(sd);
			printf("Bye\n");
			exit(1);
	
		case 4:
			free(num);
			close_stack(sd);
			main();			
	
		default :
			printf("Invalid choice\n");
			break;
		}
	}
}	

int help() {

	printf(" \nPress 1 for PUSH_OP\n Press 2 for POP_OP\n press 3 for EXIT\nPress 4 to Goback\n");

}		

int SCANF(void *num, int option)	{

	switch (option) {
	case 1:
				printf("Enter the integer to Push : \t");
				scanf("%d",((int *)num));
				break;
	case 2:
				printf("Enter the Float to Push  : \t");
				scanf("%f",((float *) num));
				break;	
	case 3:
				printf("Enter the Char to Push   :\t");
				scanf("%d",((int *) num));
				break;	
	case 4:
				printf("Enter the Double to Push : \t");
				scanf("%lf",((double *)num));
				break;	
	}
}

int PRINT(void *num, int option) {

	switch (option) {	
	case 1:
			printf("Popped integer num is : %d\n",*(int *)num);
			break;
	case 2:
			printf("Popped float num is : %f\n",*(float *)num);
			break;
	case 3:
			printf("Popped char num is : %c\n",*(char *)num);
			break;
	case 4:
			printf("Popped double num is : %lf\n",*(double *)num);
			break;

	}
}

