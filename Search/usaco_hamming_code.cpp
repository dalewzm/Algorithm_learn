/*
ID: dalewzm1
PROG: hamming
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

ofstream fou("hamming.out");
ifstream fin("hamming.in");

const int maxn = 65;
int n,b,d;
int upp;


unsigned char codewords[maxn];
char ansWords[maxn];
int mask[8];

//#define fou cout
//#define fin cin

int getDistance(int a, int b)
{
    int ret =0;
    for(int i=0; i<b; ++i)
    {
       if((a & mask[i]) ^ (b & mask[i]))
           ++ret;
    }
    return ret;
}

//num 是当前几个word
bool isValid(int num, int curr)
{
    for(int i=0; i<num; ++i)
    {
        if(getDistance( codewords[i], curr) < d)
            return false;
    }
    return true;
}

bool dfs(int num,int visit)
{
    if(num == n)
    {
         return true;
    }
    for(int i=visit; i<upp; ++i)
    {
        if(isValid(num, i))
        {
            codewords[num] = i;
            if(dfs(num+1,i+1))
                return true;
        }
    }
    return false;
    
}

void init()
{
    fin>>n>>b>>d;
    upp = 1<<(b);
    for(int i=0; i<8; ++i)
    {
        mask[i] = 1<<i;
    }
}

void solve()
{
    dfs(0,0);
    int cnt =0;
    for(int i=0; i<n; ++i)
    {
        if(cnt)
            fou<<" "<<(int)codewords[i];
        else{
            fou<<(int)codewords[i];
            cnt++;
        }
        if((i+1) % 10 == 0){
            fou<<endl;
            cnt = 0;
        }
    }
    if(n%10!=0)
        fou<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}

