class Solution {
public:
    Solution()
    {
        memset(convert, 0, sizeof(convert));
        convert['I'] = 1;
        convert['V'] = 5;
        convert['X'] = 10;
        convert['C'] = 100;
        convert['D'] = 500;
        convert['M'] = 1000;
    }
    int romanToInt(string s) {
        int ret = 0;
        int maxLevel = 0;
        for(size_t i=s.size()-1; i>=0; --i){
            if(convert[s[i]]>= maxLevel){
                maxLevel = convert[s[i]];
                ret += convert[s[i]];
            }
            else
                ret -= convert[s[i]];
        }
        return ret;
    }
    int convert[256];
};
