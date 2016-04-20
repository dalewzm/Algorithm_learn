//解法一
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


//解法二
//不需要额外空间
//1.先将原链表复制，每个节点复制一份作为自己的后继
//例如：A->B  A->a->B->b
//2.修改复制节点的random指针，即将复制节点的random 改为指向节点的next 节点
//例如，假设上例B == A->random,那么复制后B == a->random, 不正确，应该B->next== b == a->random
//3.将复制节点从链表中分离出来
class Solution {
public:
	void copyToOneList(RandomListNode* head)
	{
		RandomListNode *nextNode = NULL;
		while (head){
			nextNode = head->next;
			RandomListNode *cpNode = new RandomListNode(head->label);
			cpNode->next = head->next;
			cpNode->random = head->random;
			head->next = cpNode;
			head = nextNode;

		}
	}

	void correctRandomPointer(RandomListNode* head)
	{
		RandomListNode *cpNode = NULL;
		RandomListNode *randomNode = NULL;
		while (head){
			cpNode = head->next;
			if (cpNode->random)
			{
				randomNode = cpNode->random;
				cpNode->random = randomNode->next;
			}
			head = cpNode->next;
		}

	}
	RandomListNode* seprateList(RandomListNode* head)
	{
		RandomListNode* cpHead = NULL,*cpEnd = NULL;
		RandomListNode* cpNode = NULL;
		int cnt = 0;
		while (head){
			cpNode = head->next;
			if (cnt  == 0)
			{
				cpHead = cpNode;
				cpEnd = cpHead;
				cnt++;
			}
			else{
				cpEnd->next = cpNode;
				cpEnd = cpEnd->next;
			}
			head->next = cpNode->next;
			head = cpNode->next;
		}
		return cpHead;

	}

	RandomListNode *copyRandomList(RandomListNode *head) {
		copyToOneList(head);
		correctRandomPointer(head);
		return seprateList(head);
	}
};
