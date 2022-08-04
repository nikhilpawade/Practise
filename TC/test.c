#include <stdio.h>
int findfileSize(char f_n[]) {

   FILE *fp = fopen(f_n, "r"); // opening a file in read mode
   if (fp == NULL) // checking whether the file exists or not {
      printf("File Not Found!\n");
      return -1;
   }

   fseek(fp, 0L, SEEK_END);

   int res = ftell(fp);
   fclose(fp);
	return res;
}

int main() {
   char f_n[] = { "test.txt" }; //file name is “b.txt” whose size is to be determined
   int result = findfileSize(f_n);
   if (result != -1)
   printf("Size of the file is %ld bytes \n", result); //printing the file size
   return 0;
}
