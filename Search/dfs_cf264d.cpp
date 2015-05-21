//先是吧问题转换为DAG最长路 每个串种数字i的位置在数字j的前面的话，就存在i到j的一条有向边
//然后以入度dfs求解最长路
#include<cstdio>
#include<vector>
#include <queue>
#include <memory.h>
using std::vector;
#define maxn 1001
#define  DEBUG
int n,q,gmax;

int seq[6][1001];

int visited[1001];
vector<int> v[maxn];
int dp[maxn];


bool check(int a,int b)
{
	for(int i = 0; i < q; ++i)
		if(seq[i][a] > seq[i][b])
			return 0;
	return 1;
}

void dfs(int x)
{
	if(visited[x])
		return;
	int max = 0;
	for(int i = 0; i < v[x].size(); ++i)
	{
		if(!visited[v[x][i]])
			dfs(v[x][i]);
		
		if(dp[v[x][i]] +1 > max )
			max = dp[v[x][i]] + 1;
	}
	dp[x] = max;
	if(max > gmax)
		gmax = max;
	visited[x] = 1;
}
int main()
{
	

	FILE *fp = fopen("in.txt","r");
	fscanf(fp,"%d %d",&n, &q);
	int val;
	for(int i = 0; i  < q; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			fscanf(fp,"%d",&val);
			seq[i][val-1] = j;
			//printf("%d ",val-1);
		}
		//printf("\n");
	}


	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i!=j && check(i,j))
			{
				v[j].push_back(i);
				
			}
		}
		
	}
	/*for(int i =0; i < n; i++)
	{
		for(int j =0; j< v[i].size(); j++)
			printf("%d ",v[i][j]);
		printf("\n");
	}*/
	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	memset(dp,0, sizeof(dp));
	for(int i = 0; i < n; ++i)
	{
		if(!visited[i])
			dfs(i);
		
	}
	

	

	printf("%d\n",gmax+1);

	
}