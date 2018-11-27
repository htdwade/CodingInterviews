/* 

剑指Offer
面试题3：数组中重复的数字
题目一：找出数组中重复的数字
在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是重复的数字2或者3。

题目二：不修改数组找出数组中重复的数字
在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至
少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
输出是重复的数字2或者3。

*/

#include <iostream>
#include <vector>

using namespace std;

// 题目一
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}
	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			swap(numbers[i], numbers[numbers[i]]);
		}
	}
	return false;
}

// 题目二
int findDuplicate(vector<int>& nums) 
{
    if(nums.size() < 2)
        return -1;
    for(auto a : nums)
        if(a < 1 || a > nums.size() - 1)
            return -1;
    int start = 1, end = nums.size() - 1;
    while(start < end){
        int count = 0;
        int mid = start + (end - start) / 2;
        for(auto num : nums)
            if(num <= mid)
                count++;
        if(count <= mid)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main()
{
	int numbers1[] = { 2, 3, 1, 0, 2, 5, 3 };
	int *duplication = new int(-1);
	int length1 = sizeof(numbers1) / sizeof(numbers1[0]);
	duplicate(numbers1, length1, duplication);
	cout << *duplication << endl;

	vector<int> numbers2 = { 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << findDuplicate(numbers2) << endl;

	return 0;
}