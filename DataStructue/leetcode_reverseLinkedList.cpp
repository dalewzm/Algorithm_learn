/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //a better solution not need to copy elements
 class Solution {
public:
     ListNode* reverseList(ListNode* head) {
       if(!head)
           return NULL;
        ListNode *newhead = NULL,*next;
        while(head){
            next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
    }
};
 
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
