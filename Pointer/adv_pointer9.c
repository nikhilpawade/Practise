#include <stdio.h> 
int main() 
{ 
    int a[4][5][6]; 
    int x = 0; 
    int* a1 = &x; 
    int** a2 = &a1; 
    int*** a3 = &a2; 
    printf("%d %d %d %d\n", sizeof(a), sizeof(a1), sizeof(a2), sizeof(a3)); 
  
    printf("%d ", (char*)(&a1 + 1) - (char*)&a1); 
    printf("%d ", (char*)(&a2 + 1) - (char*)&a2); 
    printf("%d ", (char*)(&a3 + 1) - (char*)&a3); 
    printf("%d \n", (char*)(&a + 1) - (char*)&a); 
  
    printf("%d ", (char*)(a1 + 1) - (char*)a1); 
    printf("%d ", (char*)(a2 + 1) - (char*)a2); 
    printf("%d ", (char*)(a3 + 1) - (char*)a3); 
    printf("%d \n", (char*)(a + 1) - (char*)a); 
  
    printf("%d ", (char*)(&a[0][0][0] + 1) - (char*)&a[0][0][0]); 
    printf("%d ", (char*)(&a[0][0] + 1) - (char*)&a[0][0]); 
    printf("%d ", (char*)(&a[0] + 1) - (char*)&a[0]); 
    printf("%d \n", (char*)(&a + 1) - (char*)&a); 
  
    printf("%d ", (a[0][0][0] + 1) - a[0][0][0]); 
    printf("%d ", (char*)(a[0][0] + 1) - (char*)a[0][0]); 
    printf("%d ", (char*)(a[0] + 1) - (char*)a[0]); 
    printf("%d \n", (char*)(a + 1) - (char*)a); 
} 
