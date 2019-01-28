/*

剑指Offer
面试题55：二叉树的深度

题目二：平衡二叉树。输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左，右子树
的深度相差不超过1，那么它就是一棵平衡二叉树。

*/

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return height(root) != -1;
	}

private:
	int height(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = height(root->left);
		if (left == -1)
			return -1;
		int right = height(root->right);
		if (right == -1)
			return -1;
		if (abs(left - right) > 1)
			return -1;
		return 1 + max(left, right);
	}
};

int main()
{
	Solution solution;
	TreeNode* p1 = new TreeNode(3);
	TreeNode* p2 = new TreeNode(9);
	TreeNode* p3 = new TreeNode(20);
	TreeNode* p4 = new TreeNode(15);
	TreeNode* p5 = new TreeNode(7);
	p1->left = p2;
	p1->right = p3;
	p3->left = p4;
	p3->right = p5;
	TreeNode* root = p1;
	cout << solution.isBalanced(root) << endl;
	return 0;
}
