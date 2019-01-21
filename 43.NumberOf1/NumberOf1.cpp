/*

剑指Offer
面试题43：1~n整数中1出现的次数

题目：输入一个整数n，求1~n这n个整数的十进制表示中1出现的次数。
例如，输入12,1到12这些整数中包含1的数字有1,10,11和12，1一共出现了5次。

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0)
			return 0;
		int  count = 0;
		long long factor = 1;
		while (n / factor) {
			long long cur = (n / factor) % 10;
			long long high = (n / factor) / 10;
			long long low = n % factor;
			if (cur == 0)
				count += high * factor;
			else if (cur == 1)
				count += high * factor + low + 1;
			else
				count += (high + 1) * factor;
			factor *= 10;
		}
		return count;
	}

	int countDigitOne2(int n) {
		if (n <= 0)
			return 0;
		int  count = 0;
		for (long long i = 1; i <= n; i *= 10) {
			long long a = n / i, b = n % i;
			count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
		}
		return count;
	}
};

int main()
{
	Solution solution;
	cout << solution.countDigitOne(12) << endl;
	cout << solution.countDigitOne2(12) << endl;
	return 0;
}
