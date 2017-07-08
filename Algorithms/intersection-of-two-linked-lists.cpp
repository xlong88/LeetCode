// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
				   ↘
					 c1 → c2 → c3
				   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lA = f1(headA), lB = f1(headB);
		if (lA < lB) {
			for (int i = 0; i < lB - lA; ++i) {
				headB = headB->next;
			}
		}
		else {
			for (int i = 0; i < lA - lB; ++i) {
				headA = headA->next;
			}
		}
		while (headA and headB and headA != headB) {
			headA = headA->next;
			headB = headB->next;
		}
		return headA == headB ? headA : NULL;
	}
private:
	int f1(ListNode * head) {
		int result = 0;
		while (head) {
			++result;
			head = head->next;
		}
		return result;
	}
};