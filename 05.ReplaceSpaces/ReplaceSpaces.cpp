/*

剑指Offer
面试题5：二维数组中的查找
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。

*/

#include <iostream>
#include <cstdio>

using namespace std;

void replaceSpace(char *str,int length) {
    if(str == nullptr || length <= 0)
        return;
    int originLength = 0;
    int count = 0;
    char *p = str;
    while(*p != '\0'){
        if(*p == ' ')
            count++;
        originLength++;
        p++;
    }
    int newLength = originLength + 2 * count;
    if(newLength >= length)
        return;
    int originIndex = originLength;
    int newIndex = newLength;
    while(originIndex >=0 && newIndex > originIndex){
        if(str[originIndex] == ' '){
            str[newIndex--] = '0';
            str[newIndex--] = '2';
            str[newIndex--] = '%';
        }
        else
            str[newIndex--] = str[originIndex];
        originIndex--;
    }
}

int main()
{
	char str[20] = "We are happy.";
	replaceSpace(str, 20);
	printf("%s\n", str);
	return 0;
}
