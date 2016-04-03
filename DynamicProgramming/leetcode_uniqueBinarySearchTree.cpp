//n个数,分别判断以i为根时候的树的种类,然后递归计算,记忆化搜索
class Solution {
public:
    void dfs(vector<int>&dp,int n)
    {
        if( n == 1){
            dp[1] = 1;
            return;
        }
        for(int i=1; i<=n; ++i)
        {
            if(!dp[i])
                dfs(dp,i);
            if(!dp[n-i])
                dfs(dp,n-i);
            dp[n]+= dp[i-1]*dp[n-i];
           
        }
    }
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] =1;
        dfs(dp,n);
        
        return dp[n];
    }
};
