/*

剑指Offer
面试题8：二叉树的下一个节点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

*/

#include <iostream>

using namespace std;

struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
	BinaryTreeNode(int x) : m_nValue(x), m_pLeft(nullptr), m_pRight(nullptr), m_pParent(nullptr) {}
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode* pNext = nullptr;
	if (pNode -> m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode -> m_pRight;
		while (pRight -> m_pLeft != nullptr)
			pRight = pRight -> m_pLeft;
		pNext = pRight;
	}
	else if (pNode -> m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode -> m_pParent;
		while (pParent != nullptr && pCurrent == pParent -> m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent -> m_pParent;
		}
		pNext = pParent;
	}
	return pNext;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
		if (pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if (pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}


//            8
//        6      10
//      5   7  9    11
int main()
{
	BinaryTreeNode* pNode8 = new BinaryTreeNode(8);
	BinaryTreeNode* pNode6 = new BinaryTreeNode(6);
	BinaryTreeNode* pNode10 = new BinaryTreeNode(10);
	BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
	BinaryTreeNode* pNode7 = new BinaryTreeNode(7);
	BinaryTreeNode* pNode9 = new BinaryTreeNode(9);
	BinaryTreeNode* pNode11 = new BinaryTreeNode(11);
	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	cout << GetNext(pNode5)->m_nValue << endl;
	cout << GetNext(pNode7)->m_nValue << endl;
	if (GetNext(pNode11) == nullptr)
		cout << "susscess" << endl;
	return 0;
}