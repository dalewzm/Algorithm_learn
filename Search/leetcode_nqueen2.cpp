class Solution {
public:
    #define stackPush(r,c,ld,rd) { si++, stackr[si]=r,stackc[si]=c,stackld[si]=ld,stackrd[si]=rd;}

#define stackPop() { si--;}// c=stackc[si];r=stackr[si];}

#define stackPeek() {r=stackr[si],c=stackc[si],ld=stackld[si],rd=stackrd[si];}
    int totalNQueens(int n) {
         int sum = 0;
       
        const int maxn = 500;
        int upp = (1<<n)-1;
        int stackc[maxn];
        int stackr[maxn];
        int stackld[maxn];
        int stackrd[maxn];
        int si = 0;
        //int pos = 0,p=0;
        int r=0,c=0,ld=0,rd=0;
     
        stackPush(r, c, ld, rd);
        int p=0,pos = 0,state = 0;
        while(si>0)
        {
            stackPeek()
            if(r==n)
            {
                sum++;
                stackPop();
            }
            else{
                stackPop();
                pos = ~(c | ld | rd)&upp;
                p = 0;
                while(pos){
                    p = (pos & -pos);
                    pos-=p;
                    stackPush(r+1, c+p, (ld+p)<<1, (rd+p)>>1);
                }
            }
        }
        //cout<<sum<<endl;
        return sum;

    }
};
