//get a series of numbers inverve pairs
//the inverse pairs differences between 2 permutation
// num[i][j]=k, 代表从j到末尾比第i个数小的数的个数为k
#include <cstdio>
#include <memory.h>
using namespace std;
inline void swap(int &a, int &b)
{
    int tmp = a;
    a =b;
    b = tmp;
}
int temp[5001];
int divideSort(int a[],int l,int r)
{
    if(r-l<1)
    {
        return 0;
    }
    int m = (l+r)>>1;
    int ret =0;
    ret +=divideSort(a, l, m);
    ret +=divideSort(a, m+1, r);
    int len = r-l+1;
    int pos1=l,pos2=m+1;
   // int* temp = new int[len];
    
    for(int i=0; i<len; ++i)
    {
        if(pos1<=m && pos2<=r){
            if(a[pos1]>a[pos2]){
                ret +=  m - pos1+1;
                //printf("%d\n",m-pos1+1);
                temp[i] = a[pos2];
                pos2++;
            }
            else
            {
                temp[i] = a[pos1];
                pos1++;
            }
        }
        else if(pos2 <= r){// left is end
            temp[i] = a[pos2];
            pos2++;
        }
        else{
            temp[i] = a[pos1];
            pos1++;
        }
    }
    for(int i=0; i<len; ++i)
        a[l+i] = temp[i];
    //delete [] temp;
    return ret;
}

int minv,cnt;
const int len = 5001;
int b[len];
int a1[len];
int num[len][len];
int main()
{
    
    //9 2 4 5 1 7 7 7 7 3
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
        scanf("%d",a1+i);
    for(int i=0; i<n; ++i)
    {
        for(int j=n-1; j>=0; --j)
        {
            if(a1[i]>a1[j])
            {
                if(n-1 ==j)
                    num[i][j] = 1;
                else
                    num[i][j]= num[i][j+1]+1;
            }
            else
            {
                if(j<n-1)
                    num[i][j]= num[i][j+1];
            }
        }
    }
    int tmp;
    minv = cnt =0;
    minv = 5000*5000;
    memcpy(b, a1, 4*n);
    int sum =0;
    sum = divideSort(a1, 0, n-1);
    for(int i=0; i<n; ++i){
        tmp = 0;
        for(int j=i+1; j<n; ++j)
        {
            if(b[i]>b[j]){
               
                swap(b[i],b[j]);
                tmp = sum - 2*(num[i][i]-num[i][j])+2*(num[j][i]-num[j][j])-1;
                if(tmp<minv){
                    minv = tmp;
                    cnt = 1;
                }
                else if(tmp == minv)
                    cnt++;
                swap(b[i], b[j]);
            }

        }
       
    }
   
 printf("%d %d\n",minv,cnt);
    return 0;
}
