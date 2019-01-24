/*

剑指Offer
面试题51：数组中的逆序对

题目：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。例如，在数组{7,5,6,4}中，一共存在5个逆序对，
分别是(7,6)，(7,5)，(7,4)，(6,4)和(5,4)。

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.empty())
			return 0;
		mergeSort(data, 0, data.size() - 1);
		return count % 1000000007;
	}

private:
	long long count = 0;

	void mergeSort(vector<int>& data, int left, int right) {
		if (left >= right)
			return;
		int mid = left + (right - left) / 2;
		mergeSort(data, left, mid);
		mergeSort(data, mid + 1, right);
		merge(data, left, mid, right);
	}

	void merge(vector<int>& data, int left, int mid, int right) {
		vector<int> tmp;
		int i = left, j = mid + 1;
		while (i <= mid && j <= right) {
			if (data[i] <= data[j])
				tmp.push_back(data[i++]);
			else {
				tmp.push_back(data[j++]);
				count += mid - i + 1;
			}
		}
		while (i <= mid)
			tmp.push_back(data[i++]);
		while (j <= right)
			tmp.push_back(data[j++]);
		for (int k = 0; k < tmp.size(); k++)
			data[left + k] = tmp[k];
	}

};

int main()
{
	Solution solution;
	vector<int> data = { 7,5,6,4 };
	cout << solution.InversePairs(data) << endl;
	return 0;
}
