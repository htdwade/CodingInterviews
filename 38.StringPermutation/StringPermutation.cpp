/*

剑指Offer
面试题38：字符串的排列

题目：输入一个字符串，按字典序打印出该字符串中字符的所有排列。例如，输入字符串abc，
则打印出由字符a，b，c所能排列出来的所有字符串abc，acb，bac，bca，cab和cba。

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return vector<string>();
		vector<string> res;
		helper(res, str, 0);
		sort(res.begin(), res.end());
		return res;
	}

private:
	void helper(vector<string>& res, string& str, int index) {
		if (index == str.size()) {
			res.push_back(str);
			return;
		}
		unordered_set<char> s;
		for (int i = index; i < str.size(); i++) {
			if (s.find(str[i]) != s.end())
				continue;
			s.insert(str[i]);
			swap(str[index], str[i]);
			helper(res, str, index + 1);
			swap(str[index], str[i]);
		}
	}
};
int main()
{
	Solution solution;
	vector<string> res = solution.Permutation("abc");
	for (auto s : res)
		cout << s << endl;
	return 0;
}