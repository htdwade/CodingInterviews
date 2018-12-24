/*

剑指Offer
面试题34：二叉树中和为某一值的路径

题目：输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

*/

#include <iostream>
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> path;
		dfs(root, sum, res, path);
		return res;
	}

private:
	void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path) {
		if (root == nullptr)
			return;
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr && sum == root->val)
			res.push_back(path);
		dfs(root->left, sum - root->val, res, path);
		dfs(root->right, sum - root->val, res, path);
		path.pop_back();
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
	vector<vector<int>> res = solution.pathSum(root, 22);
	for (auto v : res) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}