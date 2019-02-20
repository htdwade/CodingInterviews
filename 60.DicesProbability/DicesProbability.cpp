/*

剑指Offer
面试题60：n个骰子的点数

题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<double> numberOfDice(int n) {
		vector<double> res;
		vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
		for (int i = 1; i <= 6; i++)
			dp[1][i] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = i; j <= 6 * n; j++)
				for (int k = 1; k <= 6 && k <= j; k++)
					dp[i][j] += dp[i - 1][j - k];
		for (int i = n; i <= 6 * n; i++)
			res.push_back(dp[n][i] / pow(6.0, n));
		return res;
	}
};

int main()
{
	Solution solution;
	vector<double> res = solution.numberOfDice(2);
	for (auto a : res)
		cout << a << '\t';
	return 0;
}
