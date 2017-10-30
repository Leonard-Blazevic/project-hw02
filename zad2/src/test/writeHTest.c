#include <stdio.h>
#include "../../inc/io.h"

int main (void) {
 FILE *file;
 short int value = 32;
 short int check = 0;

 file = fopen("file.bin", "wb+");
 
 if(file == NULL) {
 	printf("\nFile does not exist!\n");
 	return -1;
 }

 write_half(file, value);
 fread(&check, sizeof(short), 1, file);
 fclose(file);

 if(check == 0) {
 	printf("Error!");
 	return -1;
 }

 printf("\nTest successful\n");
 printf("\nWritten value: %d\n", check);

 return 0;
}
