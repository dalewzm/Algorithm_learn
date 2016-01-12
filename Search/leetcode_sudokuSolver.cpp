#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
//#include <unordered_map>
//#include <iomanip>

using namespace std;

const int maxn = 9;
int brow[maxn];
int bcol[maxn];
int box[maxn];
int upp = (1<<9)-1;


class Solution {
public:
    void genMap()
    {
        for(int i=0; i<9; i++)
        hashtab[1<<i] = i+1;
    }
    void dfs(vector<vector<char>>& board,int i, int j,bool &findans)
    {
        if(i==8 && j==9){
            findans = true;
            return;
        }
        //++j;//dfs start from 0,-1;
        if(j==9)
        {
            i++;
            j = 0;
        }
        int num = 0;
        int idx =  i/3*3+j/3;
        if(board[i][j]!='.')
        {
            dfs(board,i,j+1,findans);
        }else{ // we need begin enumerate
            int pos = ~(brow[i] |bcol[j] | box[idx]) & upp;
            int p =0;
            while(pos){
                p = pos & (-pos);
                pos -= p;
                //num = hashtab[p];
                brow[i] |= p;
                bcol[j] |= p;
                box[idx] |= p;
               
                board[i][j] = '0'+hashtab[p];
                dfs(board,i,j+1,findans);
                if(findans)
                break;
                board[i][j] = '.';
                //get rid of num
                brow[i] ^= p;
                bcol[j] ^= p;
                box[idx] ^= p;
                
            }
            
        }
        
        
    }
    
    void generateValidPos(vector<vector<char>>& board)
    {
        int num = 0;
        int idx = 0;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.')
                    continue;
                 idx =  i/3*3+j/3;
                num = board[i][j]-'0';
                num = 1<<(num-1);
                brow[i] |= num;
                bcol[j] |= num;
                box[idx] |= num;
                
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        
        genMap();
        memset(brow, 0, sizeof(brow));
        memset(bcol, 0, sizeof(bcol));
        memset(box, 0, sizeof(box));
        //need set 0;
        bool ans = false;
        generateValidPos(board);
        dfs(board,0,0,ans);
        return ;
    }
    map<int,int> hashtab;
};
