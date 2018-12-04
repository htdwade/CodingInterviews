/*

剑指Offer
面试题14：剪绳子
题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
时得到最大的乘积18。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//动态规划
int maxProductAfterCutting_solution1(int length) {
	if (length < 2)
		return 0;
	vector<int> dp(length + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= length; i++)
		for (int j = 1; j <= i / 2; j++)
			dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
	return dp[length];
}

//贪婪算法
int maxProductAfterCutting_solution2(int length) {
	if (length <= 3)
		return 1 * (length - 1);
	int res = 1;
	while (length > 4) {
		res *= 3;
		length -= 3;
	}
	res *= length;
	return res;
}

int main()
{
	cout << maxProductAfterCutting_solution1(8) << endl;
	cout << maxProductAfterCutting_solution2(8) << endl;
	return 0;
}