// a better solution
class Solution {
public:
    
    
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 0x7ffffffe;
        vector<int> dp(amount+1,INF);
        dp[0] = 0;
        for(int i=0; i<=amount; ++i){
            for(int j=0; j<coins.size(); ++j){
                if(i+coins[j]<=amount && dp[i+coins[j]] > dp[i] + 1)
                    dp[i+coins[j]] = dp[i] + 1;
            }
        }
        return dp[amount]==INF ? -1 : dp[amount];
    }
};


class Solution {
public:
   
     void visit(vector<int> &dp,vector<int> &vis,vector<int> &c,int s)
    {
        if(vis[s])
            return ;
        if( s== 0)
        {
            dp[s] = 0;
            return;
        }
        dp[s] = -1;
        int maxv = 0x7fffffff;
        vis[s] = 1;
        for(int i=0; i<c.size(); ++i)
        {
            if(s-c[i]<0)
               continue;
            if(!vis[s-c[i] ])
                visit(dp, vis, c, s-c[i]);
            if(dp[s-c[i]]>=0)
            maxv = min(maxv,dp[s-c[i]]+1);
        }
        if(maxv < 0x7fffffff)
          dp[s] = maxv;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount<=0)
          return 0;
        vector<int> dp(amount+1,-1);
        vector<int> vis(amount+1,0);
        visit(dp, vis, coins, amount);
        
        return dp[amount];
    }
    
};
