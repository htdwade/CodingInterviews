/*

剑指Offer
面试题54：二叉搜索树的第K小节点

题目：给定一棵二叉搜索树，请找出其中第k小的节点。

*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int res = 0;
		dfs(root, k, res);
		return res;
	}

private:
	void dfs(TreeNode* root, int& k, int& res) {
		if (root == nullptr)
			return;
		dfs(root->left, k, res);
		--k;
		if (k == 0) {
			res = root->val;
			return;
		}
		dfs(root->right, k, res);
	}
};

int main()
{
	Solution solution;
	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(2);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p4 = new TreeNode(4);
	p3->left = p1;
	p3->right = p4;
	p1->right = p2;
	TreeNode* root = p3;
	cout << solution.kthSmallest(root, 1) << endl;
	return 0;
}
