#include <stdio.h>
#include "../../inc/io.h"

int main (void) {
 FILE *file;
 int n;
 short int value = 32;
 short int check;

 file = fopen("file.bin", "wb+");
 
 if(file == NULL)
   printf("File does not exist!");

 write_half(file, value);
 n = fread(&check, sizeof(short), 1, file);
 fclose(file);

 if(n<1)
   printf("Error!");
 
 printf("Written value: %h", check);

 return 0;
}
