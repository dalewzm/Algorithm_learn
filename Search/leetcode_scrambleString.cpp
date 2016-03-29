
#include<string>
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
       if(s1==s2)
           return true;
       int len = s1.size();
       int count[26]={0};
       //判断两个串的字符是否一样
       for(int i=0; i<len; ++i)
       {
           count[s1[i]-'a']++;
           count[s2[i]-'a']--;
       }
       for(int i=0; i<26; ++i)
           if(count[i])
                return false;
      //枚举划分位置，某个位置划分成两个子串
      //同时交换这个节点也要做下测试
       for(int i=1; i<len; ++i){
           if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,len-i),s2.substr(i,len-i)))
            return true;
           if(isScramble(s1.substr(0,i),s2.substr(len-i,i)) && isScramble(s1.substr(i,len-i),s2.substr(0,len-i)))
           return true;
       }
        return false;
        
    }
};
