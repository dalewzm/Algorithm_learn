//统一转换大小写
//然后头尾开始向中间遍历，忽略非字母数字，看是否相同
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0; i<s.size(); ++i)
            s[i] |= 32;
        int len = s.size()-1;
        for(int i=0,j=len; i<=j; )
        {
           if(( s[i]>'z' || s[i] <'a') && (isdigit(s[i])==false)){
                i++;
                continue;
            }
            if(( s[j]>'z' || s[j] <'a') && (isdigit(s[j])==false)){
                j--;
                continue;
            }
            
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
        
    }
};
