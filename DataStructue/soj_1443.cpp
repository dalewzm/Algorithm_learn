// Problem#: 1443
// Submission#: 4525696
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
//use stack+array to simulate priority queue
//#define LOCAL
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); ++i)

int n,m;

typedef struct ele{
    int pri;
    int tar;
    ele(){pri=tar = 0;}
    ele(int p,int t):pri(p),tar(t){}
}ele;

const int maxn = 100;
queue<ele> priQ;
int maxQ[maxn];
int cnt;
void input()
{
    cin>>n>>m;
    REP(i,n) {
        cin>>maxQ[i];
        if(i!=m)
            priQ.push(ele(maxQ[i],0));
        else
            priQ.push(ele(maxQ[i],1));
    }
}

void pre()
{
    while(!priQ.empty())
        priQ.pop();
    cnt = 0;
}

bool cmp(const int &l, const int& r)
{
    return l>r;
}

bool check(int pri)
{
    if(pri<maxQ[cnt])
        return false;
    return true;
}


void solve()
{
    ele topE;
    bool find = false;
    int res =0;
    sort(maxQ,maxQ+n,cmp);
    while(!find){
        topE = priQ.front();
        if(check(topE.pri))//can print
        {
           if(topE.tar)
               find = true;
           else{ //update maxQ
                res++;
                cnt++;
           }
        }
        else{
            priQ.push(topE);
        }
        priQ.pop();
    }
    cout<<res+1<<endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.in", "r", stdin);
   // freopen("output.out", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        pre();
        input();
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}                                 
