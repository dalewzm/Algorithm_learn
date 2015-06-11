#include<iostream>
#include<vector>
#include<cstdio>
#include<memory.h>
#include<algorithm>
using namespace std;

vector< vector<int> > g;
int n;
const int len = 6001;
int dp[len][2];
int happy[len];

void dfs(int i,int src)
{
    //is leaf
    if(g[i].size() == 1 && g[i][0]== src)
    {
        dp[i][0] = 0;
        dp[i][1] = happy[i];
        return;
    }
    int child;
    dp[i][1] = happy[i];
    for(size_t k=0; k<g[i].size(); ++k)
    {
        if(g[i][k]==src)
            continue;
        child = g[i][k];
        dfs( child,i );
        dp[i][0] += max(dp[child][1],dp[child][0]);
        dp[i][1] += dp[child][0];
    }
    
}
int main()
{
    scanf("%d",&n);
    
    g.resize(n);
    for(int i=0; i<n; ++i)
        scanf("%d",&happy[i]);
    if(n==1)
    {
        cout<<happy[0]<<endl;
        return 0;
    }
    int k,l;
    for(int i=0; i<n-1; ++i){
        scanf("%d %d",&l,&k);
        l--,k--;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    scanf("%d %d",&l,&k);
    dfs(0,0);
    cout<<max(dp[0][0],dp[0][1])<<endl;
}

