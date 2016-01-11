//Time complexity  O(m)  m is the length of the integer
//Space complexity O(1)
class Solution {
public:
	int reverse(int x) {
	   
		if( x>=0 )
			return reverse2(x);
		else{
			return -reverse2(-x);
		}
	}
	int reverse2(int x){
		 int digit[11];
		 int num=1;
		 int count=0;
		 int ans=0;
		 if(0==x)
			 return 0;
		 while(x){
			 digit[count++]=x%10;
			 x/=10;		 
		 }
		 for(count--; count>=0; --count){
				ans+=num*digit[count];
			  num*=10;
		 }
		 return ans;
	}
};
