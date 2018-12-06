/*

剑指Offer
面试题17：打印从1到最大的n位数
题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
打印出1、2、3一直到最大的3位数即999。

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void Print1ToMaxOfNDigits(int n)
	{
		if (n <= 0)
			return;
		string s(n, '0');
		dfs(s, 0);
	}

private:
	void dfs(string& s, int index) {
		if (index == s.size()) {
			print(s);
			return;
		}
		for (int i = 0; i < 10; i++) {
			s[index] = i + '0';
			dfs(s, index + 1);
		}
	}

	void print(string s)
	{
		int i = 0;
		while (i < s.size() && s[i] == '0')
			i++;
		if (i == s.size())
			return;
		cout << s.substr(i) << endl;
	}
};

int main()
{
	Solution solution;
	solution.Print1ToMaxOfNDigits(-1);
	solution.Print1ToMaxOfNDigits(3);
	return 0;
}





