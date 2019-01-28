/*

剑指Offer
面试题50：第一个只出现一次的字符

题目一：字符串中第一个只出现一次的字符。在字符串中找出第一个只出现一次的字符。
如输入"abaccdeff"，则输出'b'。

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//字符串中第一个只出现一次的字符
	int firstUniqChar(string s) {
		unordered_map<char, int> hash;
		for (auto c : s)
			hash[c]++;
		for (int i = 0; i < s.size(); i++)
			if (hash[s[i]] == 1)
				return i;
		return -1;
	}
};

int main()
{
	Solution solution;
	cout << solution.firstUniqChar("abaccdeff") << endl;
	return 0;
}
