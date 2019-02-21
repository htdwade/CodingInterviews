/*

剑指Offer
面试题64：求1+2+...+n

题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		bool flag = sum && (sum += Sum_Solution(n - 1));
		return sum;
	}
};

int main()
{
	Solution solution;
	cout << solution.Sum_Solution(10) << endl;
	return 0;
}
