/*

剑指Offer
面试题58：翻转字符串

题目二：左旋转字符串。字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到
的结果"cdefgab"。

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.empty() || n <= 0)
			return str;
		int m = n % str.size();
		reverse(str.begin(), str.begin() + m);
		reverse(str.begin() + m, str.end());
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	Solution solution;
	string s = "abcdefg";
	cout << solution.LeftRotateString(s, 2) << endl;
	return 0;
}
