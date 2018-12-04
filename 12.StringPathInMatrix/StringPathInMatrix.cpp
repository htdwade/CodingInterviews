/*

剑指Offer
面试题12：矩阵中的路径
题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
a b t g
c f c s
j d e h

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
			return false;
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		for (int row = 0; row < rows; row++)
			for (int col = 0; col < cols; col++)
				if (hasPathCore(matrix, rows, cols, row, col, str, 0, visited))
					return true;
		return false;
	}

private:
	bool hasPathCore(char*& matrix, int rows, int cols, int row, int col, char*& str, int pathLength, vector<vector<bool>>& visited) {
		if (str[pathLength] == '\0')
			return true;
		bool flag = false;
		if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row][col]) {
			pathLength++;
			visited[row][col] = true;
			flag = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
			if (!flag) {
				pathLength--;
				visited[row][col] = false;
			}
		}
		return flag;
	}
};

int main()
{
	Solution solution;
	char matrix[] = "abtgcfcsjdeh";
	char str1[] = "bfce";
	char str2[] = "abfb";
	cout << solution.hasPath(matrix, 3, 4, str1) << endl;
	cout << solution.hasPath(matrix, 3, 4, str2) << endl;
	return 0;
}