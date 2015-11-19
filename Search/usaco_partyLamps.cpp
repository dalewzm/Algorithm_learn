/*
 ID: dalewzm1
 PROG: lamps
 LANG: C++
 */


#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<memory.h>
#include<stack>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

ofstream fou("lamps.out");
ifstream fin("lamps.in");

const int len = 101;
int n,c;
int on[len],off[len];
int onCnt,offCnt;
int sum =0;

string ans[16];

//#define fin cin
//#define fou cout

void init()
{
    fin>>n;
    fin>>c;
    int data;
    while(1){
        fin>>data;
        if(data== -1)
            break;
        on[onCnt++] = data;
    }
    while(1){
        fin>>data;
        if(data== -1)
            break;
        off[offCnt++] = data;
    }
    for(int i=0; i<16; ++i)
        ans[i].resize(n);
}

bool isSatisfied( int i, int j, int m, int n)
{
    //1. 3k+1 && odd
    //2. 3k+1 && even
    //3. not 3k+1 && odd
    //4. not 3k+1 && even
    int curr;
    int first  = (i + j + n)%2;
    int second = (i + m +n)%2;
    int third  = (i + j) % 2;
    int forth  = (i + m) % 2;
    for(int k=0; k<onCnt; ++k)
    {
        curr = on[k];
        if( curr & 1)
        {
            if(curr % 3 == 1)
            {
                if(first)
                    return false;
            }
            else{
                if(third)
                    return false;
                
            }
        }
        else{
            if(curr % 3 == 1){
                if(second){
                    return false;
                }
            }
            else{
                if(forth)
                    return false;
            }
            
        }
    }
    for(int k=0; k<6; ++k)
    {
        curr = off[k];
        if( curr & 1)
        {
            if(curr % 3 == 1)
            {
                if(!first)
                    return false;
            }
            else{
                if(!third)
                    return false;
                
            }
        }
        else{
            if(curr % 3 == 1){
                if(!second){
                    return false;
                }
            }
            else{
                if(!forth)
                    return false;
            }
            
        }
    }

    return true;
}


void output(int i,int j, int m, int nu)
{
    int first  = (i + j + nu)  % 2;
    int second = (i + m + nu)  % 2;
    int third  = (i + j)  %2;
    int forth  = (i + m)   %2;
    for(int k=1; k<=n; ++k)
    {
        if(k & 1){
            if(k % 3 == 1)
            {
                if(first)
                    ans[sum][k-1]='0';
                else
                    ans[sum][k-1]='1';
            }
            else{
                if(third)
                    ans[sum][k-1]='0';
                else
                    ans[sum][k-1]='1';
                
            }
        }
        else{
            if(k % 3 == 1)
            {
                if(second)
                    ans[sum][k-1]='0';
                else
                     ans[sum][k-1]='1';
            }
            else{
                if(forth)
                    ans[sum][k-1]='0';
                else
                    ans[sum][k-1]='1';
                
            }

            
        }
    }
    
}

void sortAns()
{
    sort(ans,ans+sum);
    if(sum == 0){
        fou<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=0; i<sum; ++i){
        ans[i][n]  = 0;
        fou<<ans[i]<<endl;
    }
}


void solve()
{
    int cnt = c/2 ? c/2:1;
    
    for(int i=0; i<=1; ++i)
    {
        for(int j=0; j<=c-i && j<=1; ++j)
        {
            for(int k=0; k<=1 && k<=c-i-j; ++k){
                int m=c-i-j-k;
                if(isSatisfied(i, j, k, m)){
                    output(i,j,k,m);
                    // fou<<i<<" "<<j<<" "<<k<<" "<<m<<endl;
                    sum++;
                }
            }
        }
    }
   
        
}



int main()
{
    init();
    solve();
    sortAns();
    return 0;
}
