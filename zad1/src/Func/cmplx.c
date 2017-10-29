#include<math.h>
#include<stdio.h>
#include "../inc/fftw3.h"
#include "../inc/cmplx.h"

#define REAL 0
#define IMAG 1

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
