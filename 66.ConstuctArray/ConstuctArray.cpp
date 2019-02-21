/*

剑指Offer
面试题66：构建乘积数组

题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，
其中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 1);
		int left = 1;
		for (int i = 0; i < nums.size(); i++) {
			res[i] *= left;
			left *= nums[i];
		}
		int right = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,2,3,4,5 };
	vector<int> res = solution.productExceptSelf(nums);
	for (auto a : res)
		cout << a << '\t';
	return 0;
}
