/*

剑指Offer
面试题32：从上到下打印二叉树

题目一：不分行从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

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
	vector<int> res = solution.PrintFromTopToBottom(root);
	for (auto x : res)
		cout << x << '\t';
	return 0;
}