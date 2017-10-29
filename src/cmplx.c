#include<math.h>
#include<stdio.h>
#include "../inc/fftw3.h"
#include "../inc/cmplx.h"

#define REAL 0
#define IMAG 1

int main () {
	fftw_complex z1;
	fftw_complex z2;
	fftw_complex z3;
	
	printf ("Unesite prvi kompleksni broj u formatu Re(z) Im(z): ");
	scanf("%lf %lf", &(z1[REAL]), &(z1[IMAG]));
	
	printf ("Unesite drugi kompleksni broj u formatu Re(z) Im(z): ");
	scanf("%lf %lf", &(z2[REAL]), &(z2[IMAG]));
	
	printf ("Ulazi: ");
	printf ("\nZ1: %.2lf %.2lf", z1[REAL], z1[IMAG]);
	printf ("\nZ2: %.2lf %.2lf", z2[REAL], z2[IMAG]);
	
	cmplx_div(z1, z2, z3);
	printf ("\nRezultat dijeljenja: %.2lf %.2lf", z3[REAL], z3[IMAG]);
	
	cmplx_mul(z1, z2, z3);
	printf ("\nRezultat mnozenja: %.2lf %.2lf", z3[REAL], z3[IMAG]);
	
	printf ("\nAmplituda: %.2lf", cmplx_mag(z1));
	printf ("\nFaza: %.2lf", cmplx_phs(z1));
	printf ("\nRealni dio: %.2lf", cmplx_real(cmplx_mag(z1), cmplx_phs(z1)));
	printf ("\nImaginarni dio: %.2lf", cmplx_imag(cmplx_mag(z1), cmplx_phs(z1)));
	
	return 0;
}

//(a + ib)/(c + id) = [(a + ib)/(c + id)] * [(c - id)/(c - id)] = [(ac + bd) + i(bc - ad)]/(c^2 + d^2)
void cmplx_div(fftw_complex a, fftw_complex b, fftw_complex c) {
	c[REAL] = (a[REAL] * b[REAL] + a[IMAG] * b[IMAG])/(b[REAL] * b[REAL] + b[IMAG] * b[IMAG]);
	c[IMAG] = (a[IMAG] * b[REAL] - a[REAL] * b[IMAG])/(b[REAL] * b[REAL] + b[IMAG] * b[IMAG]);
}

//(a + ib) · (c + id) = ac + i^2*bd + ibc + iad = (ac - bd) + i(bc + ad)
void cmplx_mul(fftw_complex a, fftw_complex b, fftw_complex c) {
	c[REAL] = (a[REAL] * b[REAL] - a[IMAG] * b[IMAG]);
	c[IMAG] = (a[IMAG] * b[REAL] + a[REAL] * b[IMAG]);
}

double cmplx_mag(fftw_complex a) {
	return sqrt((a[REAL] * a[REAL]) + (a[IMAG] * a[IMAG]));
}

double cmplx_phs(fftw_complex a) {
	return atan(a[IMAG] / a[REAL]);
}

double cmplx_real(double mag, double phs) {
	return mag * cos(phs);
}

double cmplx_imag(double mag, double phs) {
	return mag * sin(phs);
}
