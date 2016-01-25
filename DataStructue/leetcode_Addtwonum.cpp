//LinkedList
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		ListNode *psum,*temp,*head;
		psum=NULL;
		int carry=0;
		while(l1!=NULL || l2!=NULL || carry)
		{
			if(l1!=NULL){
				carry+=l1->val;
				l1=l1->next;
			}
			if(l2!=NULL){
				carry+=l2->val;
				l2=l2->next;
			}
			if(psum==NULL){
				psum=new ListNode(carry%10);
				head=psum;
			}
			else{
				temp=new ListNode(carry%10);
				psum->next=temp;
				psum=psum->next;
			}
			carry/=10;
		}
		return head;
	}
};
