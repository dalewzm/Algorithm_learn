//
//  test.cpp
//  cpp
//
//  Created by dalewang on 14-4-26.
//
//


#include <iostream>
#include<cstdlib>
#include<memory.h>
using namespace std;

#define N 51
#define M 51
#define MAX 100
#define mod 10000
typedef struct bs{
    int len;
    int digit[MAX];
    bs(){len=0,memset(digit,0,sizeof(digit));}
    bs(int a){
        digit[0]=a%mod;
        a/=mod;
        if(0==a){
            len=0;
        }
        else{
            len=1;
            digit[1]=a;
        }
            
    }
    bs operator+=(const bs& rhs);
    bs& operator=(const bs& rhs);
}bs;

bs bs::operator+=(const bs& rhs)
{
    int i,carry;
    
    for( i=carry=0; i<=this->len|| i<=rhs.len || carry;++i){
        if(i<=this->len)
            carry+=this->digit[i];
        if(i<=rhs.len)
            carry+=rhs.digit[i];
        this->digit[i]=carry%mod;
        carry/=mod;
    }
    this->len = i-1;
    return *this;
}

bs& bs::operator=(const bs & rhs)
{
    len=rhs.len;
    for(int i=0; i<=rhs.len; ++i){
        digit[i]=rhs.digit[i];
    }
    return *this;
}

void output(bs ans)
{
    
    for(int i=ans.len; i>=0; --i){
        if(i==ans.len)
            cout<<ans.digit[i];
        else
            printf("%04d",ans.digit[i]);
    }
    cout<<endl;
}
bs map[N+2][M+2];
bool visit[N][M];
int n,m;
bs dfs(int x1,int y1,int x2,int y2)
{
    if(x1 <1 || x1>n || x1>x2 || y1<1 || y1>m)
        return 0;
    int ans1=0;
    if(x2-x1<2 ){
        if( 0== x2-x1 ){
            if(0==y2-y1)
                return bs(1);
            return bs(0);
        }
        
        if(y1== y2-2)
            ans1+=1;
        if(y1== y2+2)
            ans1+=1;
        return bs(ans1);
        
        
    }
    bs ans;
    if(y1>1){
        if(!visit[x1+2][y1-1]){
            map[x1+2][y1-1]=dfs(x1+2,y1-1,x2,y2);
            visit[x1+2][y1-1]=1;
        }
        
        ans+=map[x1+2][y1-1];
    }
    if(y1<m){
        if(!visit[x1+2][y1+1]){
            map[x1+2][y1+1]=dfs(x1+2,y1+1,x2,y2);
            visit[x1+2][y1+1]=1;
        }
        ans+=map[x1+2][y1+1];
    }
    if(y1<m-1){
        if(!visit[x1+1][y1+2]){
            map[x1+1][y1+2]=dfs(x1+1,y1+2,x2,y2);
            visit[x1+1][y1+2]=1;
        }
        ans+=map[x1+1][y1+2];
    }
    if(y1>2){
        if(!visit[x1+1][y1-2]){
            map[x1+1][y1-2]=dfs(x1+1,y1-2,x2,y2);
            visit[x1+1][y1-2]=1;
        }
        ans+=map[x1+1][y1-2];
    }
    
    return ans;
    
}
int main()
{
    int x1,y1,x2,y2;
    
    memset(map,0,sizeof(map));
    

    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
        cout<<0<<endl;
    //else
      output(dfs(x1,y1,x2,y2));
    /*map[x1][y1]=1;
    for(int i=x1+1; i<=x2; ++i){
        for(int j=1; j<=m; ++j){
            if(j>1)
                map[i][j]+=map[i-1][j-2];
            map[i][j]+=map[i-2][j-1];
            map[i][j]+=map[i-2][j+1];
            map[i][j]+=map[i-1][j+2];
        }
    }*/
   
    //output(map[x2][y2]);
    //cout<<map[x2][y2];
}
  

