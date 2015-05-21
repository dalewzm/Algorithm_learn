//快速幂
//注意求的过程要用longlong ，以为 0< n< 65000,n^2可能超过int

#include <cstdio> 
typedef long long ll;
int prime[65001];
int  fastpower(ll base, int n, int mod)
{
	ll res = 1;
	while(n){
		if( n & 1)
			res = res * base % mod;
		base = base * base % mod;
		n>>=1;
	}
	return res;
}

bool check(int n)
{
	for(int i = 2; i < n; ++i)
		if( i != fastpower(i, n, n) )
			return false;
	return true;
}
int main()
{
	int n;
	for(int i = 0; i <65001; ++i)
		prime[i] = 1;
	for(int i = 2; i < 65001; ++i)
	{
		if(prime[i]){
			for(int j = i+i; j < 65001; j+=i)
				prime[j] = 0;
		}
	}

	while(~scanf("%d",&n)&&n!=0)
	{
		if(!prime[n] && check(n))
			printf("The number %d is a Carmichael number.\n",n);
		else
			printf("%d is normal.\n",n);
	}
}
