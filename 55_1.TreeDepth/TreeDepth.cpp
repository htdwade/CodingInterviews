/*

剑指Offer
面试题55：二叉树的深度

题目一：二叉树的深度。输入一棵二叉树的根结点，求该树的深度。从根节点到叶节点依次经过的节点形成树的一条路径，
最长路径的长度为树的深度。

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
	int maxDepth(TreeNode* root) {
		return root == nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
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
	cout << solution.maxDepth(root) << endl;
	return 0;
}
