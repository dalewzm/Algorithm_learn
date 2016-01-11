#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
//#include <unordered_map>
//#include <iomanip>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     
        const int maxn = 9;
        int brow[maxn];
        int bcol[maxn];
        int box[maxn];
        
        memset(brow, 0, sizeof(brow));
        memset(bcol, 0, sizeof(bcol));
        memset(box, 0, sizeof(box));
        
        int num = 0;
        int idx = 0;
        for(int i=0; i<9; ++i ){
            for(int j=0; j<9; ++j){
                if(board[i][j]=='.')
                    continue;
                num = board[i][j]-'0';
                num = 1<<(num-1);
                if(brow[i] & num) //row valid
                    return false;
                if(bcol[j] & num) //col valid
                    return false;
                idx = i/3*3+j/3;
                if(box[idx] & num) // sub valid
                    return false;
                brow[i] |= num;
                bcol[j] |= num;
                box[idx] |= num;
            }
        }

        return true;
    }
};
