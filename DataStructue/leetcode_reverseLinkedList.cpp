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
    ListNode* reverseList(ListNode* head) {
        if(!head)
         return NULL;
       
        ListNode* src =new ListNode(head->val) ,*tmp=0,*origin = head;
        while(head->next){
            tmp = new ListNode(head->next->val);
            tmp->next = src;
            src = tmp;
            head = head->next;
        }
        origin->next = NULL;
        while(origin){
            tmp = origin;
            origin = origin->next;
            delete tmp;
            
        }
        
        return src;
    }
};
