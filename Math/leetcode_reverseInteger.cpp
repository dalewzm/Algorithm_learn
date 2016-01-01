//maybe better solution
int reverse(int x) {
    long long res = 0;
     while(x){
        res = res*10 + x%10;
        x/=10;
    }
    return (res>0x7fffffff || res<-2147483648)?0:res;
}



class Solution {
public:
    int reverse(int x) {
      int res = 0;
       while(x){
        if(res>0x7fffffff/10 || res<int(0x80000000)/10)
          return 0;
        res = 10*res + x%10;
        x/=10;
      }
      return res;
    }
};
