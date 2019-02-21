/*

剑指Offer
面试题68：树中两个节点的最低公共祖先

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return left == nullptr ? right : right == nullptr ? left : root;
	}
};

int main()
{
	Solution solution;
	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(2);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p4 = new TreeNode(4);
	p1->left = p2;
	p1->right = p3;
	p3->right = p4;
	TreeNode* root = p1;
	cout << solution.lowestCommonAncestor(p1, p2, p4) ->val << endl;
	return 0;
}
