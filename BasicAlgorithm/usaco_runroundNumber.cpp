/*
 ID: dalewzm1
 PROG: runround
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
using namespace std;

ofstream fou("runround.out");
ifstream fin("runround.in");

unsigned int n;
int len;
int digit[11];
int visit[11];

//#define fou cout
//#define fin cin

void getDigit(unsigned int num)
{
    len =0;
    stack<int> dig;
    while(num){
        dig.push(num%10);
        //digit[len++] = num%10;
        num/=10;
    }
    while(!dig.empty())
    {
        digit[len++] = dig.top();
        dig.pop();
    }
}

bool isRun(unsigned int num)
{
    int pos = 0;
    for(int i=0; i<len; ++i)
    {
        if(visit[digit[pos]])
            return false;
        visit[digit[pos]] = 1;
        pos = (digit[pos]+pos)%len;
        
        //fou<<digit[pos]<<" ";
    }
    if(pos == 0)
        return true;
    return false;
}

void init()
{
    fin>>n;
    unsigned int i = n;
    for(i++; ;i++){
        getDigit(i);
        memset(visit,0,sizeof(visit));
        if(isRun(i))
            break;
    }
    fou<<i<<endl;
}

void solve()
{
  
}

int main()
{
    
    
    init();
    solve();
    
    return 0;
}
