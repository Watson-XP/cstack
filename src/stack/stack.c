#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSTACKS 20

typedef struct __STACK{ 
	char data;  
	void* next;
} stack;

void* AllStacks[MAXSTACKS];
int stackCount = 0;

stack* initStack()
{
	//printf(" infunc ");
	stack* me = (stack*)malloc(sizeof(stack));
	//printf(" malloc");
	me->data = '\x0';
	//printf(" data");
	me->next = NULL;
	//printf(" next");
	
	stackCount++;
	AllStacks[stackCount-1] = me;
	return me;
}

stack* push(stack* st, char x)
{
	stack* ni = (stack*)malloc(sizeof(stack));//initStack();
	ni->next = st;
	ni->data = x;
	for (int z = 0; z < stackCount; z++)
	{
		if (AllStacks[z] == st)
			AllStacks[z] = ni;
	}
	printf("st=%p, AS=%p\n",ni,  AllStacks[0]);
	return ni;
}

char pop(stack* st)
{
	if (st == NULL) return ' ';
	char x = st->data;
	//memcpy(&x,(char*)st->data,1);
	//free(st->data);
	stack *tmp = st->next;
	memcpy(st, st->next, sizeof(stack));    //free(st);
	free(tmp);
	return x;
}



void clearStack(stack* st)
{
	if (st == NULL) return;

	int z = stackCount-1; 
	while (z >= 0)
   //for (int z = 0; z < stackCount; z++)
	{
		if (AllStacks[z] == st)
		{
			printf("Dealloc stack #%d.", z+1);
			stackCount--;
			z = 0;
		}

		z--;
	}
	stack* tmp;
	printf("dropstack\n");
	while (st != NULL)
	{
		tmp = st;
		st = tmp->next;
		printf("deleted: %c\n", tmp->data);
		tmp->next = NULL;
		free(tmp);
	}
}

void deleteStack(stack** st)
{
	clearStack(*st);
	*st = NULL;
}

void __attribute__ ((constructor)) initLibrary(void) {
 //
 // Function that is called when the library is loaded
 //
	printf("Library is initialized\n"); 
	//AllStacks = (stack**)malloc(100*sizeof(stack*));
 //   AllStacks = NULL;
}
void __attribute__ ((destructor)) cleanUpLibrary(void) {
 //
 // Function that is called when the library is »closed«.
 //

	//if (stackCount>0) printf("Garbage collection.\n");
	while(stackCount > 0)    
	{
		//void* ptr = AllStacks[stackCount-1]; 
		//stack** ptr2 = &((stack*)ptr);
		clearStack(AllStacks[stackCount-1]);
	}
	
	//printf("Library is exited\nFinal stacks: %d\n", stackCount); 
}