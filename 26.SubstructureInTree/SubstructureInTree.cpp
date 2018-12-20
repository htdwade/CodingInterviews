/*

剑指Offer
面试题26：树的子结构

题目：输入两棵二叉树A和B，判断B是不是A的子结构。

*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr || t == nullptr)
			return false;
		return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}

private:
	bool isSame(TreeNode* s, TreeNode* t) {
		if (t == nullptr)
			return true;
		if (s == nullptr)
			return false;
		if (s->val != t->val)
			return false;
		return isSame(s->left, t->left) && isSame(s->right, t->right);
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
	TreeNode* s = createBinaryTree();
	cout << "s创建完成" << endl;
	TreeNode* t = createBinaryTree();
	cout << "t创建完成" << endl;
	cout << solution.isSubtree(s, t) << endl;
	return 0;
}