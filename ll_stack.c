#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    void *val;
    struct node *next;  
};

void push(struct node** top, void *new_val, size_t val_size)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Malloc failed for new node!\n");
        exit(EXIT_FAILURE);
    }

    new_node->val = malloc(val_size);
    if (new_node->val == NULL)
    {
        fprintf(stderr, "Malloc failed for new node's value!\n");
        exit(EXIT_FAILURE);
    }

    new_node->next = (*top);

    memcpy(new_node->val, new_val, val_size);
 
    (*top) = new_node;

    return;
}

// User of pop is responsbile to free memory pointed to by the returned pointer
void *pop(struct node** top)
{
    if (!*top)
    {
        fprintf(stderr, "Popping from an empty stack!\n");
        exit(EXIT_FAILURE);
    }

    struct node *pop_node = (*top);
    void *pop_val = NULL;

    (*top) = (*top)->next;

    pop_node->next = NULL;
    
    pop_val = pop_node->val;

    free(pop_node);
    
    return pop_val;
}

void *peek(struct node** top)
{
    if (!*top)
    {
        fprintf(stderr, "Peeking an empty stack!\n");
        exit(EXIT_FAILURE);
    }
    
    void *pop_val = NULL;
    pop_val = (*top)->val;

    return pop_val;
}

int main()
{
    struct node *top = NULL;

    int p = 6;
    int q = 7;
    int r = 8;
    char s = 't'; // Support different data types
    int t = 10;
    int u = 11;

    push(&top, &p, sizeof(int));
    push(&top, &q, sizeof(int));
    push(&top, &r, sizeof(int));
    push(&top, &s, sizeof(char));
    push(&top, &t, sizeof(int));

    
    int *a = (int*) peek(&top);
    int *b = (int*) pop(&top);
    char *c = (char*) peek(&top);
    char *d = (char*) pop(&top);
    int *e = (int*) peek(&top);
    int *f = (int*) pop(&top);
    int *g = (int*) peek(&top);
    int *h = (int*) pop(&top);
    int *i = (int*) peek(&top);
    int *j = (int*) pop(&top);
    // Peeking and Popping element from an empty stack
    // int *k = (int*) peek(&top);
    // int *l = (int*) pop(&top);

    printf("Element peeked: %d\n", *a);
    printf("Element popped: %d\n", *b);
    printf("Element peeked: %c\n", *c);
    printf("Element popped: %c\n", *d);
    printf("Element peeked: %d\n", *e);
    printf("Element popped: %d\n", *f);
    printf("Element peeked: %d\n", *g);
    printf("Element popped: %d\n", *h);
    printf("Element popped: %d\n", *i);
    printf("Element popped: %d\n", *j);

    // Have to free memory of popped elements
    free(b);
    free(d);
    free(f);
    free(h);
    free(j);




    return 0;
}



