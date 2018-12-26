/*

剑指Offer
面试题36：二叉搜索树与双向链表

题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。

*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;
		TreeNode* pre = nullptr;
		convertCore(pRootOfTree, pre);
		TreeNode* head = pRootOfTree;
		while (head->left)
			head = head->left;
		return head;
	}

private:
	void convertCore(TreeNode* pNode, TreeNode*& pre) {
		if (pNode == nullptr)
			return;
		convertCore(pNode->left, pre);
		pNode->left = pre;
		if (pre != nullptr)
			pre->right = pNode;
		pre = pNode;
		convertCore(pNode->right, pre);
	}
};

int main()
{
	Solution solution;
	TreeNode* p1 = new TreeNode(2);
	TreeNode* p2 = new TreeNode(1);
	TreeNode* p3 = new TreeNode(3);
	p1->left = p2;
	p1->right = p3;
	TreeNode* root = p1;
	TreeNode* head = solution.Convert(root);
	cout << head->val << endl;
	cout << head -> right -> val << endl;
	cout << head->right->right->val << endl;
	cout << head->right->right->left->val << endl;
	cout << head->right->right->left->left->val << endl;
	return 0;
}