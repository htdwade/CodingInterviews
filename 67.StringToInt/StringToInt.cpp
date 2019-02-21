/*

剑指Offer
面试题67：把字符串转换为整数

题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不能使用atoi或者其他类似的库函数。

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int i = 0, sign = 1, result = 0;
		if (str.empty())
			return 0;
		while (i < str.size() && str[i] == ' ')
			i++;
		if (i == str.size()) return 0;
		if (str[i] == '+' || str[i] == '-') {
			sign = str[i] == '+' ? 1 : -1;
			i++;
		}
		while (i < str.size()) {
			if (str[i] < '0' || str[i] > '9')
				return 0;
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
				return sign == 1 ? INT_MAX : INT_MIN;
			result = result * 10 + (str[i] - '0');
			i++;
		}
		return sign * result;
	}
};

int main()
{
	Solution solution;
	cout << solution.StrToInt("   -2345") << endl;
	return 0;
}
