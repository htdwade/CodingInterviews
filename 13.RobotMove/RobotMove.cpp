/*

剑指Offer
面试题13：机器人的运动范围
题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0 || rows <= 0 || cols <= 0)
			return 0;
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		return count;
	}

private:
	int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<vector<bool>>& visited) {
		int count = 0;
		if (row >= 0 && row < rows && col >= 0 && col < cols 
			&& getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row][col]) {
			visited[row][col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}
		return count;
	}

	int getDigitSum(int number) {
		int sum = 0;
		while (number) {
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};

int main()
{
	Solution solution;
	cout << solution.movingCount(2, 2, 3) << endl;
	return 0;
}