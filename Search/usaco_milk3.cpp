/*
ID: dalwzm1
PROG: milk3
LANG: C++
*/
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include <fstream>
#include<memory.h>
#include <set>
using namespace std;


ofstream fou("milk3.out");
ifstream fin("milk3.in");


const int len = 21;

int visit[len][len][len];
set<int> ans;
int limit[3];


int next_[3][2] ={{1,2},{0,2},{0,1}};


void dfs(int a[])
{
    if(!visit[a[0]][a[1]][a[2]])
    {
        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        visit[a[0]][a[1]][a[2]]= 1;
        if(0==a[0])
            ans.insert(a[2]);
        for(int i=0; i<3; ++i){
            if(a[i]){
                for(int j=0; j<2; ++j)
                {
                    int b[3];
                    int pos = next_[i][j];
                    if( a[pos]+a[i]<=limit[pos])
                    {
                        b[i] = 0;
                        b[pos] = a[pos]+a[i];
                        b[3-i-pos] = a[3-i-pos];
                    }
                    else
                    {
                        b[i] =a[i]-(limit[pos]-a[pos]);
                        b[pos] = limit[pos] ;
                        b[3-i-pos] = a[3-i-pos];
                    }
                    dfs(b);
                }
            }
        }
    }
}
int main()
{
    
    for(int i=0; i<3; ++i)
        fin>>limit[i];
    int a[3]={0,0,0};
    a[2] = limit[2];
    dfs(a);
    set<int>::iterator it= ans.begin();
    int cnt =0;
    for(   ; it!=ans.end(); ++it)
        //cout<<*it<<" ";
        if(cnt)
            fou<<" "<<*it;
        else{
            fou<<*it;
            cnt++;
        }
    fou<<endl;
    return 0;
}




