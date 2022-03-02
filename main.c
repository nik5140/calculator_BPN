// first example from book on algorithms (Real-World Algorithms)


#include <stdio.h>
#include <stdlib.h>
#include "stackArray.h"
#include <time.h>

int main()
{
    // file pointer
    FILE *f;

    int i =0;
    float x;
    double a,b;
    char *eptr;
    char value[10];
    int n=0;
    char inputData[10];

    printf("Hello. Here is calculator BPN style\n");
    n = 30;
    struct stack_structure S = Create_stack(n);



    printf("on top is %f", Top_stack(&S));

    while(1)
    {
    printf("Enter input data...\n");
    scanf("%s", &inputData);


   // printf("%s", inputData);


    if (inputData[0]=='+'||inputData[0]=='-'||inputData[0]=='*'||inputData[0]=='/')
      {
        printf("sign ... %s\n", inputData);
        a = Pop_stack(&S);
        b = Pop_stack(&S);

        if (inputData[0]=='+')
            Push_stack(&S,a+b);
        else if (inputData[0]=='-')
            Push_stack(&S,b-a);
        else if (inputData[0]=='*')
            Push_stack(&S,a*b);
        else if (inputData[0]=='/+')
            Push_stack(&S,b/a);

      ShowStack(S);
      }


    else if (! strncmp(inputData,"exit",4))
        {ShowStack(S);
        break;
        }


    else
        {
        printf("digit to stack\n");


        Push_stack(&S,strtod(inputData, &eptr));
        ShowStack(S);
      //  Push_stack(&S, 23);
         }





    }
    printf(" on top is %3.2lf\n", Top_stack(&S));
    printf("the end\n");
/*



  */

    return 0;
}

// some problems with time mesaure... should fix it
