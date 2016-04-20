//kmp 实现
//利用模板串自身相似特性，构造next数组，next[i]代表i位置前子串前缀和后缀相等的最大长度(与回文区分开)
class Solution {
public:
	void prePare(string &s, vector<int>& next)
	{
		int j = 0;
		next[0] = -1;
		next[1] = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			j = next[i];
			while (j && s[j] != s[i]) j = next[j];
			next[i + 1] = s[i] == s[j] ? j + 1 : 0;
		}
	}
	int strStr(string haystack, string needle) {
		if (haystack.size() < needle.size())
			return -1;
		if (needle.size() == 0)
			return 0;
		vector<int> next(needle.size()+1);
		prePare(needle, next);
		
		int j = 0;
		for (int i = 0; i < haystack.size();++i)
		{
			while (j && haystack[i] != needle[j]) j = next[j];
			if (haystack[i] == needle[j])
			{
				j++;
				if (j == needle.size())
				{
					return i - j+1;
				}
			}	
		}
		return -1;
	}
};
