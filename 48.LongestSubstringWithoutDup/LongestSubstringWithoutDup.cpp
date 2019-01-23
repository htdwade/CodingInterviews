/*

剑指Offer
面试题48：最长不含重复字符的子字符串

题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
假设字符串中只包含'a' ~ 'z'的字符。例如，在字符串"arabcacfr"中，最长的不含重复字符的子字符串是"acfr"，
长度为4。

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        if(s.empty())
            return 0;
        vector<int> hash(26, -1);
        int start = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i] - 'a'] >= start)
                start = hash[s[i] - 'a'] + 1;
            hash[s[i] - 'a'] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
};

int main()
{
	Solution solution;
	cout << solution.longestSubstringWithoutDuplication("arabcacfr") << endl;
	return 0;
}
