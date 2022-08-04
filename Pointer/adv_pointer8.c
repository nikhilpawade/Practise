#include<stdio.h> 
void fun(int arr[]) 
{ 
  int i;
  printf("%d %d\n", sizeof(arr), sizeof(arr[0]));
  int arr_size = sizeof(arr)/sizeof(arr[0]); 
  for (i = 0; i < arr_size; i++) 
      printf("%d ", arr[i]); 
} 
  
int main() 
{ 
  int i; 
  int arr[4] = {10, 20 ,30, 40}; 
  fun(arr);
  printf("\n%d %d\n", sizeof(arr), sizeof(arr[0])); 
  return 0; 
}  
