/*

剑指Offer
面试题24：反转链表

题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur) {
			ListNode* pNext = cur->next;
			cur->next = pre;
			pre = cur;
			cur = pNext;
		}
		return pre;
	}

	//递归
	ListNode* reverseList2(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* pNext = head->next;
		ListNode* newHead = reverseList(pNext);
		pNext->next = head;
		head->next = nullptr;
		return newHead;
	}
};

void printList(ListNode* head) {
	ListNode* p = head;
	while (p) {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << '\n';
}

int main()
{
	Solution solution;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode* head = p1;
	printList(head);
	ListNode* newHead = solution.reverseList(head);
	printList(newHead);
	return 0;
}