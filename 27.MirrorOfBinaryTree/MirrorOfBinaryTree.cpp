/*

剑指Offer
面试题27：二叉树的镜像

题目：请完成一个函数，输入一棵二叉树，该函数输出它的镜像。

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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		swap(pRoot->left, pRoot->right);
		Mirror(pRoot->left);
		Mirror(pRoot->right);
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

void preorderPrint(TreeNode* root) {
	if (root) {
		cout << root->val << '\t';
		preorderPrint(root->left);
		preorderPrint(root->right);
	}
}

int main()
{
	Solution solution;
	TreeNode* root = createBinaryTree();
	cout << "二叉树创建完成" << endl;
	preorderPrint(root);
	cout << "\n";
	solution.Mirror(root);
	preorderPrint(root);
	return 0;
}