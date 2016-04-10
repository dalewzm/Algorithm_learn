//解法一 最基础
//使用额外空间进行需要平移，时间空间复杂度为o(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int > arrayv(nums.size());
        int len = nums.size();
        k = k%len;
        for(int i=0; i<len-k; ++i){
            arrayv[i+k] = nums[i];
        }
        for(int j=k,i=0; j>0; --j,++i)
            arrayv[i] = nums[len-j];
        for(int i=0; i<len; ++i)
            nums[i] = arrayv[i];
    }
};

//解法二
// 先将整个数组翻转
// 然后翻转前k个，和翻转后len-k个
class Solution {
public:
    void reverse(vector<int>::iterator st,vector<int>::iterator ed)
    {
        while(st<ed)
        {
            swap(*st,*ed);
            st++;
            ed--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
