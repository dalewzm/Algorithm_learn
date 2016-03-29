/*
ID: dalewzm1
PROG: wormhole
LANG: C++
*/
#include<iostream>
#include<memory.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;


#ifndef __ONLINE__ 
#define FILE_NAME "wormhole"
//#define IFILE FILE_NAME.in
#include<fstream>
#include<string>
ifstream fin("wormhole.in");
ofstream fou("wormhole.out");
#define in(a) fin>>a
#define out(a) fou<<a<<endl
#define inpoint(p) fin>>p.x>>p.y
#else
#define in(a) cin>>a
#define out(a) cout<<a
#define inpoint(p) cin>>p.x>>p.y
#endif

typedef unsigned long long ll;
typedef struct point
{
public:
	point(){ x = 0, y = 0; }
	point(int a, int b){ x = a, y = b; }
	int x;
	int y;
	bool operator < (const point& rhs) const
	{
		if (x != rhs.x)
			return (x < rhs.x);
		return (y < rhs.y);
	}

	bool operator()(const point& p1, const point& p2)
	{
		if (p1.x != p2.x)
			return p1.x < p2.x;
		return p1.y < p2.y;
	}
}point;

typedef struct _pair
{
	int fst;
	int sed;
	_pair(int a = 0, int b = 0){ fst = a, sed = b; }
	bool operator ==(const _pair& rhs) const
	{
		if (fst == rhs.fst && sed == rhs.sed)
			return true;
		return false;
	}
}_pair;


const int maxn = 200;
_pair ptPair[maxn];
point holes[maxn];
bool visit[maxn];
bool visit2[maxn];
int pairs[maxn];
int  ptPairs[maxn][maxn];
bool isVisit[maxn][maxn];
int n;
int pairCnt;
int ans;
int fact[7] = { 1, 1, 2, 6, 24, 120, 720 };

void init()
{
	memset(visit, 0, sizeof(visit));
	memset(pairs, -1, sizeof(pairs));
	memset(visit2, 0, sizeof(visit2));
	memset(isVisit, 0, sizeof(isVisit));
	sort(holes, holes + n);
	pairCnt = 0;
	ans = 0;
	
}

bool checkPair()
{
	return true;
}

bool getNext(int num)
{
	
	int k = pairs[num];
	if (isVisit[num][k])
		return true;
	isVisit[num][k] = 1;
	num = k;
	for (int i = num+1; i<n; ++i){
		if (holes[i].y == holes[num].y && holes[i].x >holes[num].x)
		{
			return getNext(i);
		}
	}
	return false;
}
	

bool judge()
{
	for (int i = 0; i < n; ++i)
	{
		memset(isVisit, 0, sizeof(isVisit));
		if (getNext(i))
			return true;
		memset(isVisit, 0, sizeof(isVisit));
		if (getNext(pairs[i]))
			return true;
	}
	return false;
}

void dfs(int depth,int lastx,int lasty)
{
	int i;
	for ( i = 0; i < n; ++i)
	{
		if (!visit2[i])
			break;
	}
	for (int j = i + 1; j < n; ++j)
	{
			if (!visit2[j]){
				pairs[i] = j;
				pairs[j] = i;
				visit2[i] = 1;
				visit2[j] = 1;
				if (depth == n / 2 - 1)
				{
					if (judge())
					{
						ans++;
					}
					visit2[i] = 0;
					visit2[j] = 0;
					pairs[i] = -1;
					pairs[j] = -1;
					return;
				}
				else{

					dfs(depth + 1,i,j);
					visit2[i] = 0;
					visit2[j] = 0;
					pairs[i] = -1;
					pairs[j] = -1;
				}
			}
	}
	
}

int main()
{

	in(n);
	for (int i = 0; i < n; ++i){
		inpoint(holes[i]);
	}
	init();

	dfs(0,0,0);
	out(ans);
	return 0;

}
