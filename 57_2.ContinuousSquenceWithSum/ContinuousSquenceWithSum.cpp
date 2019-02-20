/*

剑指Offer
面试题57：和为s的数字

题目二：和为s的连续正数序列。输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
例如，输入15，由于1 + 2 + 3 + 4 + 5 = 4 + 5 + 6 = 7 + 8 = 15，所以打印出3个连续序列1 ~ 5，4 ~ 6和7 ~ 8。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		int start = 1, end = 2;
		while (start < end) {
			int total = (start + end) * (end - start + 1) / 2;
			if (total == sum) {
				vector<int> tmp;
				for (int i = start; i <= end; i++)
					tmp.push_back(i);
				res.push_back(tmp);
				start++;
			}
			else if (total < sum)
				end++;
			else
				start++;
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> res = solution.FindContinuousSequence(15);
	for (auto v : res) {
		for (auto a : v)
			cout << a << '\t';
		cout << '\n';
	}
	return 0;
}
