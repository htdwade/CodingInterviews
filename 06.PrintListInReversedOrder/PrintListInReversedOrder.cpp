/*

剑指Offer
面试题6：从尾到头打印链表
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
链表节点定义如下:
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};

*/

#include <iostream>
#include <stack>

using namespace std;

struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
    ListNode(int x): m_nKey(x), m_pNext(nullptr){}
};

//用栈
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode -> m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode -> m_nKey << '\t';
        nodes.pop();
    }
}

//递归
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr)
        {
            PrintListReversingly_Recursively(pHead -> m_pNext);
        }
        cout << pHead -> m_nKey << '\t';
    }
}

ListNode* createList() {
    ListNode head(-1);
    ListNode* cur = &head;
    int x;
    while(cin >> x){
        ListNode* temp = new ListNode(x);
        cur -> m_pNext = temp;
        cur = cur -> m_pNext;
    }
    return head.m_pNext;
}

int main()
{
    ListNode* head = createList();
    cout << "用栈反向打印:" << endl;
    PrintListReversingly_Iteratively(head);
    cout << '\n';
    cout << "递归反向打印:" << endl;
    PrintListReversingly_Recursively(head);
    return 0;
}
