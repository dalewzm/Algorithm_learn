#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <memory.h>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >  ans;
        int len = nums.size();
        vector<int> tmp(3,2);
        sort(nums.begin(),nums.end());
        map<vector<int>, int> hasht;
        int cnt = 0;
        for(int i=0; i<len; ++i){
            if(i>0 && nums[i]==nums[i-1])
               continue;
             if(nums[i]>0)
                break;
            for(int j=i+1; j<len; ++j){
                if(nums[i]+nums[j]>0 )
                    break;
                if( nums[i]+nums[j] < -nums[len-1])
                    continue;
                for(int k=j+1; k<len; ++k){
                    if(nums[i]+nums[j]+nums[k]==0){//find a solution
                        if(nums[i]==tmp[0] && nums[j]==tmp[1])  //remove dup
                             break;
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[k];
                        
                        ans.push_back(tmp);
                        break;
                       
                    }
                }
            }
        }
        return ans;
    }
};

