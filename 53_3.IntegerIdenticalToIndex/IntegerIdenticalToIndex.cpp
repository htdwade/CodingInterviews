/*

剑指Offer
面试题53：在排序数组中查找数字

题目三：数组中数值和下标相等的元素。假设一个单调递增的数组里的每个元素都是整数并且是唯一的。
请编程实现一个函数，找出数组中任意一个数值等于其下标的元素。例如，在数组{-3,-1,1,3,5}中，
数字3和它的下标相等。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//数组中数值和下标相等的元素
	int getNumberSameAsIndex(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == mid)
				return mid;
			else if (nums[mid] > mid)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { -3,-1,1,3,5 };
	cout << solution.getNumberSameAsIndex(nums) << endl;
	return 0;
}
