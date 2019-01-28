/*

剑指Offer
面试题32：从上到下打印二叉树

题目三：之字形打印二叉树
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
第三行再按照从左到右的顺序打印，其他行以此类推。

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//之字形打印二叉树
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		bool leftToRight = true;
		while (!q.empty()) {
			int n = q.size();
			vector<int> level(n);
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front();
				q.pop();
				if (leftToRight)
					level[i] = t->val;
				else
					level[n - 1 - i] = t->val;
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
			res.push_back(level);
			leftToRight = !leftToRight;
		}
		return res;
	}
};

TreeNode* createBinaryTree() {
	int x;
	cin >> x;
	if (x == 0)
		return nullptr;
	TreeNode* root = new TreeNode(x);
	root->left = createBinaryTree();
	root->right = createBinaryTree();
	return root;
}

int main()
{
	Solution solution;
	TreeNode* root = createBinaryTree();
	cout << "二叉树创建完成" << endl;
	vector<vector<int>> res = solution.zigzagLevelOrder(root);
	for (auto v : res) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}