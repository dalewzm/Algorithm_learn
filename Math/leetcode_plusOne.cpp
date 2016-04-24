//高精度加法简易模拟版
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits.begin(),digits.end());
        if(digits.size()==0)
            return ret;
        reverse(ret.begin(),ret.end());
        int add = 1;
        for(int i=0;add && i<ret.size(); ++i)
        {
            ret[i]++;
            if(ret[i]>9)
            {
                ret[i] = 0;
                add = 1;
            }
            else{
                add = 0;
            }
        }
        if(add)
        ret.push_back(1);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
