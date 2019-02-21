/*

剑指Offer
面试题62：圆圈中最后剩下的数字

题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
求出这个圆圈里剩下的最后一个数字。

*/

#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0)
			return -1;
		if (n == 1)
			return 0;
		int res = 0;
		for (int i = 2; i <= n; i++)
			res = (res + m) % i;
		return res;
	}

	int LastRemaining_Solution2(int n, int m)
	{
		if (n <= 0 || m <= 0)
			return -1;
		list<int> nums;
		for (int i = 0; i < n; i++)
			nums.push_back(i);
		auto it = nums.begin();
		int k = m - 1;
		while (nums.size() > 1) {
			while (k--) {
				it++;
				if (it == nums.end())
					it = nums.begin();
			}
			it = nums.erase(it);
			if (it == nums.end())
				it = nums.begin();
			k = m - 1;
		}
		return nums.front();
	}
};

int main()
{
	Solution solution;
	cout << solution.LastRemaining_Solution(5, 3) << endl;
	cout << solution.LastRemaining_Solution2(5, 3) << endl;
	return 0;
}
