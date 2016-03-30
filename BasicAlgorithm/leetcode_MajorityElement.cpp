//每次消除掉数组中两个不同的元素，不影响答案
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candiate;
        int times = 0;
        int n = nums.size();
        //从0开始遍历，更直观
        for(int i=0; i<n; ++i){  
             if(times == 0){
                candiate = nums[i];
                times = 1;
            }
            else{
                if( candiate == nums[i])
                    times++;
               else
                    times--;
            }
        }
        return candiate;
    }
};
