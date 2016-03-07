class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxLen = 0x7fffffff;
        string ans;
        if(strs.size()==0)
             return ans;
        for(int i=0; i<strs.size(); ++i)
          if(strs[i].size() < maxLen)
              maxLen = strs[i].size();
        
        int len = 0;
        for(int j=0; j<maxLen; ++j)
        {
            for(int i=0; i<strs.size(); ++i)
            {
                if(strs[0][j] != strs[i][j])
                {
                    ans = string(strs[0],0,len);
                    return ans;
                }
            }
            len++;
        }
        
         ans = string(strs[0],0,len);
        
        return ans;
    }
};
