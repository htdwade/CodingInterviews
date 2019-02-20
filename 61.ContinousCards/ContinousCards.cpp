/*

剑指Offer
面试题61：扑克牌中的顺子

题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() < 5)
			return false;
		sort(numbers.begin(), numbers.end());
		int count = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == 0) {
				count++;
				continue;
			}
			if (i + 1 < numbers.size() && numbers[i + 1] == numbers[i])
				return false;
			if (i + 1 < numbers.size())
				count -= numbers[i + 1] - numbers[i] - 1;
		}
		return count >= 0 ? true : false;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 0,4,3,5,1 };
	cout << solution.IsContinuous(nums) << endl;
	return 0;
}
