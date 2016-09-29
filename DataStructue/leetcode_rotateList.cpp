class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* tmpHead = head, *last = NULL;
        int len = 0;
        while( tmpHead ){
            len++;
            last = tmpHead;
            tmpHead = tmpHead->next;
            
        }
        k = k % len;
        if(k == 0)
            return head;
        int flag = len - k- 1;
        ListNode *first = NULL,*sec = NULL, *thr = NULL;
        int cnt = 0;
        first = tmpHead = head;
        while(cnt < flag)
        {
            tmpHead = tmpHead->next;
            cnt++;
        }
        sec = tmpHead;
        thr = sec->next;
        sec->next = NULL;
        last->next = head;
        return thr;
    }
};
