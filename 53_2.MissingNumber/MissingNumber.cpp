/*

剑指Offer
面试题53：在排序数组中查找数字

题目二：0 ~ n - 1中缺失的数字。一个长度为n - 1的递增排序数组中的所有数字都是唯一的，
并且每个数字都在范围0 ~ n - 1内。在范围0 ~ n - 1内的n个数字中有且只有一个数字不在该数组中，
请找出这个数字。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//0 ~ n - 1中缺失的数字
	int missingNumber(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid == nums[mid])
				left = mid + 1;
			else if (mid == 0 || nums[mid - 1] == mid - 1)
				return mid;
			else
				right = mid - 1;
		}
		return left;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 0,1,2,4,5,6};
	cout << solution.missingNumber(nums) << endl;
	return 0;
}
