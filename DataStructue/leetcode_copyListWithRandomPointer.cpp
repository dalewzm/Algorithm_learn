// 先不管random 指针，把整个链表复制一遍
//同时用hash表记录原链表，每个节点指针对应的位置
//另外一个哈希表记录复制链表位置所应得指针
//然后再遍历一遍原链表，处理复制链表中random指针的赋值

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead = NULL,*listEnd=NULL;
        RandomListNode *srcHead = head;
        unordered_map<RandomListNode*, int> getPos;
        unordered_map<int,RandomListNode*> getPointer;
        int cnt = 0;
        while(srcHead){
            if(cnt == 0)
            {
                newHead = new RandomListNode(srcHead->label);
                listEnd = newHead;
                
            }
            else{
                listEnd->next = new RandomListNode(srcHead->label);
                listEnd = listEnd->next;
            }
            getPos[srcHead] = cnt;
            getPointer[cnt] = listEnd;
            srcHead = srcHead->next;
            cnt++;
        }
        srcHead = head;
        listEnd = newHead;
        int idx = 0;
        while(srcHead){
            if(srcHead->random)
            {
                idx = getPos[srcHead->random];
                listEnd->random = getPointer[idx];
            }
            else{
                listEnd->random = NULL;
            }
            srcHead = srcHead->next;
            listEnd = listEnd->next;
        }
        
        return newHead;
    }
};
