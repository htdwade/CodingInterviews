/*

剑指Offer
面试题45：把数组排成最小的数

题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如，输入数组{3,32,321}，则打印出这3个数字能排成的最小数字321323。

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty())
			return "";
		auto cmp = [](const int& a, const int& b) {return to_string(a) + to_string(b) < to_string(b) + to_string(a); };
		sort(numbers.begin(), numbers.end(), cmp);
		string res = "";
		for (auto a : numbers)
			res += to_string(a);
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 3,32,321 };
	cout << solution.PrintMinNumber(nums) << endl;
	return 0;
}
