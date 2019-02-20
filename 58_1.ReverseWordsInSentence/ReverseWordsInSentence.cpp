/*

剑指Offer
面试题58：翻转字符串

题目一：翻转单词顺序。输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student.  a am I"。

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		int start = 0, index = 0;
		while (index <= str.size()) {
			if (index == str.size() || str[index] == ' ') {
				reverse(str.begin() + start, str.begin() + index);
				start = index + 1;
			}
			index++;
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	Solution solution;
	string s = "I am a student. ";
	cout << solution.ReverseSentence(s) << endl;
	return 0;
}
