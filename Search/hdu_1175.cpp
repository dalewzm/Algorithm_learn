#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <stack>
#include <bitset>
#include <queue>
//#include <unordered_map>
#define REP(i,n) for(int i=0; i<(n); ++i)

using namespace std;


typedef struct Pos{
    Pos(){x=0,y=0,num=0;}
    Pos(int a,int b,int nu){x=a,y=b,num=nu;}
    int x;
    int y;
    int num;
}Pos;


int n,m,q;
int maxlen;
const int maxn = 2005;
int board[maxn][maxn];
int visit[maxn][maxn];
int dirx[4] ={0, 1, 0, -1};
int diry[4] ={1, 0, -1, 0};

bool isValid(int x,int y)
{
    if(1<=x && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

bool solve(Pos& start, Pos &end)
{
    if(board[start.x][start.y] != board[end.x][end.y])//消去棋子得相同
        return false;
    if(start.x == end.x && start.y == end.y)//不能是同一个位置
        return false;
    if(board[start.x][start.y] == 0)//不能同时是空
        return false;
    int orig = board[end.x][end.y];
    board[end.x][end.y] = 0;
    queue<Pos> judgeQueue;
    judgeQueue.push(start);
    visit[start.x][start.y] = 1;
    while(!judgeQueue.empty()){
        Pos tmp = judgeQueue.front();
        judgeQueue.pop();
        if(tmp.x == end.x && tmp.y == end.y){
            board[end.x][end.y] = orig;
            return true;
        }
        
        for(int i=0; i<4; ++i)
        {
            for(int j=1; j<maxlen; ++j){
                Pos np(tmp.x + j*dirx[i], tmp.y+j*diry[i],tmp.num+1);
                if(isValid(np.x,np.y)&& !visit[np.x][np.y] && np.num < 3)
                {
                    if( board[np.x][np.y])
                        break;
                    visit[np.x][np.y] = 1;
                    judgeQueue.push(np);
                }
            }
        }
    }
    board[end.x][end.y] = orig;
    return false;
}


int main()
{
#ifdef debug
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
#endif
    int x1,y1,x2,y2;
    while(scanf("%d %d",&n,&m) && (n!=0 || m!=0)){
        maxlen = max(n,m);
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j)
                scanf("%d",&board[i][j]);
        }
        scanf("%d",&q);
        REP(i,q){
            scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
            Pos st(x1,y1,-1),ed(x2,y2,0);
            if(solve(st, ed)){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            memset(visit,0, sizeof(visit));

        }
        
    }
    
    
#ifdef debug
    fclose(stdin);
    //fclose(stdout);
#endif
    
    return 0;
}






