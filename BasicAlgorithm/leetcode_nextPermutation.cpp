//from end to find a pos a[i]>a[i-1],this is change point
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=0;
        int tmp = 0;
        for(int i=nums.size()-1; i>0; i--)
        {
            if(nums[i]>nums[i-1]){
                j = i;
                break;
            }
        }
         int len = nums.size()-1;
         int idx = 0;
        if(j){//find a pos
            for(idx=len; idx>=j; idx--)
                if(nums[idx]>nums[j-1])
                    break;
            tmp = nums[idx];
            nums[idx] = nums[j-1];
            nums[j-1] = tmp;
            sort(nums.begin()+j,nums.end());
        }

        else{
            
            for(int i=0; i<nums.size()/2; ++i)
            {
                tmp = nums[i];
                nums[i] = nums[len-i];
                nums[len-i] = tmp;
            }
        }
    }
};
