#include <stdio.h> 
void f(char**); 
int main() 
{ 
    char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" }; 
    f(argv); 
    return 0; 
} 
void f(char **p) 
{ 
    char *t; 
    t = (p += sizeof(int))[-1]; 
    printf("%s\n", t); 
} 

// The expression (p += sizeof(int))[-1] can be written as (p += 4)[-1] which can be written as (p = p+4)[-] which returns address p+3 which is address of fourth element in argv[].
