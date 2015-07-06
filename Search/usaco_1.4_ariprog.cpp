/*
ID: dalwzm1
PROG: ariprog
LANG: C++
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include <fstream>
#include<memory.h>
#include<ctime>
using namespace std;

const int len = 2*251*251;
int visit[len];
int can[len];
int num[len];
int d[len];
long long int cal;
int sz;
int cnt,a,b,n,m,dcnt;


bool dfs(int start,int diff)
{
    int len =0;
    while(len<n){
        if(!can[ num[start]+len*diff])
            break;
        len++;
    }
    if(len==n)
        return true;
    return false;
}


ifstream fin("ariprog.in");
ofstream fou("ariprog.out");
int main()
{


    int pcnt =0;
    fin>>n>>m;
    for(int i=0; i<=m; ++i)
        for(int j=i; j<=m; ++j){
            can[i*i+j*j]=1;
        }
   
    
   
    for(int i=0; i<len; ++i)
    {
        if(can[i])
            num[cnt++] = i;
    }
    for(int i=0; i<cnt-1; ++i)
    {
        for(int j=i+1; j<cnt; ++j)
            visit[num[j]-num[i]]=1;
    }
    for(int i=1; i<len; ++i)
    {
        if(visit[i])
            d[dcnt++] = i;
    }
    for(int j=0; j<dcnt; ++j){
        for(int i=0; i<cnt; ++i)
        {
            a = num[i];
            b = d[j];
            if(a+(n-1)*b>num[cnt-1])
                break;
            if(dfs(i,b)){
                pcnt++;
                fou<<a<<" "<<b<<"\n";
            }
            
        }
    }
  
    if(pcnt == 0)
        fou<<"NONE\n";
    
}
