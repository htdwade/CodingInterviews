/*

剑指Offer
面试题21：调整数组顺序使奇数位于偶数前面

题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
奇数位于数组的前半部分，所有偶数位于数组的后半部分。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int i = 0, j = A.size() - 1;
		while (i < j) {
			while (i < j && (A[i] % 2 == 0))
				i++;
			while (i < j && (A[j] % 2 == 1))
				j--;
			swap(A[i++], A[j--]);
		}
		return A;
	}
};

int main()
{
	Solution solution;
	vector<int> A = { 1, 2, 3, 4, 5 };
	vector<int> res = solution.sortArrayByParity(A);
	for (auto a : res)
		cout << a << '\t';
	return 0;
}