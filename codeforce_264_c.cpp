//学习：1.同一对角线上横纵坐标和相等
//      2.同一对角线上坐标和奇偶性相同，相交的对角线上有公共元素，奇偶性也一样
//      3.cin.sync_with_stdio 取消缓存
//
#include<iostream>
using namespace std;
#define maxn 2001
typedef long long ll;
ll a[maxn][maxn],d1[2*maxn],d2[maxn<<1],sol[2];

int n,x[2],y[2];
int main()
{
	sol[1] = sol[0] = -1;
	cin.sync_with_stdio(false);
	cin>>n;
	int b;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j< n; ++j)
		{
			cin>>a[i][j];
			d1[i+j] += a[i][j];
			d2[i -j +n] += a[i][j];
		}
	}

	int pos;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			pos = (i+j) & 1;
			if(sol[pos] < d1[i+j] + d2[i-j+n]-a[i][j])
			{
				sol[pos] = d1[i+j] + d2[i-j+n]-a[i][j];
				x[pos] = i;
				y[pos] = j;
			}
		}
	}
	cout<<sol[0]+sol[1]<<endl;
	cout<<x[0]+1<<" "<<y[0]+1<<" "<<x[1]+1<<" "<<y[1]+1<<endl;
}
