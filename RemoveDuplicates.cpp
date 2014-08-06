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
//Remove Duplicates from Sorted Array II
//由链表改为数组，同样记录前后两个变量，给重复的变量允许两次机会
//----------------------------------------------------------------------------------
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int *copy = new int[n];
		if (A == NULL || n == 0)
			return 0;
		int max = 2;
		int j = 1;
		copy[0] = A[0];
		for (int i = 0; i < n-1; ++i)
		{
			if (A[i] == A[i + 1])
			{
				max--;
				if (max > 0)
				{
					copy[j++] = A[i + 1];					
				}
			}
			else{
				max = 2;
				copy[j++] = A[i + 1];
			}
		}
		for (int i = 0; i < j; ++i)
			A[i] = copy[i];
		delete[] copy;
		return j;
	}
};
