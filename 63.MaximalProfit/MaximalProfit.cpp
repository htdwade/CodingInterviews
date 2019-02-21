/*

剑指Offer
面试题63：股票的最大利润

题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股票可能获得的利润是多少？
例如一只股票在某些时间节点的价格为{9, 11, 8, 5, 7, 12, 16, 14}。如果我们能在价格为5的时候买入
并在价格为16时卖出，则能收获最大的利润11。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int buy = prices[0], diff = 0;
		for (int i = 1; i < prices.size(); i++) {
			buy = min(buy, prices[i]);
			diff = max(diff, prices[i] - buy);
		}
		return diff;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 9, 11, 8, 5, 7, 12, 16, 14 };
	cout << solution.maxProfit(nums) << endl;
	return 0;
}
