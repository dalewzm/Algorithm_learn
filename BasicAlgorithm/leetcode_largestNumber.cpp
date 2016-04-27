//贪心，排序之后相加
bool cmp(const string &a,const string &b)
 {
        return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.resize(nums.size());
        int len = nums.size();
        for( int i=0; i<len; ++i)
           strs[i] = std::to_string(nums[i]);
        sort(strs.begin(),strs.end(), cmp);
        string ret; 
        for(int i=0; i<len; ++i)
            ret += strs[i];
        while(ret.size()>1 && ret[0]=='0')
        {
            ret = ret.substr(1,ret.size()-1);
        }
        return ret;
    }
};
