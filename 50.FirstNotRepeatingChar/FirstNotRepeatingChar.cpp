/*

剑指Offer
面试题50：第一个只出现一次的字符

题目一：字符串中第一个只出现一次的字符。在字符串中找出第一个只出现一次的字符。
如输入"abaccdeff"，则输出'b'。

题目二：字符流中第一个只出现一次的字符。请实现一个函数，用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'，当从该字符流中读出前6个字符"google"时，
第一个只出现一次的字符是'l'。

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

	//字符流中第一个只出现一次的字符
	//Insert one char from stringstream
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (auto c : s)
			if (hash[c] == 1)
				return c;
		return '#';
	}

private:
	unordered_map<char, int> hash;
	string s;
};

int main()
{
	Solution solution;
	cout << solution.firstUniqChar("abaccdeff") << endl;
	solution.Insert('g');
	solution.Insert('o');
	cout << solution.FirstAppearingOnce() << endl;
	solution.Insert('o');
	solution.Insert('g');
	solution.Insert('l');
	solution.Insert('e');
	cout << solution.FirstAppearingOnce() << endl;
	return 0;
}
