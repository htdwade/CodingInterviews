/*

剑指Offer
面试题44：数字序列中某一位的数字

题目：数字以0123456789101112131415...的格式序列化到一个字符序列中。在这个序列中，
第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一个函数，求任意第n位对应的数字。

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int digitAtIndex(int n) {
		if (n < 0)
			return -1;
		//确定数字有几位数
		int digits = 1;
		while (true) {
			long long total = totalNumberOfDigits(digits);
			if (n < total * digits)
				break;
			n -= total * digits;
			digits++;
		}
		//确定数字是哪个数
		int number = beginNumberOfDigits(digits) + n / digits;
		//找到具体的那一位
		int indexFromRight = digits - n % digits;
		for (int i = 1; i < indexFromRight; i++)
			number /= 10;
		return number % 10;
	}

private:
	//有digits位数的数字总数，1 -> 10(0 ~ 9)， 2 -> 90(10 ~ 99)， 3 -> 900(100 ~ 999) ...
	long long totalNumberOfDigits(int digits) {
		if (digits == 1)
			return 10;
		return 9 * pow(10, digits - 1);
	}

	//digits位数的第一个数字
	int beginNumberOfDigits(int digits) {
		if (digits == 1)
			return 0;
		return pow(10, digits - 1);
	}
};

int main()
{
	Solution solution;
	cout << solution.digitAtIndex(5) << endl;
	cout << solution.digitAtIndex(13) << endl;
	cout << solution.digitAtIndex(19) << endl;
	return 0;
}
