/*
ID: dalewzm1
PROG: skidesign
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
//#define __ONLINE__ 1
#ifndef __ONLINE__ 
#define FILE_NAME "wormhole"
//#define IFILE FILE_NAME.in
#include<fstream>
#include<string>
ifstream fin("skidesign.in");
ofstream fou("skidesign.out");
#define in(a) fin>>a
#define out(a) fou<<a<<endl
#define inpoint(p) fin>>p.x>>p.y
#else
#define in(a) cin>>a
#define out(a) cout<<a
#define inpoint(p) cin>>p.x>>p.y
#endif

typedef struct hill
{
	hill(int h=0){ height = h, num = 1; }
	int num;
	int height;
	bool operator <(const  hill& rhs) const
	{
		return height < rhs.height;
	}
}hill;
const int len = 1001;
int high[len];
hill hills[len];
int n;
int minh, maxh,cnt;
int res;
void init()
{
	sort(high, high + n);
	minh = high[0], maxh = high[n-1];
	cnt = 0;
	hills[cnt].height = high[0];
	hills[cnt].num = 1;
	for (int i = 1; i < n; ++i)
	{
		
		if (high[i] == hills[cnt].height)
			hills[cnt].num++;
		else{
			hills[++cnt].num = 1;
			hills[cnt].height = high[i];
		}
	}
	++cnt;
}

int getCost(int add, int sub)
{
	hill* lp = upper_bound(hills, hills + cnt, hill(minh + add));
	int sum =0;
	for (hill* begin = hills; begin < lp; begin++)
	{
		sum += (minh + add - begin->height)*(minh + add - begin->height)*(begin->num);
	}
	hill* rp = lower_bound(hills, hills + cnt, hill(maxh - sub));
	for (hill* it = rp; it < hills + cnt; it++)
		sum += (it->height - maxh + sub)*(it->height - maxh + sub)*(it->num);
	return sum;
}
void solve()
{
	if (maxh - minh <= 17)
	{
		res = 0;
		return;
	}
	int need = maxh - minh-17;
	res = 10000 * 10000;
	for (int i = need / 2; i >= 0; --i)
	{
		int other = need - i;
		int tmp = getCost(i, other);
		if (res > tmp)
			res = tmp;
		tmp = getCost(other, i);
		if (res > tmp)
			res = tmp;
	}
}

int main()
{
	in(n);
	for (int i = 0; i < n; ++i)
		in(high[i]);
	init();
	solve();
	out(res);
}
