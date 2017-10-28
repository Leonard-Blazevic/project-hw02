#include<math.h>
#include<stdio.h>
#include "../inc/fftw3.h"

#define REAL 0
#define IMAG 1

int main () {
	struct fftw_complex z1;
	struct fftw_complex z2;
	struct fftw_complex z3;
	
	printf ("Unesite prvi kompleksni broj u formatu Re(z) Im(z): ");
	scanf("%lf %lf", &z1[REAL], &z1[IMAG]);
	printf ("Rez: %lf %lf", &z1[REAL], &z1[IMAG]);
	
	return 0;
}

//(a + ib)/(c + id) = [(a + ib)/(c + id)] * [(c - id)/(c - id)] = [(ac + bd) + i(bc - ad)]/(c^2 + d^2)
void cmplx_div(fftw_complex a, fftw_complex b, fftw_complex *c) {
	*c[REAL] = (a[REAL]*b[REAL] + a[IMAG]*b[IMAG])/(b[REAL]*b[REAL] + b[IMAG]*b[IMAG]);
	*c[IMAG] = (a[IMAG]*b[REAL] - a[REAL]*b[IMAG])/(b[REAL]*b[REAL] + b[IMAG]*b[IMAG]);
}

//(a + ib) · (c + id) = ac + i^2*bd + ibc + iad = (ac - bd) + i(bc + ad)
void cmplx_mul(fftw_complex a, fftw_complex b, fftw_complex *c) {
	*c[REAL] = (a[REAL]*b[REAL] - a[IMAG]*b[IMAG]);
	*c[IMAG] = (a[IMAG]*b[REAL] + a[REAL]*b[IMAG]);
}

double cmplx_mag(fftw_complex a) {
	return sqrt((a[REAL]*a[REAL]) + (a[IMAG]*a[IMAG]));
}

double cmplx_phs(fftw_complex a) {
	
}

double cmplx_real(double mag, double phs) {
	
}

double cmplx_imag(double mag, double phs) {
	
}
