/*

剑指Offer
面试题20：表示数值的字符串

题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是.

*/

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//正则表达式
	bool isNumber(string s) {
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		if (s.empty())
			return false;
		regex pattern("[+-]?((\\d+(\\.\\d*)?)|(\\.\\d+))([Ee][+-]?\\d+)?");
		return regex_match(s, pattern);
	}

	// DFA
	bool isNumber2(string s) {
		vector<unordered_map<string, int>> state = { {},
													{{"blank", 1}, {"sign", 2}, {"digit", 3}, {".", 4}},
													{{"digit", 3}, {".", 4}},
													{{"blank", 9}, {"digit", 3}, {"exp", 6}, {".", 5}},
													{{"digit", 5}},
													{{"digit", 5}, {"exp", 6}, {"blank", 9}},
													{{"sign", 7}, {"digit", 8}},
													{{"digit", 8}},
													{{"digit", 8}, {"blank", 9}},
													{{"blank", 9}}
		};
		int curState = 1;
		for (auto c : s) {
			string t = "";
			if (c == ' ')
				t = "blank";
			if (c == '+' || c == '-')
				t = "sign";
			if (c >= '0' && c <= '9')
				t = "digit";
			if (c == '.')
				t = ".";
			if (c == 'e' || c == 'E')
				t = "exp";
			if (state[curState].find(t) == state[curState].end())
				return false;
			curState = state[curState][t];
		}
		if (curState == 3 || curState == 5 || curState == 8 || curState == 9)
			return true;
		return false;
	}

};

int main()
{
	Solution solution;
	cout << "正则:" << solution.isNumber("+100") << endl;
	cout << "DFA:" << solution.isNumber2("+100") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("5e2") << endl;
	cout << "DFA:" << solution.isNumber2("5e2") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("-123") << endl;
	cout << "DFA:" << solution.isNumber2("-123") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("3.1416") << endl;
	cout << "DFA:" << solution.isNumber2("3.1416") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("-1E-16") << endl;
	cout << "DFA:" << solution.isNumber2("-1E-16") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("12e") << endl;
	cout << "DFA:" << solution.isNumber2("12e") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("1a3.14") << endl;
	cout << "DFA:" << solution.isNumber2("1a3.14") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("1.2.3") << endl;
	cout << "DFA:" << solution.isNumber2("1.2.3") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("+-5") << endl;
	cout << "DFA:" << solution.isNumber2("+-5") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("12e+5.4") << endl;
	cout << "DFA:" << solution.isNumber2("12e+5.4") << endl;
	cout << '\n';
	return 0;
}