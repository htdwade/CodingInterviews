/*

剑指Offer
面试题53：在排序数组中查找数字

题目一：数字在排序数组中出现的次数。统计一个数字在排序数组中出现的次数。
例如，输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4。

题目二：0 ~ n - 1中缺失的数字。一个长度为n - 1的递增排序数组中的所有数字都是唯一的，
并且每个数字都在范围0 ~ n - 1内。在范围0 ~ n - 1内的n个数字中有且只有一个数字不在该数组中，
请找出这个数字。

题目三：数组中数值和下标相等的元素。假设一个单调递增的数组里的每个元素都是整数并且是唯一的。
请编程实现一个函数，找出数组中任意一个数值等于其下标的元素。例如，在数组{-3,-1,1,3,5}中，
数字3和它的下标相等。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//数字在排序数组中出现的次数
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int start = binarySearch(data, k);
		if (start == data.size() || data[start] != k)
			return 0;
		return binarySearch(data, k + 1) - start;
	}

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

private:
	//[left...right)
	int binarySearch(vector<int>& data, int k) {
		int left = 0, right = data.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (data[mid] < k)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 1,2,3,3,3,3,4,5 };
	cout << solution.GetNumberOfK(nums1, 3) << endl;
	vector<int> nums2 = { 0,1,2,4,5,6};
	cout << solution.missingNumber(nums2) << endl;
	vector<int> nums3 = { -3,-1,1,3,5 };
	cout << solution.getNumberSameAsIndex(nums3) << endl;
	return 0;
}
