#include <stdio.h>

/*absolute value of integer x*/
int iabs(int x)
{
	if (x > 0)
		return x;
	return -x;
}
/*absolute value of float x*/
float fabs(float x)
{
	if (x > 0)
		return x;
	return -x;
}
/*absolute value of double x*/
double abs(double x) 
{
	if (x > 0)
		return x;
	return -x;
}
/*sqare root of int x*/
float isqrt(int x)
{
	if (x <= 0)
		return 0;
	float low = 0, high = (float)x, mid, res;
	for (int i = 0; i < 1000; i++) {
		mid = (high + low) / 2;
		res = mid * mid;
		if (res == x)
			return mid;
		if (res > x)
			high = mid;
		else if (res < x)
			low = mid;
	}
	return mid;
}
/*sqrt of a float*/
float fsqrt(float x) 
{
	if (x <= 0)
		return 0;
	float low = 0, high = x, mid = x / 2.f, res;
	for (int i = 0; i < 1000; i++) {
		mid = (high + low) / 2;
		res = mid * mid;
		if (res == x)
			return mid;
		if (res > x)
			high = mid;
		else if (res < x)
			low = mid;
	}
	return mid;
}

double dipow(double sq, int pow);
//sqrt of a double
double sqrt(double x, int root)
{
	if (x <= 0)
		return 0;
	double low = 0, high = x, mid = x / 2.f, res;
	for (int i = 0; i < 1000; i++) {
		mid = (high + low) / 2;
		res = dipow(mid, 2);
		if (res == x)
			return mid;
		if (res > x)
			high = mid;
		else if (res < x)
			low = mid;
	}
	return mid;
}
//double to integer power
double dipow(double sq, int pow) 
{
	double y = sq;
	for (unsigned short i = pow; i - 1; i--)
		y = y * sq;
	return y;
}
//float to integer power
float fipow(float sq, int pow) 
{
		
}
//Interger to integer power
int iipow(int sq, int pow) 
{
	int y = sq;
	for (unsigned short i = pow; i - 1; i--)
		y = y*sq;
	return y;
}

int main() 
{
	for (int i = 0; i < 101; i++)
		printf("%i, %i\n", i, i * 4 + 1);
	printf("%f\n", sqrt(72.5f, 2));
}