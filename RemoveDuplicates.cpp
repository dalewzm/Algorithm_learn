/*-------------------------------------------------------
Remove Duplicates from Sorted List Total Accepted: 21379 Total Submissions: 61447 My Submissions
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.-
--------------------------------------------------------
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
	ListNode *deleteDuplicates(ListNode *head) {
		if (NULL == head || head->next == NULL)
			return head;
		ListNode *last, *now;
		last = head;
		now = head->next;
		while (now){
			if (last->val == now->val)
			{
				ListNode *temp = now;
				now = now->next;
				last->next = now;
				delete temp;
				
			}
			else{
				last = now;
				now = now->next;
			}
			
		}
		return head;
	}
};
