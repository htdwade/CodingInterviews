/*

剑指Offer
面试题31：栈的压入、弹出序列

题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的的所有数字均不相等。例如，序列{1,2,3,4,5}是某栈的压栈序列，序列{4,5,3,2,1}是该压栈序列对应的一个弹出序列，
但{4,5,3,1,2}就不可能是该压栈序列的弹出序列。

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> sta;
		int i = 0;
		for (int x : pushed) {
			sta.push(x);
			while (!sta.empty() && sta.top() == popped[i]) {
				sta.pop();
				++i;
			}
		}
		return sta.empty();
	}
};

int main()
{
	Solution solution;
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,3,2,1 };
	vector<int> v3 = { 4,5,3,1,2 };
	cout << solution.validateStackSequences(v1, v2) << endl;
	cout << solution.validateStackSequences(v1, v3) << endl;
	return 0;
}