/*

剑指Offer
面试题11：旋转数组的最小数字
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

*/

#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() == 0)
        return 0;
    int start =0, end = rotateArray.size() - 1;
    while(start < end){
        int mid = start + (end - start) / 2;
        if(rotateArray[mid] == rotateArray[end])
            end--;
        else if(rotateArray[mid] < rotateArray[end])
            end = mid;
        else
            start = mid + 1;
    }
    return rotateArray[start];
}

int main()
{
	vector<int> nums = { 3, 4, 5, 1, 2 };
	cout << minNumberInRotateArray(nums) << endl;
	return 0;
}
