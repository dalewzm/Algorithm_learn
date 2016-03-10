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
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *ret = NULL,*tmp = headA,*bHead = headB;
        int lenA = 1,lenB=1;
        while(tmp->next)
        {
            lenA++;
            tmp = tmp->next;
        }
        tmp->next = headA;
        bool inter = false;
        while(bHead->next){
            if(bHead == headA){
                inter = true;
                break;
            }
            bHead = bHead->next;
        }
        tmp->next = NULL;
        if(!inter)
            return ret;
        //intersec
        bHead = headB;
        while(bHead->next)
        {
            lenB++;
            bHead = bHead->next;
        }
        
        if(lenA >= lenB)
        {
            tmp = headA;
            bHead = headB;
            int diff = lenA -lenB;
            while(diff--)
            {
                tmp = tmp->next;
            }
            while(tmp!=bHead)
            {
                tmp = tmp->next;
                bHead = bHead ->next;
            }
            ret = tmp;
        }
        else{
            tmp = headA;
            bHead = headB;
            int diff = lenB -lenA;
            while(diff--)
            {
                bHead = bHead->next;
            }
            while(tmp!=bHead)
            {
                tmp = tmp->next;
                bHead = bHead ->next;
            }
            ret = tmp;
        }
        
        
        
        return ret;
    }
};
