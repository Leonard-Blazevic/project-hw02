#include <stdio.h>
#include <io.h>

int read_word(FILE *fd) {
 int result;
 
 fread(&result, sizeof(int), 1, fd);

 return result;
}

short read_half(FILE *fd) {
 short int result;

 fread(&result, sizeof(short), 1, fd);

 return result;
}

void write_word(FILE *fd, int word) {
 fwrite(&word, sizeof(word), 1, fd);
}

void write_half(FILE *fd, short word) {
 fwrite(&word, sizeof(word), 1, fd);
}

