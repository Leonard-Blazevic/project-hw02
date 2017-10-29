#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "../../inc/cmplx.h"
#include "../../inc/testDataGetterFunctions.h"

#define N 10
#define REAL 0
#define IMAG 1

int main () {
	struct ComplexNumber testData[N];
	int i = 0;
	
	fftw_complex z1;
	
	getTestDataFromFile(testData);
	
	for (i=0;i<10;i++) {
		printf("\nTesting for %d. data point...", i+1);
		z1[REAL] = testData[i].real;
		z1[IMAG] = testData[i].imag;

		if(abs(cmplx_phs(z1) - atan((double)testData[i].imag / (double)testData[i].real)) < 0.01)
			printf("\n%d. test passed!", i+1);
		else {
			printf("\nTest failed!");
			return -1;
		}
	}
	printf("\nTest was successful for all data points!");
	
	return 0;
}
