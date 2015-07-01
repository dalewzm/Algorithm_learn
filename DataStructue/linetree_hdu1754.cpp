//点修改，求区间最值
#include<cstdio>
#include<algorithm>
using namespace std;

#pragma warning(disable:4996)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
//#define imax(a,b) ((a)>(b)?(a):(b))
#define  imax max
#define maxn 222221
int ans[maxn << 2];

void pushUp(int rt)
{
    ans[rt] = imax(ans[rt << 1], ans[rt << 1 | 1]);
}


void build(int l, int r, int rt)
{
    if (l == r){
        scanf("%d", ans + rt);
        return;
    }
    int m = (l + r) >>1 ;
    build(lson);
    build(rson);
    pushUp(rt);
}

void set(int l, int r, int rt, int pos, int add)
{
    if (l == r){
        ans[rt] = add;
        return;
    }
    int m = (l + r) >>1 ;
    if (pos <= m)
        set(lson, pos, add);
    else
        set(rson, pos, add);
    pushUp(rt);
}

int query(int l, int r, int rt, int L, int R)
{
    if (L <= l && r <= R){
        return ans[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L <= m)
        ret = imax(ret, query(lson, L, R));
    if (m < R)
        ret = imax(ret, query(rson, L , R));
    return ret;
}

int main()
{
    int n, m,pos,add;
    char cmd[10];
    while (~scanf("%d %d", &n, &m)){
        build(1, n, 1);
        for (int i = 0; i < m; i++){
            scanf("%s",cmd);
            scanf("%d%d", &pos, &add);
            if (cmd[0] == 'Q')
                printf("%d\n", query(1, n, 1, pos, add));
            else
                set(1, n, 1, pos, add);
        }
    }
}
