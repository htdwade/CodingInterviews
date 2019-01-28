/*

剑指Offer
面试题18：删除链表的节点

题目二：删除链表中重复的节点。
在一个排序的链表中，如何删除重复的节点？

*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* pre = dummy;
	ListNode* cur = head;
	while (cur != nullptr) {
		while (cur->next != nullptr && cur->val == cur->next->val)
			cur = cur->next;
		if (pre->next == cur)
			pre = pre->next;
		else
			pre->next = cur->next;
		cur = cur->next;
	}
	return dummy->next;
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
	ListNode* newHead = deleteDuplicates(head);
	printList(newHead);
	return 0;
}