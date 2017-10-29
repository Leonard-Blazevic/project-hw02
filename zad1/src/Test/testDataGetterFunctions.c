#include<stdio.h>
#include <stdlib.h>
#include "../../inc/testDataGetterFunctions.h"

#define N 10
#define TESTFILENAME "complexNumbers.txt"

void getTestDataFromFile(ComplexNumber* numbers) {
	FILE *file;
	size_t nread;
	char buf;
	int i=0;
	int j=0;
	int k=1;
	
	file = fopen(TESTFILENAME, "r");

	if (file) {
		printf("\nFile found!");
		
		numbers[i].real = numbers[i].imag = numbers[i].squareAmp = 0;
		
    	while ((nread = fread(&buf, 1, sizeof buf, file)) > 0) {
    		if (buf == ','){
    			i++;
    			j=0;
    			k = 1;
    			numbers[i].real = numbers[i].imag = numbers[i].squareAmp = 0;
			}	
    		else if (buf == ' '){
    			j++;
    			k = 1;
			}	
    		else{
    			if(j==0){
    				numbers[i].real = numbers[i].real * k + atoi(&buf);
				}	
    			if(j==1){
    				numbers[i].imag = numbers[i].imag * k + atoi(&buf);
				}	
    			if(j==2){
    				numbers[i].squareAmp = numbers[i].squareAmp * k + atoi(&buf);
				}
    			k = 10;
			}
		}
        	
    	if (ferror(file)) {
        	printf("\nThere was an error while processing the test file!");
    	}
    	fclose(file);
	}
}
