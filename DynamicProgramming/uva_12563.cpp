//kaitlynchen@tencent.com
#define debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
//#include <stack>
//#include <unordered_map>
#define REP(i,n) for(int i=0; i<(n); ++i)

using namespace std;

typedef struct Node{
    int num;
    int time;
    Node ()
    {
        num = 0;
        time = 0;
    }
    bool operator < (const Node& rhs)
    {
        if(num!=rhs.num)
            return num < rhs.num;
        return time < rhs.time;
    }
}Node;

int t,n,T;
int cnt=0;
const int nm = 51;
const int timev = nm*180;
//int dp[nm][timev];
int music[nm];

Node dp[timev];

void solve()
{
    memset(dp, 0, sizeof(dp));
    //for(int i=0; i<timev; ++i)
    //    dp[0][i] = 0;
    //dp[0] = 0;
    //dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w)
    Node maxv;
    int len = 0;
    for(int i=1; i<=n; ++i){
        for(int j =t-1; j>=0; --j){
            if(j>=music[i]){
                Node tmp;
                tmp.num = dp[j-music[i]].num+1;
                tmp.time = dp[j-music[i]].time + music[i];
                if(dp[j]<tmp)
                    dp[j] = tmp;
            }
            if(maxv < dp[j])
                maxv = dp[j];
        }
    }
    
    
    
    printf("Case %d: %d %d\n",cnt,maxv.num+1,maxv.time+678);
}



int main()
{
#ifdef debug
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
#endif
    
    
    //ta.print();
    scanf("%d", &T);
    cnt = 0;
    while(T--){
        scanf("%d %d",&n,&t);
        for(int i=1; i<=n; ++i){
            scanf("%d",music+i);
        }
        cnt++;
        solve();
    }
#ifdef debug
    fclose(stdin);
    //fclose(stdout);
#endif
    
    return 0;
}






