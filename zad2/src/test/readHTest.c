#include <stdio.h>
#include "../../inc/io.h"

int main (void) {
 FILE *file;
 short int value;

 file = fopen("file.bin", "rb");
 
 if(file == NULL)
   printf("File does not exist!");

 value = read_half(file);
 fclose(file);
 printf("Read value: %h\n", value);
 
 return 0;
}
