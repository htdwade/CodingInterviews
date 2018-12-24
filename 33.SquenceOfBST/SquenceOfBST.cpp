/*

剑指Offer
面试题33：二叉搜索树的后序遍历序列

题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回true，否则返回false。假设输入的数组的任意两个数字互不相同。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		return dfs(sequence, 0, sequence.size() - 1);
	}

private:
	bool dfs(vector<int>& sequence, int left, int right) {
		if (right - left <= 1)
			return true;
		int root = sequence[right];
		int index = left;
		while (index < right && sequence[index] < root)
			index++;
		for (int i = index; i < right; i++)
			if (sequence[i] < root)
				return false;
		return dfs(sequence, left, index - 1) && dfs(sequence, index, right - 1);
	}
};

int main()
{
	Solution solution;
	vector<int> v1 = { 5,7,6,9,11,10,8 };
	vector<int> v2 = { 7,4,6,5 };
	cout << solution.VerifySquenceOfBST(v1) << endl;
	cout << solution.VerifySquenceOfBST(v2) << endl;
	return 0;
}