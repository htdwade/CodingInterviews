/*

剑指Offer
面试题16：数值的整数次方
题目：实现函数double Power(double base, int exponent)，求base的exponent
次方。不得使用库函数，同时不需要考虑大数问题。

*/

#include <iostream>

using namespace std;

double Power(double base, int exponent) {
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	bool isNegative = false;
	if (exponent < 0) {
		exponent = -exponent;
		isNegative = true;
	}
	double res = Power(base * base, (unsigned)exponent >> 1);
	if (exponent & 0x1 == 1)
		res *= base;
	return isNegative ? 1.0 / res : res;
}

int main()
{
	cout << Power(2, 3) << endl;
	cout << Power(0, -1) << endl;
	cout << Power(2, -3) << endl;
	return 0;
}