#include<string>
using namespace std;
class Solution {
public:
    Solution():N(0){}
    int getDigIdx(int x,int y)
    {
        if(y==0)
            return x;
        return N+y;
    }
    int getRidx(int x, int y)
    {
        if(x==0)
            return y+2*N; // not minues 1 for speed
        return x+3*N;
    }
    void dfs(int depth, vector<int>& path)
    {
        if(depth==N){
            sum++;
            vector<string> curAns;
            for(vector<int>::iterator it=path.begin(); it!=path.end(); ++it)
            {
                string tmp(N,'.');
                tmp[*it]='Q';
                curAns.push_back(tmp);
            }
           
            res.push_back(curAns);
            return;
        }
        int minv = 0;
        int didx = 0;
        int ridx = 0;
        for(int i=0; i<N; ++i){
            if(!visitCol[i]){
                minv = min(depth,i);
                didx = getDigIdx(depth-minv, i-minv);
                minv = min(N-1-i,depth);
                ridx = getRidx(depth-minv, i+minv);
               
                if(visitDig[didx]==0 && visitDig[ridx]==0){
                    visitCol[i] = 1;
                    visitDig[didx] = 1;
                    visitDig[ridx] = 1;
                    path[depth] = i;
                    
                    dfs(depth+1, path);
                    visitCol[i] = 0;
                    path[depth] = 0;
                    visitDig[didx] = 0;
                    visitDig[ridx] = 0;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        sum = 0;
        N = n;
        visitCol.resize(n,0);
        visitDig.resize(4*n,0);
        res.resize(0);
        res.clear();
        vector<int> curPath(n,0);
        dfs(0,curPath);
        cout<<sum<<endl;
        return res;
        
    }
    int N;
    int sum;
    vector<int> visitCol;
    vector<int> visitDig;
    vector<vector<string> > res;
};
