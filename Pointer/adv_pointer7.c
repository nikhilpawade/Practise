#include <stdio.h>

int main(void) 
{ 
    int i; 
    int *ptr = (int *) malloc(5 * sizeof(int)); 
  
    for (i=0; i<5; i++) 
        *(ptr + i) = i; 
  
    printf("%d ", *ptr++); 
    printf("%d ", (*ptr)++); 
    printf("%d ", *ptr); 
    printf("%d ", *++ptr); 
    printf("%d ", ++*ptr); 
} 

/*
Explanation: The important things to remember for handling such questions are

1) Prefix ++ and * operators have same precedence and right to left associativity.

2) Postfix ++ has higher precedence than the above two mentioned operators and  associativity is from left to right.

We can apply the above two rules to guess all

*ptr++ is treated as *(ptr++)


*/
