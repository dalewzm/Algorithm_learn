//#define debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <queue>
//#include <unordered_map>
#define REP(i,n) for(int i=0; i<(n); ++i)
#pragma warning(disable:4996)
using namespace std;


typedef struct Pos {
    Pos() { x = 0, y = 0; }
    explicit Pos(int a, int b, int l) { x = a, y = b, len = l; }
    Pos(int a, int b) { x = a, y = b; }
    int x;
    int y;
    int len;
}Pos;


int dirx[4] = { 0, 1, 0, -1 };
int diry[4] = { 1, 0, -1, 0 };

const int maxn = 25;
int r, c, cnt;
int board[maxn][maxn];
int visit[maxn][maxn][4];
int manVisit[maxn][maxn];
Pos start, tar, box, human;


bool isValid(Pos &p)
{
    if (p.x < r && p.x >= 0 && p.y < c && p.y >= 0 && board[p.x][p.y] != 1)
        return true;
    return false;
}


bool canMove(Pos &p)
{
    if (board[p.x][p.y] != 1 && board[p.x][p.y] != 2)
        return true;
    return false;
}

//检查人是否能够到达箱子的背后
//cur 是箱子当前位置
bool canPush(Pos &back, Pos &cur, Pos &man)
{
    if (!isValid(back))
        return false;
    if (board[back.x][back.y] == 1)
        return false;
    memset(manVisit, 0, sizeof(manVisit));
    queue<Pos> path;
    path.push(man);
    manVisit[cur.x][cur.y] = 1;
    manVisit[man.x][man.y] = 1;
    while (!path.empty()) {
        Pos p = path.front();
        path.pop();
        if (p.x == back.x && p.y == back.y) {
            //board[cur.x][cur.y] = 0;
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            Pos next(p.x + dirx[i], p.y + diry[i]);
            if (isValid(next)
                && !manVisit[next.x][next.y])
            {
                manVisit[next.x][next.y] = 1;
                path.push(next);
            }
        }
    }
    //board[cur.x][cur.y] = 0;
    return false;

}

int solve()
{
    queue<Pos> pushQueue;
    queue<Pos> humanQueue;
    box.len = 0;
    pushQueue.push(box);
    humanQueue.push(start);
    //visit[box.x][box.y] = 1;
    while (!pushQueue.empty()) {
        Pos cur = pushQueue.front();
        human = humanQueue.front();
        pushQueue.pop();
        humanQueue.pop();
        if (cur.x == tar.x && cur.y == tar.y)
        {
            //need process
            return cur.len;
        }
        for (int i = 0; i < 4; ++i) {
            Pos np(cur.x + dirx[i], cur.y + diry[i], cur.len + 1);
            Pos back(cur.x - dirx[i], cur.y - diry[i]);
            if (isValid(np)
                && !visit[np.x][np.y][i]
                && canPush(back, cur, human)) {
                pushQueue.push(np);
                humanQueue.push(back);
                visit[np.x][np.y][i] = 1;
            }
        }
    }
    return -1;
}

int main()
{
#ifdef debug
    //freopen("test.in","r",stdin);
    freopen("input.in", "r", stdin);
    //freopen("output.out","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; ++z) {
        scanf("%d %d\n", &r, &c);
        REP(i, r) {
            REP(j, c) {
                scanf("%d", &board[i][j]);
                if (board[i][j] == 4) {
                    human.x = i;
                    human.y = j;
                    start = human;
                    board[i][j] = 0;
                }
                else if (board[i][j] == 3)
                {
                    tar.x = i;
                    tar.y = j;
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2) {
                    box.x = i;
                    box.y = j;
                    board[i][j] = 0;
                }

            }
        }
        memset(visit, 0, sizeof(visit));
        //printf("%d\n",++cnt);
        int res = solve();
        printf("%d\n", res);

    }

#ifdef debug
    fclose(stdin);
#endif

    return 0;
}
