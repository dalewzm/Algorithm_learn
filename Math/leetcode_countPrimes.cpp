//先素数筛法
//然后统计素数个数
class Solution {
public:
    int countPrimes(int n) {
        if(n<=0)
          return 0;
       int *primeTable = new int[n]{1};
       for(int i=0; i<n; ++i)
        primeTable[i] = 1;
		primeTable[1] = 0;
		for (int i = 2; i < n; ++i){
			for (int j = i*2; j < n; j += i){
				primeTable[j] = 0;
			}
		}
		
		int ret = 0;
		for (int i = 2; i < n; ++i)
		{
			if (primeTable[i])
				ret++;
		}
		delete[]primeTable;
		return ret;
    }
};
