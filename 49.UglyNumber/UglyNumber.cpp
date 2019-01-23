/*

剑指Offer
面试题49：丑数

题目：我们把只包含因子2，3和5的数称作丑数。求按从小到大的顺序的第1500个丑数。
例如，6，8都是丑数，但14不是，因为它包含因子7。习惯上我们把1当做第一个丑数。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		if (n < 7)
			return n;
		vector<int> res(n);
		res[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; i++) {
			res[i] = min(min(res[p2] * 2, res[p3] * 3), res[p5] * 5);
			if (res[i] == res[p2] * 2)
				++p2;
			if (res[i] == res[p3] * 3)
				++p3;
			if (res[i] == res[p5] * 5)
				++p5;
		}
		return res[n - 1];
	}
};

int main()
{
	Solution solution;
	cout << solution.nthUglyNumber(1500) << endl;
	return 0;
}
