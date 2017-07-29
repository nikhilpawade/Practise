#include <stdio.h>
  #include <string.h>
  #define MAX 256

  int main() {
        FILE *fp1, *fp2;
        char word[MAX], fname[MAX];
        char string[MAX], replace[MAX];
        char temp[] = "temp.txt", *ptr1, *ptr2;

        /* get the input file from the user */
        printf("Enter your input file name:");
        fgets(fname, MAX, stdin);
        fname[strlen(fname) - 1] = '\0';

        /* get the word to delete from the user */
        printf("Enter the word to be replaced:");
        scanf("%s", word);

        /* get the word to replace */
        printf("Enter your replace word:");
        scanf("%s", replace);

        /* open input file in read mode */
        fp1 = fopen(fname, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open the input file!!\n");
                return 0;
  }

        /* open temporary file in write mode */
        fp2 = fopen(temp, "w");

        /* error handling */
        if (!fp2) {
                printf("Unable to open temporary file!!\n");
                return 0;
        }

        /* delete the given word from the file */
        while (!feof(fp1)) {
                strcpy(string, "\0");
                /* read line by line from the input file */
                fgets(string, MAX, fp1);

                /*
                 * check whether the word to delete is
                 * present in the current scanned line
                 */
                if (strstr(string, word)) {
                        ptr2 = string;
                        while (ptr1 = strstr(ptr2, word)) {
                                /*
                                 * letters present before
                                 * before the word to be replaced
                                 */
                                while (ptr2 != ptr1) {
                                        fputc(*ptr2, fp2);
                                        ptr2++;
                                }
 /* skip the word to be replaced */
                                ptr1 = ptr1 + strlen(word);
                                fprintf(fp2, "%s", replace);
                                ptr2 = ptr1;
                        }

                        /* characters present after the word to be replaced */
                        while (*ptr2 != '\0') {
                                fputc(*ptr2, fp2);
                                ptr2++;
                        }
                } else {
                        /*
                         * current scanned line doesn't 
                         * have the word that need to be replaced
                         */
                        fputs(string, fp2);
                }
        }

        /* close the opened files */
        fclose(fp1);
        fclose(fp2);

        /* remove the input file */
        remove(fname);
        /* rename temporary file name to input file name */
        rename(temp, fname);
        return 0;
  }
