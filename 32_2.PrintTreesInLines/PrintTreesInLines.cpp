/*

剑指Offer
面试题32：从上到下打印二叉树

题目二：分行从上到下打印二叉树
从上到下打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
	vector<vector<int>> res = solution.levelOrder(root);
	for (auto v : res) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}