/*

剑指Offer
面试题32：从上到下打印二叉树

题目一：不分行从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

题目二：分行从上到下打印二叉树
从上到下打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
	//不分行从上到下打印二叉树
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			res.push_back(t->val);
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
		return res;
	}
	//分行从上到下打印二叉树
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			vector<int> level;
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
			res.push_back(level);
		}
		return res;
	}
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
	vector<int> res1 = solution.PrintFromTopToBottom(root);
	for (auto x : res1)
		cout << x << '\t';
	cout << '\n';
	vector<vector<int>> res2 = solution.levelOrder(root);
	for (auto v : res2) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	vector<vector<int>> res3 = solution.zigzagLevelOrder(root);
	for (auto v : res3) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}