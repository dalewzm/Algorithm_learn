//o(n) solution
// a1 a2 q1 a3 q2 a4 q1
//       i     j
//先找到包含所有需要关键字的i和j，然后i+1，看是否仍满足，不满足就扩大j，窗口大小就是j-i+1
//细节: 如何维护所需要的是否都满足了
// 通过require[] 及 diff变量,diff变量维护总共差多少个，require[k],表明k元素仍需相应个
//如果diff为0 则满足了
class Solution {
public:
	string minWindow(string s, string t) {
		string ret;
		if (s.size() == 0 || t.size() == 0)
			return ret;
		int diff = 0;
		const int maxn = 256;
		int require[maxn]={0};
		bool isNeed[maxn]={0};
		for (int i = 0; i < t.size(); ++i)
		{
				diff++;
				isNeed[t[i]] = 1;
				require[ t[i] ]++;
		}
	
		int ed = -1, st = 0;
		int minLen = s.size() + 1;
		int minIdx = 0;
		
		while (st < s.size() && ed < (int)s.size()){
			if (diff){
				ed++;
				if (isNeed[s[ed]] && --require[s[ed]] >= 0)
				{
					diff--;
				}
			}
			else{
				if (ed - st + 1 < minLen)
				{
					minLen = ed - st + 1;
					minIdx = st;
				}
				if (isNeed[s[st]] && require[s[st]]++ == 0)
				{
					diff++;
				}
				st++;
			}
		}
		if(minLen == s.size() + 1)
		    return "";
		return s.substr(minIdx, minLen);
	}
};
