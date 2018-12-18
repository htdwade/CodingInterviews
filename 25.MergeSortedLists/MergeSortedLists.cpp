/*

剑指Offer
面试题25：合并两个排序的链表

题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head(-1);
		ListNode* cur = &head;
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		return head.next;
	}

	//递归
	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		if (l1->val <= l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}

};

ListNode* createList() {
	ListNode head(-1);
	ListNode* cur = &head;
	int x;
	while (cin >> x) {
		ListNode* temp = new ListNode(x);
		cur->next = temp;
		cur = cur->next;
	}
	return head.next;
}

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
	ListNode* l1 = createList();
	cin.clear();
	cin.sync();
	ListNode* l2 = createList();
	ListNode* head = solution.mergeTwoLists(l1, l2);
	printList(head);
	return 0;
}