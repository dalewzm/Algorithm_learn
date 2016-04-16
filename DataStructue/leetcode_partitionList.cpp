// 重新维护两个新链表
//一条维持 val < x，且值按照原链表的顺序
//一条维护 val >= x，，且值按照原链表的顺序
// 时间复杂度O(n)
// 空间复杂度O(1)
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {

		ListNode *smallListfp = NULL, *smallListlp = NULL;
		ListNode *largeListfp = NULL, *largeListlp = NULL;
		ListNode *tmp = NULL;
		bool smallFirst = false, largeFirst = false;
		while (head){
			tmp = head->next;
			if (head->val < x)
			{
				if (!smallFirst){
					smallListfp = head;
					smallListlp = head;
					smallListlp->next = NULL;
					smallFirst = true;
				}
				else{
					smallListlp->next = head;
					smallListlp = head;
					smallListlp->next = NULL;
				}
			}
			else{
				if (!largeFirst)
				{
					largeListfp = head;
					largeListlp = head;
					largeListlp->next = NULL;
					largeFirst = true;
				}
				else{
					largeListlp->next = head;
					largeListlp = head;
					largeListlp->next = NULL;
				}
			}
			head = tmp;
		}

		if (!smallListfp){
			return largeListfp;
		}
		if (!largeListfp){
			return smallListfp;
		}
		smallListlp->next = largeListfp;
		return smallListfp;
	}
};
