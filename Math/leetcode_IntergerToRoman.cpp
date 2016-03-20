//进制转换，4和9的特别处理
class Solution {
public:
    Solution()
    {
        b[0][0] = 'I';
        b[0][1] = 'V';
        b[0][2] = 'X';
        b[1][0] = 'X';
        b[1][1] = 'L';
        b[1][2] = 'C';
        b[2][0] = 'C';
        b[2][1] = 'D';
        b[2][2] = 'M';
        b[3][0] = 'M';
    }
    string intToRoman(int num) {
        int digit[4];
        int base =10;
        int cnt = 0;
        while(num){
            digit[cnt++] = num % 10;
            num/=10;
        }
        int len = 0;
        stack<char> str;
        for(int d =0; d<cnt; ++d){
            if(digit[d] <= 3)
            {
                for(int i=0; i<digit[d]; ++i)
                    str.push(b[d][0]);
            }
            else if(digit[d] == 4)
            {
                 
                str.push(b[d][1]);
                str.push(b[d][0]);
               
            }
            else if(digit[d] == 5)
            {
                 str.push(b[d][1]);
            }
            else if(digit[d]< 9)
            {
                
                for(int i=0; i<digit[d]-5; ++i)
                    str.push(b[d][0]);
                str.push(b[d][1]);
            }
            else if(digit[d]==9)
            {
                 str.push(b[d][2]);
                 str.push(b[d][0]);
                
            }
        }
        string ret(str.size(),'1');
        cnt = 0;
        while(!str.empty())
        {
            ret[cnt++]=str.top();
            str.pop();
        }
        return ret;
    }
    char b[4][3];
    
};
