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

//欧拉筛法
//o(n)
//按照 k = M*p1 来筛，p1是合数k的最小质因子
//证明： 1. 肯定能筛到
//       2. 最多筛一次，假设在 i = N，质因子为p2时也筛了一次，p2>p1(p2是k的因子就必定大于p1), N<M。
//         (2-1) p1| p2(p2是p1的倍数), 此种情况不可能，p2为质因子
//        （2-2）p2不是p1倍数, 那么p1 | N, 在i == N时，当j遍历到primeList[j] = p1时，N%p1 ==0,跳出循环
class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
          return 0;
       int *primeTable = new int[n]{1};
       int *primeList = new int[n>>1];
       int cnt = 0;
       int idx = 0;
       for(int i=0; i<n; ++i)
        primeTable[i] = 1;
		primeTable[1] = 0;
		for (int i = 2; i < n; ++i){
		    if(primeTable[i])
		    {
		        primeList[cnt++] = i;
		    }
			for (int j = 0; j < cnt; ++j){
				idx = i*primeList[j];
			    if (idx>=n)
				    break;
			    primeTable[idx] = 0;
			    if (i % primeList[j]==0)
				    break;
			}
		}
		
		int ret = 0;
		for (int i = 2; i < n; ++i)
		{
			if (primeTable[i])
				ret++;
		}
		delete[]primeTable;
		delete[]primeList;
		return ret;
    }
};
