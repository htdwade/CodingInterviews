/*

剑指Offer
面试题65：不用加减乘除做加法

题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷ 四则运算符号。

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2) {
			int sum = num1 ^ num2;
			int carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		return num1;
	}
};

int main()
{
	Solution solution;
	cout << solution.Add(3, 5) << endl;
	return 0;
}
