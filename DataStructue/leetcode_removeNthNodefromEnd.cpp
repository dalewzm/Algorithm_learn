//a better solution not used extra space to get answer
class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode *faster = head,*slow = head;
        while(n--) //to get delete pre node
            faster = faster->next;
        
        if(faster == NULL) //delete node is first node
        {
            faster = head->next;
            delete head;
            return faster;
        }
        while(faster->next)//faster before null,slow will point to pre delete node
        {
            faster = faster->next;
            slow = slow->next;
        }
       
        faster = slow->next;//faster now is delete node
        slow->next = faster->next;
        delete faster;
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <vector>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          vector<ListNode*> larray;
          ListNode *src = head;
          while(src){
              larray.push_back(src);
              src = src->next;
          }
          if(larray.size()==1)
           return NULL;
           if(larray.size() == 2)
            {
                //need delete one
                delete larray[2-n];
                larray[n-1]->next = NULL;
                return larray[n-1];
            }
          int preDel = larray.size() - n -1;
          if(preDel<0)
          {
              //need delete;
              return larray[preDel+1]->next;
          }
          larray[preDel]->next = larray[preDel+1]->next;
          delete larray[preDel+1];
          return head;
    }
};
