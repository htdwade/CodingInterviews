/*

剑指Offer
面试题41：数据流中的中位数

题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后
位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		left.push(num);
		right.push(left.top());
		left.pop();
		if (left.size() < right.size()) {
			left.push(right.top());
			right.pop();
		}
	}

	double findMedian() {
		return left.size() > right.size() ? left.top() : (left.top() + right.top()) / 2.0;
	}

private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main()
{
	MedianFinder obj;
	obj.addNum(3);
	cout << obj.findMedian() << endl;
	obj.addNum(7);
	cout << obj.findMedian() << endl;
	obj.addNum(6);
	cout << obj.findMedian() << endl;
	obj.addNum(5);
	cout << obj.findMedian() << endl;
	return 0;
}
