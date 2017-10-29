#include <stdio.h>
#include <io.h>

int read_word(int fd) {
 int result, n;
 
 n = fread(&result, sizeof(int), 1, fd);

 if(n<1)
   printf("Reading word failed!");

 return result;
}

short read_half(int fd) {
 int n;
 short int result;

 n = fread(&result, sizeof(short), 1, fd);
 
 if(n<1)
   printf("Reading halfword failed!");

 return result;
}

void write_word(int fd, int word) {
 int n;

 n = fwrite(&word, sizeof(word), 1, fd);
 
 if(n<1)
   printf("Writing word failed!");
}

void write_half(int fd, short word) {
 int n;

 n = fwrite(&word, sizeof(word), 1, fd);
 
 if(n<1)
   printf("Writing halfword failed!");
}

