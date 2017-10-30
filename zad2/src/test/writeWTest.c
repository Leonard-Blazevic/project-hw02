#include <stdio.h>
#include "../../inc/io.h"

#define VALUE 111

int main (void) {
 FILE *file;

 file = fopen("file.bin", "wb+");
 
 if(file == NULL) {
 	printf("\nFile does not exist!\n");
 	return -1;
 }

 write_word(file, VALUE);
  
 printf("\nTest successful\n");
 printf("\nWritten value: %d\n", VALUE);

 return 0;
}
