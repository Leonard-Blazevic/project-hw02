#include <stdio.h>
#include <io.h>

int read_word(FILE *fd) {
 int result, n;
 
 n = fread(&result, sizeof(int), 1, fd);

 if(n<1)
   printf("Reading word failed!");

 return result;
}

short read_half(FILE *fd) {
 int n;
 short int result;

 n = fread(&result, sizeof(short), 1, fd);
 
 if(n<1)
   printf("Reading halfword failed!");

 return result;
}

void write_word(FILE *fd, int word) {
 int n;

 n = fwrite(&word, sizeof(word), 1, fd);
 
 if(n<1)
   printf("Writing word failed!");
}

void write_half(FILE *fd, short word) {
 int n;

 n = fwrite(&word, sizeof(word), 1, fd);
 
 if(n<1)
   printf("Writing halfword failed!");
}

