/*

剑指Offer
面试题4：二维数组中的查找
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。

*/

#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int>> array) {
    if(array.size() == 0 || array[0].size() == 0)
        return false;
    int rows = array.size();
    int columns = array[0].size();
    int row = 0;
    int column = columns - 1;
    while(row < rows && column >= 0){
        if(array[row][column] == target)
            return true;
        else if(array[row][column] > target)
            column--;
        else
            row++;
    }
    return false;
}

int main()
{
	vector<vector<int>> array = {{1, 2, 8, 9},
								  {2, 4, 9, 12},
								  {4, 7, 10, 13},
								  {6, 8, 11, 15}};
	cout << Find(18, array) << endl;
	cout << Find(15, array) << endl;
	return 0;
}
