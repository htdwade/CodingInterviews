/*

剑指Offer
面试题53：在排序数组中查找数字

题目一：数字在排序数组中出现的次数。统计一个数字在排序数组中出现的次数。
例如，输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4。

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
	vector<int> nums = { 1,2,3,3,3,3,4,5 };
	cout << solution.GetNumberOfK(nums, 3) << endl;
	return 0;
}
