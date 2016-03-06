// Problem#: 1151
// Submission#: 4529156
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
//#define debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
//#include <stack>
//#include <unordered_map>
#define REP(i,n) for(int i=0; i<(n); ++i)

using namespace std;

const int maxn = 41000;
//const int mod = maxn -1;
int base[8];
int first,last,n;
typedef struct Node{
    char ope;
    int state;
    int far;
    Node()
    {
        ope =   0;
        state = far = 0;
    }
    
}Node;

int getState(int,int);
int BKDRhash(int state)
{
    int j,t=0;
    unsigned num = 0,s[8];
    for(int i=0; i<8; ++i)
        s[i] = getState(state, i);
    for(int i = 7; i>=0; --i){
        t= 0;
        for(j=i-1; j>=0; --j)
            if(s[j]<s[i])++t;
        num+=base[i]*t;
    }
    return num;
    
}

void printState(int);

Node opeA(const Node &rhs)
{
    Node tmp;
    tmp.far = first;
    tmp.ope = 'A';
    tmp.state = (rhs.state << 16) | (rhs.state >> 16);
    return tmp;
}

int getState(int s,int i)
{
    return  ( s>>(4*i)) & 15;
}

void setState(int &s,int i,int v)
{
    //set 0
    int range = 0xf << (4*i);
    s &= (~range);
    //set v
    s |= (v << 4*i);
    
}

Node opeB(const Node &rhs)
{
    Node tmp;
    tmp.far = first;
    tmp.ope = 'B';
    
    int ur = getState(rhs.state, 3);
    int dr = getState(rhs.state, 7);
    int upper = rhs.state & 0x0000ffff;
    int down = rhs.state >> 16;
    upper <<= 4;
    upper &= ~(0x000f0000);
    down <<= 4;
    down &= ~(0x000f0000);
    upper |= ur;
    down  |= dr;
    //printState(upper);
    tmp.state = upper | (down<<16);
    return tmp;
}


Node opeC(const Node &rhs)
{
    Node tmp;
    tmp.far = first;
    tmp.ope = 'C';
    tmp.state = rhs.state;
    //tmp.step = rhs.step +1;
    //int t = getState(rhs.state, 1);
    setState(tmp.state, 1, getState(rhs.state, 5));
    setState(tmp.state, 5, getState(rhs.state, 6));
    setState(tmp.state, 6, getState(rhs.state, 2));
    setState(tmp.state, 2, getState(rhs.state, 1));
    return tmp;
}

Node nqueue[maxn];
//int stack[maxn];
int visit[maxn];
char sop[maxn];

Node start,Res;
//int steps,cnt;



void printState(int s)
{
   
    for(int i=0; i<8; ++i){
        cout<<(s & 15)<<" ";
        s>>=4;
    }
    cout<<endl;
    
}

void init()
{
    int s;
    Res.state = 0;
    first = last = 0;
    //cnt =0 ;
    memset(visit,0,sizeof(visit));
    //hashTab.clear();
    for(int i=0; i<8; ++i){
        cin>>s;
        Res.state |= (s<<(4*i));
    }
    //printState(Res.state);
}

void printTop()
{
    int i,j;
    j=0;
    i=nqueue[first].far;
    //  cout<<"i: "<<i<<" "<<j<<endl;
    sop[j]=nqueue[first].ope;
    //   cout<<i<<" "<<sop[j]<<endl;
    while(i!=0)
    {
        j=j+1;
        sop[j]=nqueue[i].ope;
        i=nqueue[i].far;
        //      cout<<i<<endl;
    }
    
    if(j+1>n)
        cout<<-1<<endl;
    else{
        cout<<j+1<<" ";
        for( i=j; i>=0; i--)
            cout<<sop[i];
        cout<<endl;
    }
}

/*
void printSolution(Node &cur,int idx)
{
    int c=0;
   
    stack[c++] = idx;
    int len = cur.step;
    while(cur.far > 0)
    {
        stack[c++] = cur.far;
        cur = nqueue[cur.far];
    }
    //assert(c == len);
    if(len>n)
    {
        printf("-1\n");
        return;
    }
    printf("%d ",len);
    for(int i=c-1; i>=0; --i)
    {
        printf("%c",nqueue[stack[i]].ope);
    }
    printf("\n");
}
 */

void pushEle(Node &nod)
{
    int pos = BKDRhash(nod.state);
    if(visit[pos]){
        //if(nqueue[visit[pos]].state == nod.state)
        return ;
        //pos+=2;
    }
    nqueue[++last] = nod;
    visit[pos] = last;
    
}

void solve()
{
    
    nqueue[0] = start;
    visit[BKDRhash(start.state)] =1;
    //last++;
    Node cur,tmp;
    if(start.state == Res.state)
    {
        if(n>=0)
            cout<<0<<endl;
        else
            cout<<-1<<endl;
        return ;
    }
    while(first<=last ){
        cur = nqueue[first];
        if(cur.state == Res.state){//find ans;
            printTop();
            break;
        }
        tmp = opeA(cur);
        pushEle(tmp);
        tmp = opeB(cur);
        pushEle(tmp);
        tmp = opeC(cur);
        pushEle(tmp);
        first++;
    }
    
}




int main()
{
#ifdef debug
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
#endif
    //int n;
    start.state = 0x56784321;
    start.far = -1;
    //printState(start.state);
    //Node nod;
    //nod = opeB(start, 0);
   
    base[0] =1;
    for(int i=1; i<8; ++i)
        base[i] =base[i-1]*(i);
    base[0] = 0;
    
    while(scanf("%d",&n) && n!=-1){
        init();
        
        solve();
    }
    
    
#ifdef debug
    fclose(stdin);
    //fclose(stdout);
#endif
    
    return 0;
}                                 
