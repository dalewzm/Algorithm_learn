/*
ID: dalewzm1
PROG: holstein
LANG: C++
*/

/*/-------------
when try comnation, no need use visit arrary to avoid visiting again
-------------/*/
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<memory.h>
#include <cmath>
#include <cassert>
using namespace std;

ofstream fou("holstein.out");
ifstream fin("holstein.in");

const int maxn = 26;
int n;
int cnt;
int reqn;
int req[maxn];

int supn;
int sup[maxn][maxn];
int visit[maxn];
int sum[maxn];
int ansStack[maxn];
int tmpStack[maxn];
int minn;


//#define fou cout
//#define fin cin


void init()
{
    
    fin>>reqn;
    for(int i=0; i<reqn; ++i)
        fin>>req[i];
    fin>>supn;
    for(int i=0; i<supn; i++)
        for(int j=0; j<reqn; ++j)
            fin>>sup[i][j];
    
    minn= 1001;
}

inline void swap(int& a,int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}


void Vadd(int k)
{
    for(int i=0; i<reqn; ++i)
        sum[i]+= sup[k][i];
}

void Vminues(int k)
{
    
    for(int i=0; i<reqn; ++i)
        sum[i]-= sup[k][i];
}

bool isAns(int k)
{
    for(int i=0; i<reqn; ++i)
    {
        if(sum[i]<req[i])
            return false;
    }
    return true;
}

void dfs(int k,int num)
{
    Vadd(k);
    tmpStack[num] = k;
    num++;
    if(isAns(k))
    {
        if(num < minn)
        {
            minn = num;
            for(int j=0; j<minn; ++j)
                ansStack[j] = tmpStack[j];
        }
        Vminues(k);
        return;
    }
    for(int i=k+1; i<supn; ++i)
    {
        if(!visit[i])
        {
            visit[i] = 1;
            dfs(i,num);
            visit[i] = 0;
        }
    }
    Vminues(k);
}

void solve()
{
    for(int i=0; i<supn; ++i)
        dfs(i,0);
    fou<<minn<<" ";
    for(int i=0; i<minn; ++i)
        if(i<minn-1)
        fou<<ansStack[i]+1<<" ";
        else
        fou<<ansStack[i]+1;
    fou<<endl;
    
}

int main()
{
    
    init();
    solve();
    
    return 0;
}

