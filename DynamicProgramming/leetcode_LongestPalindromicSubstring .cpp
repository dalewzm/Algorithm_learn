//更简洁一点写法
//dp[i] 代表 以i 为中心的最大回文子串半径，包括它自己 "aba" dp[1] =2;
//pR 代表曾经判断回文子串所到达的最右位置的下一个位置
//idx 代表能到达最右位置的回文串的中心
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)
            return s;
        string extend(s.size()*2+1,'#');
        for(int i=0; i<s.size(); ++i)
            extend[i*2+1] = s[i];
        vector<int> dp(extend.size(),0);
        int pR =0;
        int idx = 0;
        for(int i=0; i<extend.size(); ++i){
            dp[i] = 1;
            if(pR > i){
                int j = 2*idx - i;
                dp[i] = min(dp[j],pR-i);
                for(int k=dp[i]; i+k<extend.size(); ++k )
                {
                    if( i-k >= 0 && extend[i-k]==extend[i+k])
                    {
                        dp[i]++;
                        
                    }
                    else
                        break;
                }
                if( i + dp[i]>pR){
                    pR = i + dp[i];
                    idx = i;
                }
            }
            else{//之前还没有扫到这里
                for(int  j=1; i+j<extend.size(); ++j){
                    if(i-j>=0  && extend[i-j]==extend[i+j])
                    {
                        dp[i]++;
                    }
                    else
                        break;
                }
                if(i+dp[i]>pR)
                {
                    pR = i+dp[i];
                    idx = i;
                }
            }
        }
        int maxlen = 0;
        for(int i=0; i<extend.size(); ++i)
            if( dp[i] > maxlen )
            {
                maxlen = dp[i];
                idx = i;
            }
        string ans;
        if(extend[idx]=='#')
            ans.resize(maxlen/2*2);
        else
            ans.resize(maxlen/2*2-1);
        int cnt = 0;
        for(int i= idx-maxlen+1; i<idx+maxlen; ++i)
        {
            if(extend[i]!='#')
                ans[cnt++] = extend[i];
        }
        return ans;
    }
};
