/*
ID: dalewzm1
PROG: sort3
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

ofstream fou("sort3.out");
ifstream fin("sort3.in");

const int maxn = 1001;
int n;
int cnt;
int a[maxn];
int sum[4];
int pos[5];

void init()
{
    
    for(int i=0; i<n; ++i)
    {
        fin>>a[i];
        sum[a[i]]++;
    }
    pos[1] = 0;
    pos[2] += sum[1];
    pos[3] += sum[2] + sum[1];
    pos[4] = n;
}

inline bool inRightPos(int i)
{
    if(i <= pos[a[i]+1]-1 && i >= pos[a[i]])
        return true;
    return  false;
}

inline void swap(int& a,int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}

void solve()
{
    int ct = 0;
    for(int i=0; i<n; ++i)
    {
        if(!inRightPos(i)){
            for(int j=pos[a[i]]; j<=pos[a[i]+1]-1; ++j)
            {
                if(pos[a[j]]<=i && i<= pos[a[j]+1]-1)
                {
                    swap(a[i],a[j]);
                    cnt++;
                }
            }
        }
    }
    
    for(int i=0; i<n; ++i)
    {
        if(!inRightPos(i))
            ct++;
    }
    fou<<ct/3*2 + cnt<<endl;
    
}

int main()
{
    fin>>n;
    init();
    solve();
    return 0;
}






