/*

剑指Offer
面试题15：二进制中1的个数
题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

*/

#include <iostream>

using namespace std;

int NumberOf1_Solution1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1) & n;
	}
	return count;
}

int main()
{
	cout << NumberOf1_Solution1(9) << endl;
	cout << NumberOf1_Solution2(9) << endl;
	return 0;
}