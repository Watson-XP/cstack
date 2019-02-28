typedef struct{
    char data;  
    void* next;
} stack;

stack* initStack();

stack* push(stack* st, char x);

extern char pop(stack* st);

extern void deleteStack(stack** st);
