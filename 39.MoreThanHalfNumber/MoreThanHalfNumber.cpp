/*

剑指Offer
面试题39：数组中出现次数超过一半的数字

题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如，输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int res = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); i++) {
			if (count == 0) {
				res = numbers[i];
				count = 1;
			}
			else if (numbers[i] == res)
				count++;
			else
				count--;
		}
		count = 0;
		for (auto a : numbers) {
			if (a == res)
				count++;
		}
		if (count > numbers.size() / 2)
			return res;
		else
			return 0;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,2,3,2,2,2,5,4,2 };
	cout << solution.MoreThanHalfNum_Solution(nums) << endl;
	return 0;
}