//dp[i] 代表以i结尾的子数组和最大的值
//dp[i] = dp[i-1] + nums[i]  ,dp[i-1]>=0
//      = nums[i]   dp[i-1]<0

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(),0);
        int maxSum = (int)0xffffffff;
        dp[0] = nums[0];
        maxSum = dp[0];
        for(int i=1; i<nums.size(); ++i){
            if( dp[i-1]>0 )
              dp[i] = dp[i-1]+ nums[i];
            else
              dp[i] = nums[i];
            maxSum = max(dp[i],maxSum);
            
        }
        return maxSum;
    }
};
