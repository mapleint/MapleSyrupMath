#pragma once

/* #include <math.h>
 * Lol no I don't do that, though it would be funny 
 * I try to implement according to :
 * http://www.cplusplus.com/reference/cmath/?kw=math.h
 I will not, however, reimpliment functions that are virtually the same
 */

static const double PI = 3.1415926535897932384264;

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
	x = modd(x, PI*2);
	char sign = 1;
	if (x > PI)
	{
		x -= PI;
		sign = -1;
	}
	double xx = x * x;

	return sign * (1 - ((xx) / (2)) + 
		((xx * xx) / (24))
		- ((xx * xx * xx) / (720))
		+ ((xx * xx * xx * xx) / (40320)) 
		- ((xx * xx * xx * xx * xx) / (3628800)) 
		+ ((xx * xx * xx * xx * xx * xx) / (479001600)));
}

double sin(double x)
{
	cos(x - (PI/ 2.f));
}

double tan(double x)
{
	sin(x) / cos(x);
}

double asin(double x) 
{
	-acos(x) + (PI / 2.f);
}

/* Credits: nVidia*/

double acos(double x) 
{
	float negate = (float)(x < 0);
	x = fabs(x);
	float ret = -0.0187293;
	ret = ret * x;
	ret = ret + 0.0742610;
	ret = ret * x;
	ret = ret - 0.2121144;
	ret = ret * x;
	ret = ret + 1.5707288;
	ret = ret * sqrt(1.0-x);
	ret = ret - 2 * negate * ret;
	return negate * 3.14159265358979 + ret;
}

double atan(double x)
{
	return atan2(x, 1.f);
}
/* credits to nVidia again */
double atan2(double x, double y)
{
	float t0, t1, t2, t3, t4;

	t3 = fabs(x);
	t1 = fabs(y);
	t0 = fmax(t3, t1);
	t1 = fmin(t3, t1);
	t3 = 1 / t0;
	t3 = t1 * t3;

	t4 = t3 * t3;
	t0 = -0.013480470;
	t0 = t0 * t4 + 0.057477314;
	t0 = t0 * t4 - 0.121239071;
	t0 = t0 * t4 + 0.195635925;
	t0 = t0 * t4 - 0.332994597;
	t0 = t0 * t4 + 0.999995630;
	t3 = t0 * t3;

	t3 = (abs(y) > abs(x)) ? (PI/2)- t3 : t3;
	t3 = (x < 0) ? PI - t3 : t3;
	t3 = (y < 0) ? -t3 : t3;

	return t3;
}

/* Hyperbolic */

double cosh(double x)
{
	return 0.5 * (exp(x) + exp(-x));
}

double sinh(double x)
{
	return 0.5 * (exp(x) - exp(-x));
}

double tanh(double x)
{
	return sinh(x) / cosh(x);
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

/* I am bitter we do not know of these functions
what motherfucks decided hypberbolics and arc hyperbolics need to exist
*/

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
	return exp(base * log(exponent));
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
	double l, b, h;
	if(x < 0)
		l = fmax(-1, x), b = x / 2, h = fmin(x, -1);
	else
		l = fmin(1, x), b = x / 2, h = fmax(x, 1);
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
