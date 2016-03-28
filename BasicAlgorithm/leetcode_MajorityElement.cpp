//每次消除掉数组中两个不同的元素，不影响答案
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candiate = nums[0];
        int times = 1;
        int n = nums.size();
        for(int i=1; i<n; ++i){
             if(times == 0){
                candiate = nums[i];
                times = 1;
                continue;
            } 
            if( candiate == nums[i])
                times++;
            else
                times--;
           
        }
        return candiate;
    }
};
