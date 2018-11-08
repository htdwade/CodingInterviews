/*

剑指Offer
面试题8：二叉树的下一个节点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

*/

#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == nullptr)
            return nullptr;
    if(pNode -> right){
        TreeLinkNode* cur = pNode -> right;
        while(cur -> left)
            cur = cur -> left;
        return cur;
    }
    while(pNode -> next){
        TreeLinkNode* parent = pNode -> next;
        if(pNode == parent -> left)
            return parent;
        pNode = parent;
    }
    return nullptr;
}

void ConnectTreeNodes(TreeLinkNode* pParent, TreeLinkNode* pLeft, TreeLinkNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
		if (pLeft != nullptr)
			pLeft->next = pParent;
		if (pRight != nullptr)
			pRight->next = pParent;
	}
}


//            8
//        6      10
//      5   7  9    11
int main()
{
	TreeLinkNode* pNode8 = new TreeLinkNode(8);
	TreeLinkNode* pNode6 = new TreeLinkNode(6);
	TreeLinkNode* pNode10 = new TreeLinkNode(10);
	TreeLinkNode* pNode5 = new TreeLinkNode(5);
	TreeLinkNode* pNode7 = new TreeLinkNode(7);
	TreeLinkNode* pNode9 = new TreeLinkNode(9);
	TreeLinkNode* pNode11 = new TreeLinkNode(11);
	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	cout << GetNext(pNode5)->val << endl;
	cout << GetNext(pNode7)->val << endl;
	if (GetNext(pNode11) == nullptr)
		cout << "susscess" << endl;
	return 0;
}
