
//similar to the model DAG longest path, add a array store evey node's beauty
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
//#include <unordered_map>
//#include <iomanip>

using namespace std;

const int maxn = 100001;
//int visit[maxn];
long long int dpl[maxn];//dp max length
long long int dpb[maxn];//dp max beauty
vector< vector<int> >edges;
int n,m;
void init()
{
    cin>>n>>m;
    edges.resize(n, vector<int>());
    int u,v;
    for(int i=0; i<m; ++i)
    {
        cin>>u>>v;
        
        edges[u-1].push_back(v-1);
        
        edges[v-1].push_back(u-1);
        
    }
}

long long int maxb;
void dfs(int u)
{
    if(dpl[u]!=0)
        return;
    int idx = 0;
    dpl[u] = 1;
    for(int i=0; i<edges[u].size(); ++i)
    {
        if(edges[u][i]<u){
            idx = edges[u][i];
            if(dpl[idx]==0)
                dfs(idx);
            if(dpl[idx]+1>dpl[u])
                dpl[u] = dpl[idx]+1;
        }
    }
    dpb[u] = dpl[u]*edges[u].size();
}

void solve()
{
    for(int i=0; i<n; ++i)
    {
        dfs(i);
    }
    for(int i=0; i<n; ++i)
        if(dpb[i]>maxb)
            maxb = dpb[i];
    cout<<maxb<<endl;
}


int main()
{
    
    init();
    solve();
    return 0;
    
}
