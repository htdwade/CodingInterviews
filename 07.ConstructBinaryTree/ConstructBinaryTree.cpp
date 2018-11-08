/*

剑指Offer
面试题7：重建二叉树
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
如图所示的二叉树并输出它的头结点。
			  1
           /     \
          2       3
         /       / \
        4       5   6
         \         /
          7       8
二叉树节点的定义如下：
struct BinaryTreeNode{
int m_nValue;
BinaryTreeNode* m_pLeft;
BinaryTreeNode* m_pRight;
};

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* construct(vector<int>& pre, int preStart, int preEnd, vector<int>& vin, int inStart, int inEnd);
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size() == 0 || vin.size() == 0)
        return nullptr;
    return construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
}

TreeNode* construct(vector<int>& pre, int preStart, int preEnd, vector<int>& vin, int inStart, int inEnd){
    if(preStart > preEnd || inStart > inEnd)
        return nullptr;
    TreeNode* root = new TreeNode(pre[preStart]);
    int inRoot = inStart;
    while(vin[inRoot] != pre[preStart])
        inRoot++;
    int leftLength = inRoot - inStart;
    root -> left = construct(pre, preStart + 1, preStart + leftLength, vin, inStart, inRoot - 1);
    root -> right = construct(pre, preStart + leftLength + 1, preEnd, vin, inRoot + 1, inEnd);
    return root;
}

void preorderPrint(TreeNode* root) {
	if (root) {
		cout << root -> val << '\t';
		preorderPrint(root -> left);
		preorderPrint(root -> right);
	}
}

int main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = reConstructBinaryTree(pre, vin);
	preorderPrint(root);
	return 0;
}
