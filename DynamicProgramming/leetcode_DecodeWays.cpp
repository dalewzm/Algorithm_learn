//动态规划
//dp[i] = dp[i+1] + dp[i+2],需要满足相应条件
// dp[i] = 0; //以0开始的都是错误码，无法解码
// dp[i]= dp[i+1]
class Solution {
public:
    int numDecodings(string s) {
         if(s.size()==0)
            return 0;
        vector<int> dp(s.size()+2,0);
        dp[s.size()+1] = 0;
        dp[s.size()]=1;
        for(int i=s.size()-1; i>=0; --i)
        {
            if( (s[i]=='1')  ||(s[i]=='2' && s[i+1]<='6'))
                dp[i] =dp[i+1] + dp[i+2];
            else if(s[i]=='0')
               dp[i] = 0;
            else
               dp[i] =dp[i+1];
        }
        return dp[0];
    }
};
