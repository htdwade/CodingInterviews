/*

剑指Offer
面试题57：和为s的数字

题目一：和为s的两个数字。输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则任意输出一对即可。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> res;
		int left = 0, right = array.size() - 1;
		while (left < right) {
			int cur = array[left] + array[right];
			if (cur == sum) {
				res.push_back(array[left]);
				res.push_back(array[right]);
				break;
			}
			else if (cur < sum)
				left++;
			else
				right--;
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = {1,2,4,7,11,15};
	vector<int> res = solution.FindNumbersWithSum(nums, 15);
	cout << res[0] << '\t' << res[1] << endl;
	return 0;
}
