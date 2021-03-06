/*

剑指Offer
面试题47：礼物的最大价值

题目：在一个m * n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格，直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物?

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getMaxValue(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		for (int i = 1; i < m; i++)
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		return dp[m - 1][n - 1];
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> grid = { {1, 10, 3, 8},
								{12, 2, 9, 6},
								{5, 7, 4, 11},
								{3, 7, 16, 5} };
	cout << solution.getMaxValue(grid) << endl;
	return 0;
}
