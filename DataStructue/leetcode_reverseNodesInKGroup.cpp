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
    ListNode* reverseLinkedList(ListNode* head){
        if(!head)
            return NULL;
        ListNode* newHead = NULL;
        while(head){
            ListNode* tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = 0;
        ListNode* pHead = head;
        while(pHead && len<k-1){
            len++;
            pHead = pHead->next;
        }
        if(!pHead|| len<k-1)
            return head;
        ListNode* others = pHead->next;
        pHead->next = NULL;
        ListNode *cur = reverseLinkedList(head);
        head->next = reverseKGroup( others, k);
        return cur;
    }
};
