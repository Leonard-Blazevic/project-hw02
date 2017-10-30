#include <stdio.h>
#include "../../inc/io.h"

int main (void) {
 FILE *file;
 short int value;

 file = fopen("file.bin", "rb");
 
 if(file == NULL)
   printf("\nFile does not exist!\n");

 value = read_half(file);
 fclose(file);
 printf("\nRead value: %d\n", value);
 
 return 0;
}
