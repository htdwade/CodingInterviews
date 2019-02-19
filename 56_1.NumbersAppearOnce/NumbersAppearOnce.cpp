/*

剑指Offer
面试题56：数组中数字出现的次数

题目一：数组中只出现一次的两个数字。一个整型数组里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度为O(n)，空间复杂度为O(1)。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res(2, 0);
		int diff = 0;
		for (auto num : nums)
			diff ^= num;
		diff &= -diff;
		for (auto num : nums) {
			if ((num & diff) == 0)
				res[0] ^= num;
			else
				res[1] ^= num;
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 2,4,3,6,3,2,5,5 };
	vector<int> res = solution.singleNumber(nums);
	cout << res[0] << '\t' << res[1] << endl;
	return 0;
}
