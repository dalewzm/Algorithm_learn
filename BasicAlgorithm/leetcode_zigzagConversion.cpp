#include<memory.h>
#include<cstdlib>
class Solution {
public:
    string convert(string s, int numRows) {
        string ans(s);
        
        int len = s.size();
        
        if(0==len || 1==len)
        return s;
        char tmp[numRows][len];
        int times =1;
        if(numRows > 1)
            times = len / (2*numRows - 2)+1 ;
        int cnt=0,steps=numRows-1;

        memset(tmp, 0 ,sizeof(tmp));
        for(int i=0; i<times; ++i){
            for(int j=0; j<numRows; ++j)
            {
                if(cnt<len)
                {
                    tmp[j][i*steps]= s[cnt++];
                }
            }
            for(int j=1; j<numRows-1; ++j)
            {
                if(cnt<len)
                {
                    tmp[numRows-j-1][i*steps+j] = s[cnt++];
                }
            }
        }
        cnt =0;
       
        for(int i=0; i<numRows; ++i)
        {
            for(int j=0; j<len; ++j)
                if(tmp[i][j])
                    ans[cnt++] = tmp[i][j];
        }
        return ans;
    }
};
