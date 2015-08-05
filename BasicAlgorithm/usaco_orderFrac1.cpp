/*
ID: dalewzm1
PROG: frac1
LANG: C++
*/


#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<memory.h>
#include <cmath>

using namespace std;


ofstream fou("frac1.out");
ifstream fin("frac1.in");



const int maxn = 40000;
int n;
int cnt;
//#define fou cout
//#define fin cin


typedef struct frac
{
    int up;
    int down;
    frac(){up=0,down = 0;}
    frac(int a,int b){up=a,down =b;}
    bool operator < (const frac& rhs) const
    {
        return up*1.0/down < (rhs.up*1.0/rhs.down);
    }
}frac;


int gcd(int m, int n)
{
    if( 0 == n)
        return m;
    return gcd(n, m%n);
}


frac Ans[maxn];


void init()
{
    Ans[0]=frac(0,1);
    cnt = 1;
}

void solve()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<i; ++j)
        {
            //fou<<j<<" "<<i<<" gcd is:"<<gcd(i,j)<<endl;
            if(gcd(i,j)==1)
            {
                Ans[cnt++] = frac(j,i);
            }
        }
    }
    Ans[cnt++] = frac(1,1);
    sort(Ans,Ans+cnt);
    for(int i=0; i<cnt; ++i)
        fou<<Ans[i].up<<"/"<<Ans[i].down<<endl;
}

int main()
{
    fin>>n;
    init();
    solve();
    return 0;
}






