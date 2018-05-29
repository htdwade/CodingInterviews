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

using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int x) : m_nValue(x), m_pLeft(nullptr), m_pRight(nullptr) {}
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// 前序遍历序列的第一个数字是根结点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode(rootValue);
	// 在中序遍历中找到根结点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// 构建左子树
		root -> m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// 构建右子树
		root -> m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

void preorderPrint(BinaryTreeNode* root) {
	if (root) {
		cout << root->m_nValue << '\t';
		preorderPrint(root->m_pLeft);
		preorderPrint(root->m_pRight);
	}
}

int main()
{
	int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int length = 8;
	BinaryTreeNode* root = Construct(preorder, inorder, length);
	preorderPrint(root);
	return 0;
}