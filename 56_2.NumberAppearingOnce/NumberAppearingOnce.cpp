/*

剑指Offer
面试题56：数组中数字出现的次数

题目二：数组中唯一只出现一次的数字。在一个数组中除一个数字只出现一次之外，其他数字都出现了三次。
请找出那个只出现一次的数字。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < 32; i++) {
			int count = 0;
			for (auto a : nums)
				count += (a >> i) & 0x1;
			if (count % 3)
				res += (1 << i);
		}
		return res;
	}

	//  a b
	//0 0 0
	//1 x 0
	//2 0 x
	//3 0 0
	int singleNumber2(vector<int>& nums) {
		int a = 0, b = 0;
		for (auto x : nums) {
			a = (a ^ x) & ~b;
			b = (b ^ x) & ~a;
		}
		return a;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 2,2,3,2};
	cout << solution.singleNumber(nums) << endl;
	cout << solution.singleNumber2(nums) << endl;
	return 0;
}
