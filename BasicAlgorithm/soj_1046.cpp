//soj 1046 Plane Spotting
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

const int maxn= 90000;
const int maxq = 300;

typedef struct period
{
    int start;
    int end;
    int len;
    double per;
}period;

bool cmp(const period &l, const period &r)
{
    if(fabs(l.per-r.per) > 0.0001)
        return l.per > r.per;
    if(l.end-l.start != r.end-r.start)
        return (l.end-l.start) > (r.end - r.start);
    return l.end < r.end;
}

period p[maxn];
int quar[maxq];
int n,n_period,n_quar;
void init()
{
    scanf("%d %d %d",&n,&n_period,&n_quar);
    for(int i=0; i<n; ++i)
        scanf("%d",&quar[i]);
}

void solve()
{
    int cnt = 0;
    int sum = 0;
    for(int i=0; i<=n-n_quar; ++i)
    {
        sum = 0;
        for(int j=i; j<i+n_quar-1 && j<n; ++j)
            sum+= quar[j];
        int len = n_quar;
        for(int k=i+n_quar-1; k<n; ++k)
        {
            sum += quar[k];
            p[cnt].start = i+1;
            p[cnt].end = k+1;
            p[cnt].per = sum*1.0/len;
            len++;
            cnt++;
        }
    }
    int need = min(cnt,n_period);
    sort(p,p+cnt, cmp);
    for(int i=0; i<need; ++i)
    {
        printf("%d-%d\n",p[i].start,p[i].end);
    }
}

int main()
{
    //freopen("input.in","r",stdin);
    //freopen("output.out", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int k=1; k<=t; ++k){
        init();
        printf("Result for run %d:\n",k);
        solve();
    }
    //fclose(stdin);
    //fclose(stdout);
}
