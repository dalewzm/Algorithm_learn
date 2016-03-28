//主要在于对每次可取的集合进行排序，然后根据必胜态与必败态的相互转移
//#define debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <queue>
//#include <unordered_map>
#define REP(i,n) for(int i=0; i<(n); ++i)

using namespace std;
int n,m;
int sets[10];
const int maxn = 1000001;

int f[maxn];

void pre()
{
    f[0] = 0;
    f[1] = 1;
}




void solve()
{
    for(int i=2; i<=n; ++i){
        f[i] =1;
        for(int j=0; j<m; ++j)
            if(i-sets[j]>=0)
            f[i] = f[i] & f[i-sets[j]];
        f[i] = 1 - f[i];
    }
}


int main()
{
#ifdef debug
    freopen("input.in","r",stdin);
#endif
    while(cin>>n){
        cin>>m;
        for(int i=0; i<m; ++i)
            cin>>sets[i];
        sort(sets,sets+m);
        pre();
        solve();
        if(f[n])
            cout<<"Stan wins"<<endl;
        else
            cout<<"Ollie wins"<<endl;
    }
    
#ifdef debug
    fclose(stdin);
#endif
    
    return 0;
}






