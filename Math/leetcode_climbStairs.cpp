//f(n ) = f(n-1) + f(n-2)
int climbStairs(int n) {
     if(n<2)
       return 1;
    int n_1 = 1;
    int n_2 = 1;
    int res = 0;
    for(int i=2; i<=n; ++i){
        res = n_1 + n_2;
        n_2 = n_1;
        n_1 = res;
    }
    return res;
}
