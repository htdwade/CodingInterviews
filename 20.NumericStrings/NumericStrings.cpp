/*

剑指Offer
面试题20：表示数值的字符串

题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是.

*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
	//正则表达式
	bool isNumeric(const char* str)
	{
		if (str == nullptr)
			return false;
		regex pattern("[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?");
		return regex_match(str, pattern);
	}

	// 常规扫描解法
	// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
	// 整数（可以有正负号，也可以没有），而B是一个无符号整数
	bool isNumeric2(const char* str)
	{
		if (str == nullptr)
			return false;

		bool numeric = scanInteger(str);

		// 如果出现'.'，接下来是数字的小数部分
		if (*str == '.')
		{
			++str;

			// 下面一行代码用||的原因：
			// 1. 小数可以没有整数部分，例如.123等于0.123；
			// 2. 小数点后面可以没有数字，例如233.等于233.0；
			// 3. 当然小数点前面和后面可以有数字，例如233.666
			numeric = scanUnsignedInteger(str) || numeric;
		}

		// 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
		if (*str == 'e' || *str == 'E')
		{
			++str;

			// 下面一行代码用&&的原因：
			// 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
			// 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
			numeric = numeric && scanInteger(str);
		}

		return numeric && *str == '\0';
	}

private:
	bool scanUnsignedInteger(const char*& str)
	{
		int count = 0;
		while (*str != '\0' && *str >= '0' && *str <= '9') {
			++str;
			++count;
		}

		// 当str中存在若干0-9的数字时，返回true
		return count > 0;
	}

	// 整数的格式可以用[+|-]B表示, 其中B为无符号整数
	bool scanInteger(const char*& str)
	{
		if (*str == '+' || *str == '-')
			++str;
		return scanUnsignedInteger(str);
	}

};

int main()
{
	Solution solution;
	cout << solution.isNumeric("+100") << endl;
	cout << solution.isNumeric("5e2") << endl;
	cout << solution.isNumeric("-123") << endl;
	cout << solution.isNumeric("3.1416") << endl;
	cout << solution.isNumeric("-1E-16") << endl;
	cout << solution.isNumeric("12e") << endl;
	cout << solution.isNumeric("1a3.14") << endl;
	cout << solution.isNumeric("1.2.3") << endl;
	cout << solution.isNumeric("+-5") << endl;
	cout << solution.isNumeric("12e+5.4") << endl;
	return 0;
}