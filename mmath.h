#pragma once

/* #include <math.h>
 * Lol no I don't do that, though it would be funny 
 * I try to implement according to :
 * http://www.cplusplus.com/reference/cmath/?kw=math.h
 I will not, however, reimpliment functions that are virtually the same
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

/* Rounding and remainder */

double ceil(double x);

double floor(double x);

double fmod(double numer, double denom);

double trunc(double x);

double round(double x);

double rint(double x);

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
	sinh(x) / cosh(x);
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
	if (x < 0)
		return 0;
	int i = 0;
	double l = fmin(1, 0), b = x / 2, h = fmax(x, 1);
	for (; i < 100; i++) {
		b = (l+h)/2;
		if (b * b == x)
			return b;
		if (b * b > x)
			h = b;
		else
			l = b;
	}
	return b;
}

double cbrt(double x)
{
	int i = 0;
	if(x < 0)
		double l = fmax(-1, x), b = x / 2, h = fmin(x, -1);
	double l = fmin(1, x), b = x / 2, h = fmax(x, 1);
	for (; i < 100; i++) {
		b = (l + h) / 2;
		if (b * b * b == x)
			return b;
		if (b * b * b > x)
			h = b;
		else
			l = b;
	}
	return b;
}

double hypot(double x, double y)
{
	return sqrt(x * x + y * y);
}

/* Rounding and remainder */

double ceil(double x)
{
	floor(x + 1);
}

double floor(double x)
{
	return (double)(int)x;
}

double fmod(double numer, double denom)
{
	double q = numer / denom;
	q -= floor(q);
	return q * denom;
}

double trunc(double x)
{
	return floor(x);
}

double round(double x)
{
	nearbyint(x);
}


double rint(double x)
{
	return nearbyint(x);
}


double nearbyint(double x)
{
	if (x + .5f >= floor(x + 1))
		return floor(x + 1);
	return floor(x);
}

double remainder(double numer, double denom)
{
	int rquot = nearbyint(numer / denom);
	return numer - rquot * denom;
}

double remquo(double numer, double denom, int* quot)
{

	double q = numer / denom;
	q -= floor(q);
	*quot = (numer - q * denom)/denom;
	return q * denom;

}

/* Floating Point Maniupation*/

double copysign(double x, double y)
{
//	double o = x;
//	double k = y;
//#ifdef _WIN32
//	*((int*)&o) = ((*((int*)&k) >> 31) << 31) + *((int*)&o);
//#elif
//	*((int*)&o)[1] |= ~((*((int*)&k)[1] << 31) >> 31);
//#endif
//	return o;
	//didn't work, will work out later
	if ((y < 0 && x > 0) || (x < 0 && y > 0))
		return x * -1.f;
	else return x;
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
	if (x > y)
		return y;
	return x;
}

double fmax(double x, double y)
{
	if (x > y)
		return x;
	return y;
}

double fdim(double x, double y)
{
	return fabs(x - y);
}

/* other */

double fabs(double x)
{
	/* floats can't be bit manipulated
	   and this is platform iffy*/
	double o = x;
#ifdef _WIN32
	*((int*)&o) &= 0x7fffffff;
#elif
	*((int*)&o)[1] &= 0x7fffffff;
#endif
	return o;

}

double fma(double x, double y, double z) 
{
	return x * y + z;
}
