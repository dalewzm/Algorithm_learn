
//dfs get articulation vertex
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <memory.h>
using namespace std;

const int maxn = 110;

int pre[maxn];
int visit[maxn];
int is_cut[maxn];
int dfs_clock;

vector<vector<int> > edges;
int n;

bool init()
{
    bool ret = false;
    string line;
    cin>>n;
    getline(cin,line);
    edges.resize(n);
    int u,v;
    while(n){
        ret = true;
        getline(cin,line);
        istringstream iss(line);
        //iss<<line;
        iss>>u;
        if(u==0)
            return ret;
        while(iss>>v){
            edges[u-1].push_back(v-1);
            edges[v-1].push_back(u-1);
        }
    }
    return ret;
}


int dfs(int u,int fa)
{
    //root node, fd = -1
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i=0; i<edges[u].size(); ++i){
        int v = edges[u][i];
        int lowv = 0;
        if(!pre[v]){//tree edge
            child++;
            lowv = dfs(v, u);
            lowu = min(lowu,lowv);
            if(lowv >= pre[u])
                is_cut[u] = 1;
        }
        else{ //back edge
            if(pre[v] < pre[u] && v!=fa){ //not parent node
                lowu = min(lowu,pre[v]);
            }
        }
    }
    if(child == 1 && fa < 0)
    {
        is_cut[u] = 0;
    }
    return lowu;
}


void solve()
{
    int sum = 0;
    while(init()){
        dfs_clock  =0 ;
        for(int i=0; i<n; ++i)
            if(!pre[i]){
                //dfs_clock = 0;
                dfs(i,-1);
            }
        for(int i=0; i<n; ++i)
            if(is_cut[i])
                sum++;
        cout<<sum<<endl;
        
        edges.clear();
        memset(is_cut,0,sizeof(is_cut));
        memset(pre, 0, sizeof(pre));
        sum = 0;
    }
}

int main()
{
    solve();
    return 0;
}
