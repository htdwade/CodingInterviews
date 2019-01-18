/*

剑指Offer
面试题40：最小的k个数

题目：输入n个整数，找出其中最小的k个数。例如，输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	//快速选择算法
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.empty() || k <= 0 || k > input.size())
			return res;
		int left = 0, right = input.size() - 1;
		int index = 0;
		while (left <= right) {
			index = partition(input, left, right);
			if (index == k - 1)
				break;
			else if (index < k - 1)
				left = index + 1;
			else
				right = index - 1;
		}
		res = vector<int>(input.begin(), input.begin() + k);
		return res;
	}

	//优先级队列维护最大堆
	vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
		vector<int> res;
		priority_queue<int> pq;
		if (input.empty() || k <= 0 || k > input.size())
			return res;
		for (auto a : input) {
			pq.push(a);
			if (pq.size() > k)
				pq.pop();
		}
		while (!pq.empty()) {
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
	}

private:
	int partition(vector<int>& input, int left, int right) {
		int pivot = input[left];
		int i = left;
		int j = left + 1;
		while (j <= right) {
			if (input[j] <= pivot)
				swap(input[++i], input[j]);
			j++;
		}
		swap(input[i], input[left]);
		return i;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 4,5,1,6,2,7,3,8 };
	vector<int> res1 = solution.GetLeastNumbers_Solution(nums1, 4);
	for (auto a : res1)
		cout << a << '\t';
	cout << "\n\n";
	vector<int> nums2 = { 4,5,1,6,2,7,3,8 };
	vector<int> res2 = solution.GetLeastNumbers_Solution2(nums2, 4);
	for (auto a : res2)
		cout << a << '\t';
	return 0;
}
