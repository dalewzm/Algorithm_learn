//hash 
#include<iostream>
#include<string>
#define maxn 10000
using namespace std;


int vis[128];
int lastc[128];
class Solution{
public:
	int lengthOfLongestSubstring(string s){
		if (s.size() < 2)
			return s.size();
		
		memset(vis, 0, sizeof(vis));
		int *last = new int[s.size()]{-1};
		int pos;
		for (int i = 0; i < s.size(); ++i) //pre
		{
			pos = s[i];
			if (!vis[pos])
			{
				vis[pos] = 1;
				lastc[pos] = i;
			}
			else{
				last[i] = lastc[pos];
				lastc[pos] = i;
			}
		}
		int lenth, maxl, sum;
		memset(vis, 0, sizeof(vis));
		lenth = 0;
		maxl = 0;
		int all = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			pos = s[i];
			if (vis[pos]) //遇到重复
			{
				if (lenth > maxl)
					maxl = lenth;
				sum = (i - last[i]);
				int k = 0;
				memset(vis, 0, sizeof(vis));
				for (int j = last[i]; k < sum; ++j, ++k)
					vis[s[j]] = 1;
				lenth = i - last[i];
				
			}
			else{
				lenth++;
				vis[pos] = 1;
			}

		}
		maxl = maxl > lenth ? maxl : lenth;
		return maxl;
	}
};
