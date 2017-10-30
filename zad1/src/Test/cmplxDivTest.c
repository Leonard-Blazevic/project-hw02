#include<stdio.h>
#include<math.h>
#include "../../inc/cmplx.h"
#include "../../inc/testDataGetterFunctions.h"

#define N 10
#define REAL 0
#define IMAG 1

int main () {
	struct ComplexNumber testData[N];
	int i = 0;
	double temp = 0;
	
	fftw_complex z1;
	fftw_complex z2;
	fftw_complex z3;
	
	getTestDataFromFile(testData);
	
	for (i=0;i<5;i++) {
		printf("\nTesting for %d. data point...", i+1);
		z1[REAL] = testData[i].real;
		z1[IMAG] = testData[i].imag;
		z2[REAL] = testData[N-1-i].real;
		z2[IMAG] = testData[N-1-i].imag;
		
		cmplx_div(z1, z2, z3);
		
		temp = testData[N-1-i].real * testData[N-1-i].real + testData[N-1-i].imag * testData[N-1-i].imag;
		
		if((z3[REAL] == ((testData[i].real * testData[N-1-i].real + testData[i].imag * testData[N-1-i].imag))/temp) && (z3[IMAG] == ((testData[i].imag * testData[N-1-i].real - testData[i].real * testData[N-1-i].imag)/temp)))
			printf("\n%d. test passed!", i+1);
		else {
			printf("Test failed!");
			return -1;
		}
	}
	printf("\nTest was successful for all data points!");
	
	return 0;
}
