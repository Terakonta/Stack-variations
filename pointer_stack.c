#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int max_size; // Size of  stack
    int top; // Index of element on top of stack
    void *elements; // Pointer to address with several void* to support different data types
};
 

struct stack* create_stack(int max_size)
{
    struct stack *stack_ptr = (struct stack*) malloc(sizeof(struct stack));
    if (stack_ptr == NULL)
    {
        fprintf(stderr, "Malloc failed for stack!\n");
        exit(EXIT_FAILURE);
    }
 
    stack_ptr->max_size = max_size;
    stack_ptr->top = -1;
    stack_ptr->elements = malloc(max_size * sizeof(void*));
    if (stack_ptr->elements == NULL)
    {
        fprintf(stderr, "Malloc failed for stack elements!\n");
        exit(EXIT_FAILURE);
    }
 
    return stack_ptr;
}
 

void push(struct stack *stack_ptr, void *new_element)
{
    // If stack full, warn user
    if (stack_ptr->top == stack_ptr->max_size - 1)
    {
        fprintf(stderr, "Stack full! Can't push more elements onto it.\n");
        exit(EXIT_FAILURE);
    }

    stack_ptr->top++;

    void **top_pointer = (stack_ptr->elements + stack_ptr->top * sizeof(void*));

    *top_pointer = new_element;

    return;

}
 

void* peek(struct stack *stack_ptr)
{   

    if (stack_ptr->top == -1)
    {
        fprintf(stderr, "Peeking at an empty stack.\n");
        exit(EXIT_FAILURE);
    }
    
    void** top_element = NULL;
    top_element = (stack_ptr->elements + (stack_ptr->top * sizeof(void*)));
    
   
   return *top_element;
}
 

void* pop(struct stack *stack_ptr)
{
    if (stack_ptr->top == -1)
    {
        fprintf(stderr, "Popping from an empty stack!\n");
        exit(EXIT_FAILURE);
    }
    
    void** top_element = NULL;
    
    top_element = (stack_ptr->elements + (stack_ptr->top * sizeof(void*)));
    (stack_ptr->top)--;
    
   
   return *top_element;
}
 
int main()
{
    // create a stack of capacity 5
    struct stack *stack_ptr = create_stack(5);
 
    int p = 6;
    int q = 7;
    int r = 8;
    char s = 't'; // Support different data types
    int t = 10;
    int u = 11;

    push(stack_ptr, &p);
    push(stack_ptr, &q);
    push(stack_ptr, &r);
    push(stack_ptr, &s);
    push(stack_ptr, &t);
    // Pushing element in a full stack
    // push(stack_ptr, &u);

    
    int a = *(int*) peek(stack_ptr);
    int b = *(int*) pop(stack_ptr);
    char c = *(char*) peek(stack_ptr);
    char d = *(char*) pop(stack_ptr);
    int e = *(int*) peek(stack_ptr);
    int f = *(int*) pop(stack_ptr);
    int g = *(int*) peek(stack_ptr);
    int h = *(int*) pop(stack_ptr);
    int i = *(int*) peek(stack_ptr);
    int j = *(int*) pop(stack_ptr);
    // Peeking and Popping element from an empty stack
    // int k = *(int*) peek(stack_ptr);
    // int l = *(int*) pop(stack_ptr);

    printf("Element peeked: %d\n", a);
    printf("Element popped: %d\n", b);
    printf("Element peeked: %c\n", c);
    printf("Element popped: %c\n", d);
    printf("Element peeked: %d\n", e);
    printf("Element popped: %d\n", f);
    printf("Element peeked: %d\n", g);
    printf("Element popped: %d\n", h);
    printf("Element popped: %d\n", i);
    printf("Element popped: %d\n", j);



    free(stack_ptr->elements);
    free(stack_ptr);
 
    return EXIT_SUCCESS;
}