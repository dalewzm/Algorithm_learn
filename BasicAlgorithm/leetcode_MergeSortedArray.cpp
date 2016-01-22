//Method1: AC
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


//Method2: TLE
//Don't use temp array, worst time  complexity is O(mn+m)=O(mn)
//but space complexity is O(1)
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i=0,j=0,count=0,k;
		
		while(i<m || j<n){
			if( i<m && j<n){
				if(A[count]<=B[j]){
					count++;
					i++;
				}
				else{
					for(k=m-i; k>=0; --k)
						A[count+k+1]=A[count+k];
					A[count++]=B[j++];
				}
			}
			else if(i<m){
				continue;
			}
			else{
				A[count++]=B[j++];
			}
		}
		
	
	}
};  
