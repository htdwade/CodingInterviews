/*

剑指Offer
面试题18：删除链表的节点

题目一：在O(1)时间内删除链表节点。
给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。
链表节点与函数的定义如下：
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void DeleteNode(ListNode* head, ListNode* node)
{
	if (head == nullptr || node == nullptr)
		return;
	// 要删除的结点不是尾结点
	if (node -> next != nullptr)
	{
		ListNode* pNext = node -> next;
		node -> val = pNext -> val;
		node -> next = pNext -> next;
		delete pNext;
		pNext = nullptr;
	}
	// 链表只有一个结点，删除头结点（也是尾结点）
	else if (head == node)
	{
		delete node;
		node = nullptr;
		head = nullptr;
	}
	// 链表中有多个结点，删除尾结点
	else
	{
		ListNode* p = head;
		while (p -> next != node)
			p = p -> next;
		p -> next = nullptr;
		delete node;
		node = nullptr;
	}
}

void printList(ListNode* head) {
	ListNode* p = head;
	while (p) {
		cout << p -> val << '\t';
		p = p -> next;
	}
	cout << '\n';
}

int main()
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode* head = p1;
	printList(head);
	DeleteNode(head, p3);
	printList(head);
	return 0;
}