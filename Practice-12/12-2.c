#include <stdio.h>
#include <stdlib.h>

struct stack{
   int *stack_ptr;
   int top;
   int max_size;
};


void stack_init(struct stack *s, int size){
(*s).stack_ptr = (int *) malloc(size * sizeof(int));
(*s).top = 0;
(*s).max_size = size;
}

void stack_destroy(struct stack *s){
free((*s).stack_ptr);
}

void push(int elem, struct stack *s){
/* You need to check whether the stack is full before pushing into the stack.
If it's full, print "Stack is full!\n" on the screen.
Otherwise, push elem into stack, and remember doing top++ to record how many numbers has been pushed.
*/
if((*s).top < (*s).max_size)
{
    for(int i = (*s).top; i >= 0; i--)
    {
        *( (*s).stack_ptr + i+1) = *( (*s).stack_ptr + i);
    }
    *( (*s).stack_ptr) = elem;
    (*s).top++;
}
else
{
    printf("Stack is full!\n");
}

}

void show_stack(struct stack *s){
/* You need to check whether the stack is empty.
If it's empty, print "Empty" on the screen.
Otherwise, print all elements in the stack separated by a whitespace.
*/
if((*s).top <= 0)
{
    printf("Empty\n");
}
else
{
    for(int i = 1; i <= (*s).top; i++)
    {
        printf("%d ", *((*s).stack_ptr + (*s).top -i));
    }
    printf("\n");
}
}

int pop(struct stack *s){
/* You need to check whether the stack is empty before popping.
If it's empty, print "Stack is empty!\n" on the screen and return -100000.
Otherwise, pop the latest element from the stack and return it.
*/
if((*s).top > 0)
{
    int temp = *((*s).stack_ptr);
    for(int i = 0; i < (*s).top-1 ; i++)
    {
        *( (*s).stack_ptr + i) = *( (*s).stack_ptr + i+1);
    }
    (*s).top--;
    return temp;
}
else
{
    printf("Stack is empty!\n");
    return -100000;
}
}

int main(){
   struct stack s1;
   int temp;
   int n;
   scanf("%d",&n);
   stack_init(&s1, n);
   printf("Push an integer in stack_ptr:\n");
   push(5, &s1);
   push(10, &s1);
   push(15, &s1);
   push(20, &s1);
   push(25, &s1);
   push(30, &s1);
   show_stack(&s1);
   printf("Pop an integer from stack_ptr:\n");
   temp = pop(&s1);
   show_stack(&s1);
   temp = pop(&s1);
   show_stack(&s1);
   temp = pop(&s1);
   show_stack(&s1);
   temp = pop(&s1);
   show_stack(&s1);
   temp = pop(&s1);
   show_stack(&s1);
   stack_destroy(&s1);
   return 0;
}
