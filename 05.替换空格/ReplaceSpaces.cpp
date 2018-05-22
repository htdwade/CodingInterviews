/* 

剑指Offer
面试题5：二维数组中的查找
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。

*/

#include <iostream>
#include <cstdio>

using namespace std;

void ReplaceBlank(char str[], int length)
{
	if (str == nullptr && length <= 0)
		return;
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++originalLength;
		if (str[i] == ' ')
			++numberOfBlank;
		++i;
	}
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength >= length)
		return;
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

int main()
{	
	char str[20] = "We are happy.";
	ReplaceBlank(str, 20);
	printf("%s\n", str);
	return 0;
}