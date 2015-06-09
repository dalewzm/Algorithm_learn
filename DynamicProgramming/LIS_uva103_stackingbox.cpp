#include<iostream>
#include <memory.h>
#include<algorithm>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
#pragma warning(disable:4996)

int n, k, res;
int ans[301];
int pre[301];
typedef struct box{
	box(){ }
	int num;
	int dim[30];
	
	friend bool operator < (const box &a, const box &b){
		for (int i = 0; i< k; ++i){
			if (a.dim[i]>b.dim[i])return false;
		}
		return true;
	}
}box;

box boxs[41];
inline bool isSmaller(int a, int b){
	for (int i = 0; i < k; ++i)
		if (boxs[a].dim[i] >= boxs[b].dim[i])return false;
	return true;
}

void init()
{
	for (int i = 0; i < n; ++i)
	{
		ans[i] = 1;
		pre[i] = -1;
	}
}

void trace(int i)
{
	stack<int> path;
	path.push(i);
	while (pre[i] != -1)
	{
		path.push(pre[i]);
		i = pre[i];
	}
	int cnt = 0;
	while (!path.empty())
	{
		if (0 == cnt)
			cout << boxs[path.top()].num;
		else
			cout << " " << boxs[path.top()].num;
		path.pop();
		cnt++;
	}
	cout << endl;
}



void sovle()
{
	sort(boxs, boxs + n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
			if (isSmaller(j,i) && (ans[i]<ans[j] + 1))
			{
			ans[i] = ans[j] + 1;
			pre[i] = j;
			}
	}
	res = 0;
	int pos = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ans[i]>res)
		{
			res = ans[i];
			pos = i;
		}
	}
	cout << res << endl;
	trace(pos);

}
int main()
{

	while (~scanf("%d%d", &n, &k))
	{
		for (int i = 0; i < n; ++i)
		{
			boxs[i].num = i + 1;
			for (int j = 0; j < k; ++j)
			{
				scanf("%d", &boxs[i].dim[j]);
			}
			sort(boxs[i].dim, boxs[i].dim + k);
		}
		init();
		sovle();	//

	}
	return 0;
}
