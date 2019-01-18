/*

剑指Offer
面试题42：连续子数组的最大和

题目：输入一个整型数组，数组里面有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
求所有子数组的和的最大值。要求时间复杂度为O(n)。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int maxSum = dp[0];
		for (int i = 1; i < nums.size(); i++) {
			if (dp[i - 1] <= 0)
				dp[i] = nums[i];
			else
				dp[i] = dp[i - 1] + nums[i];
			maxSum = max(maxSum, dp[i]);
		}
		return maxSum;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,-2,3,10,-4,7,2,-5 };
	cout << solution.maxSubArray(nums) << endl;
	return 0;
}
