//不删除元素，只是采取赋值，避免了删除导致的内存变化
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while(i<n)
        {
            if(nums[i]==val){
                nums[i] = nums[n-1];
                n--;
            }
            else
              i++;
        }
        return n;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it)
        {
            if(*it == val)
            {
                nums.erase(it);
                it--;
            }
        }
        return nums.size();
    }
};
