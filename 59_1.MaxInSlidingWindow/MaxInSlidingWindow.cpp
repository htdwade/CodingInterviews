/*

剑指Offer
面试题59：队列的最大值

题目一：滑动窗口的最大值。给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
例如，如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
它们的最大值分别为{4, 4, 6, 6, 6, 5}。

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> q;
		for (int i = 0; i < nums.size(); i++) {
			while (!q.empty() && i - q.front() >= k)
				q.pop_front();
			while (!q.empty() && nums[i] >= nums[q.back()])
				q.pop_back();
			q.push_back(i);
			if (i >= k - 1)
				res.push_back(nums[q.front()]);
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> res = solution.maxSlidingWindow(nums, 3);
	for (auto a : res)
		cout << a << '\t';
	return 0;
}
