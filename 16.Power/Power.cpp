/*

剑指Offer
面试题16：二进制中1的个数
题目：实现函数double Power(double base, int exponent)，求base的exponent
次方。不得使用库函数，同时不需要考虑大数问题。

*/

#include <iostream>

using namespace std;

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

/*
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
double result = 1.0;

for (int i = 1; i <= exponent; ++i)
result *= base;
return result;
}
*/

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}
int main()
{
	cout << Power(2, 3) << endl;
	cout << Power(0, -1) << endl;
	cout << Power(2, -3) << endl;
	return 0;
}