/* 

剑指Offer
面试题3：数组中重复的数字
题目二：不修改数组找出数组中重复的数字
在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至
少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
输出是重复的数字2或者3。

*/

#include <iostream>

using namespace std;

int countRange(const int* numbers, int length, int start, int end);
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字
int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;
	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++)
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	return count;
}

int main()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int length = sizeof(numbers) / sizeof(numbers[0]);
	cout << getDuplication(numbers, length) << endl;
	return 0;
}