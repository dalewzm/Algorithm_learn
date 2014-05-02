//Use temp array,time complexity  is  O(2(m+n))=O(m+n)
//space complexity is O(m+n)
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i=0,j=0,count=0;
		int *c=new int[m+n];
		while(i<m || j<n){
			if( i<m && j<n){
				if(A[i]<B[j]){
					c[count++]=A[i++];
				}
				else
					c[count++]=B[j++];
			}
			else if(i<m){
				c[count++]=A[i++];
			}
			else{
				c[count++]=B[j++];
			}
		}
		for(i=0; i<count; ++i)
			A[i]=c[i];
		delete []c;
	}
};