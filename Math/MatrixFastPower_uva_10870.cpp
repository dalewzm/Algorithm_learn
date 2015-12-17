//n+m+d
//uva 10870
#include<cstdio>
#include<vector>

using std::vector;
vector<vector<int> >A;
int D[16];
int C[16];
int n,m,d;

vector<vector<int> > mul(vector<vector<int> >a, vector<vector<int> >b)
{
	vector<vector<int> > ans( a.size(), vector<int>(b[0].size()));

	for(size_t i= 0; i < a.size(); i++ )
	{
		for(size_t j = 0; j < b[0].size(); ++j)
		{
			ans[i][j] = 0;
			for(size_t k=0; k < a[0].size(); k++)
			{
				ans[i][j] += (a[i][k] * b[k][j])%m;
				ans[i][j] %= m;
			}
		
		}
	}
	return ans;
}

vector<vector<int> > fastPower(vector<vector<int> >a, int n1)
{
	vector< vector<int> >ans(a.size(), vector<int>(a[0].size(),0));
	for(int i = 0; i < d ; i++)
		ans[i][i] = 1;
	
	while(n1)
	{
		if(n1 & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		n1>>=1;
	}
	return ans;
}

int main()
{
	int cnt =0;
	while(~scanf("%d %d %d", &d, &n, &m) && n+m+d){
		
		for(int i =0; i < d; ++i)
			scanf("%d",D+i); //coffiec
		for(int i =0; i < d; ++i)
			scanf("%d",C+i); //f[i]
		A.resize(d);
		for(int i = 0; i < d; i++){
			A[i].resize(d);
			A[0][i] = D[i] % m;
			C[i] = C[i]%m;
		}
		for(int i = 1; i < d ; i++)
		{
			A[i][i-1] = 1;
		}
		if(n <= d)
		{
			printf("%d\n",C[n-1]);
		}
		else{
			vector<vector<int> >res = fastPower(A, n-d);
			size_t ans = 0;
			for(int i =0; i < d; ++i){
				ans += (res[0][i] * C[d-i-1] % m);
				ans %= m;
			}
			printf("%d\n",ans);
		}
	
	}
}
