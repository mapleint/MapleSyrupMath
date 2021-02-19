#pragma once

/* #include <math.h>
 * Lol no I don't do that, though it would be funny 
 * I try to implement according to :
 * http://www.cplusplus.com/reference/cmath/?kw=math.h
 */

/*declare all functions as many may rely on others*/

/* Trigonometric */

double cos(double x);

double sin(double x);

double tan(double x);

double asin(double x);

double atan(double x);

double atan2(double x);

/* Hyperbolic */

double cosh(double x);

double sinh(double x);

double tanh(double x);

double acosh(double x);

double asinh(double x);

double atanh(double x);

/* Exponential and Logarithmic*/

double exp(double x);

double frexp(double x, int* exp);

double ldexp(double x, int exp);

double log(double x);

double log10(double x);

double modf(double x, double* intpart);

double exp2(double x);

double expm1(double x);

int ilogb(double x);

double log1p(double x);

double log2(double x);

double logb(double x);

double scalbn(double x, int n);

double scalbln(double x, long int n);

/* Power */

double pow(double base, double exponent);

double sqrt(double x);

double cbrt(double x);

double hypot(double x, double y);

/* Error and Gamma*/

double erf(double x);

double erfc(double x);

double tgamma(double x);

double lgamma(double x);

/* Rounding and remainder */

double ceil(double x);

double floor(double x);

double fmod(double numer, double denom);

double trunc(double x);

double round(double x);

long int lround(double x);

long long int llround(double x);

double rint(double x);

long int lrint(double x);

double nearbyint(double x);

double remainder(double numer, double denom);

double remquo(double numer, double denom, int* quot);

/* Floating Point Maniupation*/

double copysign(double x, double y);

double nextafter(double x, double y);

double nexttoward(double x, long double y);

/* Min, max, diff*/

double fmin(double x, double y);

double fmax(double x, double y);

double fdim(double x, double y);

/* other */

double fabs(double x);

double fma(double x, double y, double z);

/*END DECLARATIONS*/

/* Trigonometric */

double cos(double x) 
{

}

double sin(double x)
{

}

double tan(double x)
{
	sin(x) / cos(x);
}

double asin(double x) 
{

}

double acos(double x) 
{

}

double atan(double x)
{

}

double atan2(double x)
{

}

/* Hyperbolic */

double cosh(double x)
{

}

double sinh(double x)
{

}

double tanh(double x)
{

}

double acosh(double x)
{

}

double asinh(double x)
{

}

double atanh(double x)
{

}

/* Exponential and Logarithmic*/

double exp(double x)
{

}

double frexp(double x, int* exp)
{

}

double ldexp(double x, int exp)
{

}

double log(double x)
{

}

double log10(double x)
{

}

double modf(double x, double* intpart)
{

}

double exp2(double x)
{

}

double expm1(double x)
{

}

int ilogb(double x)
{

}

double log1p(double x)
{

}

double log2(double x)
{

}

double logb(double x)
{

}

double scalbn(double x, int n)
{

}

double scalbln(double x, long int n)
{

}

/* Power */

double pow(double base, double exponent)
{

}

double sqrt(double x)
{

}

double cbrt(double x)
{

}

double hypot(double x, double y)
{

}

/* Error and Gamma*/

double erf(double x)
{

}

double erfc(double x)
{

}

double tgamma(double x)
{

}

double lgamma(double x)
{

}

/* Rounding and remainder */

double ceil(double x)
{

}

double floor(double x)
{

}

double fmod(double numer, double denom)
{

}

double trunc(double x)
{

}

double round(double x)
{

}

long int lround(double x)
{

}

long long int llround(double x)
{

}

double rint(double x)
{

}

long int lrint(double x)
{

}

double nearbyint(double x)
{

}

double remainder(double numer, double denom)
{

}

double remquo(double numer, double denom, int* quot)
{

}

/* Floating Point Maniupation*/

double copysign(double x, double y)
{

}

double nextafter(double x, double y)
{

}

double nexttoward(double x, long double y)
{

}

/* Min, max, diff*/

double fmin(double x, double y)
{

}

double fmax(double x, double y)
{

}

double fdim(double x, double y)
{

}

/* other */

double fabs(double x)
{
	return *((int*)&x) | 0x7fffffff;
}

double fma(double x, double y, double z) 
{
	return x * y + z;
}