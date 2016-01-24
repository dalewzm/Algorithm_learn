class Solution {
public:
	int myAtoi(string str) {
		long long ret = 0;
		bool flagPositive=true, flagNum = true, flagFirst = true;
		string::iterator it= str.begin();
       
        do{
            if(*it == ' ')
                *it++;
            else
                break;
        }while(it != str.end());
		do{
			if (*it >= '0' && *it <= '9')
			{
				ret = ret * 10 + (*it - '0');
                if(ret>INT_MAX)
                    break;
			}
			else if (*it == '-' && flagFirst)
			{
            
				flagPositive = false;
			}
            else if(*it == '+' && flagFirst){
                ;
            }
			else{
				flagNum = false;
			}
			it++;
            flagFirst = false;
		} while (*it !='\0' && flagNum && it!=str.end());
			if (flagPositive){
                if(ret > INT_MAX)
                    ret = INT_MAX;
				return (int)ret;
            }
			else{
                long long int t= INT_MIN;
                
                if(-ret < t)
                    return INT_MIN;
				return (int)-ret;
            }
		
    }
};
