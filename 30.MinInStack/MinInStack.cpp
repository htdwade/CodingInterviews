/*

剑指Offer
面试题30：包含min函数的栈

题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
在该栈中，调用min，push及pop的时间复杂度都是O(1)。

*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		dataStack.push(x);
		if (minStack.empty() || x < minStack.top())
			minStack.push(x);
		else
			minStack.push(minStack.top());
	}

	void pop() {
		dataStack.pop();
		minStack.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return minStack.top();
	}

private:
	stack<int> dataStack;
	stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
	MinStack minStack;
	minStack.push(3);
	minStack.push(4);
	minStack.push(2);
	minStack.push(1);
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.getMin() << endl;
	minStack.push(0);
	cout << minStack.getMin() << endl;
	return 0;
}