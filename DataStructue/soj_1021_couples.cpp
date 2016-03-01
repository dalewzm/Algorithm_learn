//#define debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stack>
#define REP(i,n) for(int i=0; i<(n); ++i)

using namespace std;
int n;
//#include <unordered_map>

typedef struct couple{
    int fst;
    int sed;
}couple;


//vector<Player> players;
void init()
{
    
 
}
const int maxn = 200002;
int relation[maxn];

void solve()
{
    int f,s;
    stack<int> cpStack;
    stack<int> tpStack;
    couple cur;
    REP(i, n){
        scanf("%d %d",&f, &s);
        relation[f-1] = s-1;
        relation[s-1] = f-1;
    }
    for(int i=0; i<n*2; ++i)
        cpStack.push(i);
    do{
        int top = cpStack.top();
        cpStack.pop();
        tpStack.push(top);
        
        while(!cpStack.empty() && !tpStack.empty() && relation[tpStack.top()] == cpStack.top())
        {
            cpStack.pop();
            tpStack.pop();
        }
        
    }while(!cpStack.empty());
    
    if(tpStack.empty())
        printf("Yes\n");
    else
        printf("No\n");
    
}


int main()
{
#ifdef debug
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
#endif
    while(scanf("%d",&n) && n){
        //init();
        solve();
    }

    
#ifdef debug
    fclose(stdin);
    //fclose(stdout);
#endif
    
    return 0;
}





