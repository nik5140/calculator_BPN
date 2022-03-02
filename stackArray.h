#ifndef STACKARRAY_H_INCLUDED
#define STACKARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct stack_structure
{
    double *elements;
    int last_filled;
} stack_structure;


struct stack_structure Create_stack(int n)
{
    struct stack_structure stack1;
    stack1.last_filled=-1;
    stack1.elements = (double*)malloc(sizeof(double)*n);
    return stack1;
}

void Push_stack(struct stack_structure *stack1, double element)
{
    stack1->elements[stack1->last_filled+1] = element;
    stack1->last_filled++;
}

float Top_stack(struct stack_structure *stack1)
{
   return stack1->elements[stack1->last_filled];
}

int Pop_stack(struct stack_structure *stack1)
{
   if (stack1->last_filled>=0)
   {double popped;
   popped = stack1->elements[stack1->last_filled];
   stack1->elements[stack1->last_filled] = 0;
   stack1->last_filled--;
   return popped;}
   else
   {
        printf("Nothing to return\n");
        return 0;
   }

}

int IsEmpty(struct stack_structure stack1)
{
    if (stack1.last_filled>=0)
        return 0;
    else
        return 1;
}


void ShowStack(struct stack_structure stack1)
{
int n = 0;
printf("[");
while(n<=stack1.last_filled)
{
if (n<stack1.last_filled)
    printf("%3.1lf, ", stack1.elements[n]);
else
    printf("%3.1lf", stack1.elements[n]);


n++;

}
printf("]");

}

#endif // STACKARRAY_H_INCLUDED
