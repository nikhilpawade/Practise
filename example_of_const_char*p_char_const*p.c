/*const char * p;
char * const p; 
const char * const p;*/ // these are the three conditions,

// const char *p;const char * const p; pointer value cannot be changed

// char * const p; pointer address cannot be changed

// const char * const p; both cannot be changed.

#include<stdio.h>

int main()
{
    const char * p; // value cannot be changed
    char z='a';
    //*p = 'c'; // this will not work
    p = &z;
    printf(" %c\n",*p);

    char * const q = &z; // address cannot be changed
    char x;
   *q = 'c'; 
    //q = &z;   // this will not work
    printf(" %c %c\n",*q,z);

    const char * const a; // both address and value cannot be changed
    char b;
//    *a = 'c'; // this will not work
  //  a = &b; // this will not work
    //printf(" %c\n",*a);
    return 0;
}
