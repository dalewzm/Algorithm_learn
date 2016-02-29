#include <cmath>
#include <vector>

using namespace std;
class Solution {
public:
     int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0x7ffffff;
        int res = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n-1; ++j){
                int tmp = nums[i] + nums[j];
                vector<int>::iterator it = lower_bound(nums.begin()+j+1, nums.end(), target-tmp);
                if(it == nums.end())//
                {
                    it--;
                    updateValue( tmp + (*it), target, ans, res);
                }
                else{
                    updateValue(tmp+(*it), target, ans,res);
                    --it;
                    if(it>nums.begin()+j)
                        updateValue(tmp+(*it), target, ans,res);
                }
                
                if(tmp>target && nums[j]>0){
                    updateValue(tmp+nums[j+1], target, ans, res);
                    break;
                }
               
            }
        }
       
        return res;
    }
    
    void updateValue(int v,int target,int& ans,int &res)
    {
        if(abs(v-target) < ans){
            ans = abs(v-target);
            res = v;
        }
    }

    
};
