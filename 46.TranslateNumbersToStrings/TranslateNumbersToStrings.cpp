/*

剑指Offer
面试题46：把数字翻译成字符串

题目：给定一个数字，我们按照如下规则把它翻译为字符串：
0翻译成"a"，1翻译成"b"，......11翻译成"1"，.....，25翻译成"z"。
一个数字可能有多个翻译。例如，12258有5种不同的翻译，分别是"bccfi"，"bwfi"，"bczi"，"mcfi"和"mzi"。
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int getTranslationCount(string s) {
		if (s.empty())
			return 0;
		int n = s.size();
		vector<int> dp(n + 1);
		dp[n] = 1;
		dp[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			dp[i] = dp[i + 1];
			if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '5'))
				dp[i] += dp[i + 2];
		}
		return dp[0];
	}
};

int main()
{
	Solution solution;
	cout << solution.getTranslationCount("12258") << endl;
	return 0;
}
