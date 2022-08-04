
// *p --> value at this p -> address stover in p  &p --> address of pointer
#include <stdio.h>
void fun(int *p)  
{ 
  int q = 10; 
  p = &q;     
}
      
void fun1(int **p)  
{ 
  int q = 10; 
 *p = &q;     
}   
int main()  
{  
  int r = 20; 
  int *p = &r;
  printf("%p  %p %p\n", p, &p, &r);
  fun(p);
  printf("%d\n", *p);
  fun1(&p);
  printf("%d\n", *p);
  return 0;  
}
