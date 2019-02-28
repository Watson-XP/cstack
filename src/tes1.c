#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack/stack.h"


void main()
{
	
	printf("TEST\n");
	stack* tst = NULL;
	
	printf("defined ");

	tst = initStack();

	printf("created ");
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'x');
	tst = push(tst, 'y');
	tst = push(tst, 'z');

	printf("pushed ");

	//char x,y,z;
	char x,y,z;
	x = pop(tst);
	y = pop(tst);
	z = pop(tst);
	printf(" from stack: %c, %c, %c\n", x,y,z);

	deleteStack(&tst);// = NULL;// = initStack();
	//tst = (stack*)malloc(10*sizeof(stack));
	//free(tst);
	
	//deleteStack(&tst);
	//deleteStack(&tst);
	z = pop(tst);
	//deleteStack(&tst);
	
}