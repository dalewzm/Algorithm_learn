/*
 ID: dalewzm1
 PROG: subset
 LANG: C++
 */


#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<memory.h>
#include <cmath>
#include <cassert>
using namespace std;

ofstream fou("subset.out");
ifstream fin("subset.in");

int n;

int dp[40][400];

//#define fou cout
//#define fin cin


int sum;
int target;
int res;
int cnt;
void dfs(int i, int num)
{
    if(-1 == dp[i][num])
    {
        
        if(-1 == dp[i-1][num])
            dfs(i-1,num);
        
        
        if(num-i>=0){
            if(-1 == dp[i-1][num-i])
                dfs(i-1,num-i);
            dp[i][num] = dp[i-1][num-i] + dp[i-1][num];
        }
        else
        {
            dp[i][num] = dp[i-1][num];
        }
        
        
        return;
    }
    
}

void nores()
{
    for(int i=1; i<40; ++i)
    {
        for(int j=1; j<=target; ++j)
        {
            if(j>=i)
                dp[i][j] = dp[i-1][j-i] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
        
    }
        
}

void init()
{
    fin>>n;
    memset(dp,-1, sizeof(dp));
    if( n*(n+1) % 4 != 0)
    {
        fou<<0<<endl;
        exit(0);
    }
    target = n*(n+1)/4;
    for(int i=0; i<40; i++)
        dp[i][0] = 1;
    for(int i=0; i<400; ++i)
        dp[0][i] = 0;
}

void solve()
{
    nores();
    //dfs(n, target);
    fou<<dp[n][target]<<endl;
    
}

int main()
{
    init();
    solve();

    return 0;
}



