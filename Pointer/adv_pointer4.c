#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
void fun(char** str_ref) 
{ 
    str_ref++; 
}
 
void fun1(char** str_ref) 
{ 
    (*str_ref)++; 
} 
int main() 
{ 
    char *str = (void *)malloc(100*sizeof(char)); 
    printf("%p\n", str);
    strcpy(str, "GeeksQuiz"); 
    fun(&str);
    printf("%p\n", str);
    puts(str); 
    fun1(&str); 
    printf("%p\n", str);
    puts(str); 
    free(str); 
    return 0; 
} 
