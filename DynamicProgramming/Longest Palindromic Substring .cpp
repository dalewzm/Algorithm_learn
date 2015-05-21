/*
最长回文子串 o(N)
*/

#include<string>
#define maxn 2000011
int dp[maxn];
int n;
#define intMin(a,b) ((a)>(b)?(b):(a))
using namespace std;
class Solution {
public:
	Solution()
	{

	}

	int maxRe(string &str, int &pos)
	{
		int j, maxf, maxAll;
		maxf = 1;
		j = 0;
		maxAll = 1;
		dp[0] = 1;
		pos = 0;
		for (int i = 1; i < str.size(); ++i)
		{

			if (j + maxf / 2 > i){
				int a = dp[(j << 1) - i];
				int b = dp[j] - ((i - j) << 1);
				dp[i] = intMin(a, b);
			}
			else
				dp[i] = 1;

			int up = i + dp[i] / 2 + 1;
			int low = i - dp[i] / 2 - 1;
			for (; up < str.size() && low >= 0; ++up, --low)
			{
				if (str[up] == str[low])
					dp[i] += 2;
				else
					break;
			}
			if (dp[i]>maxAll)
			{
				maxAll = dp[i];
				pos = i;
			}
			if ((i + dp[i] / 2) > (j + maxf / 2))
			{
				j = i;
				maxf = dp[i];
			}

		}
		return maxAll;
	}
string longestPalindrome(string s) {
		string str;
		if (s.size() == 1)
			return s;
		int p = (s.size() << 1) + 1;

		string b(p, (char)'#');
		for (int i = 1; i < b.size(); i += 2)
			b[i] = s[i >> 1];

		int ans = maxRe(b, p);
		int add = 0;
		string res(b, p - ans / 2, ans );
		add = res.size() / 2;
		if (res[res.size() - 1] != '#')
			add++;
		string rres(add,'1');
		for (int i = 0, j = 0; i < res.size(); ++i)
			if (res[i] != '#')
				rres[j++] = res[i];
		return rres;
	}
};
