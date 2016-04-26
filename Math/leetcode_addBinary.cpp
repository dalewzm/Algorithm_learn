//二进制加法
class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size());
        string ret(len,'0');
        int n =  a.size()-1;
        int m =  b.size()-1;
        int add = 0;
        len--;
        for(int i=n,j=m;i>=0||j>=0;len--)
        {
            if(i>=0){
                ret[len]+=a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                ret[len]+=b[j]-'0';
                j--;
            }
            if(add)
                ret[len]+=add;
            if(ret[len]>'1')
            {
                ret[len]= (ret[len]-'0')%2+'0';
                add =1;
            }
            else
             add = 0;
            
        }
        if(add)
         ret.insert(ret.begin(),'1');
        return ret;
    }
};
