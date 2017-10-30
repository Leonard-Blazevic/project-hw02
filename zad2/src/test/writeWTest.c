#include <stdio.h>
#include "../../inc/io.h"

int main (void) {
 FILE *file;
 int value = 32;
 int check = 0;

 file = fopen("file.bin", "wb+");
 
 if(file == NULL) {
 	printf("\nFile does not exist!\n");
 	return -1;
 }

 write_word(file, value);
 check = read_word(file);
 fclose(file);

 if(check != value) {
 	printf("Error!");
 	return -1;
 }
  
 printf("\nTest successful\n");
 printf("\nWritten value: %d\n", check);

 return 0;
}
