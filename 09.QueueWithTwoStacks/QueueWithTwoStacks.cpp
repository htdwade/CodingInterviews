/*

剑指Offer
面试题9：用两个栈实现队列
题目：用两个栈实现一个队列。

*/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty())
			throw new exception("队列为空，出栈失败");
		int t = stack2.top();
		stack2.pop();
		return t;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution solution;
	solution.push(1);
	solution.push(2);
	solution.push(3);
	cout << solution.pop() << endl;
	solution.push(4);
	cout << solution.pop() << endl;
	cout << solution.pop() << endl;
	return 0;
}