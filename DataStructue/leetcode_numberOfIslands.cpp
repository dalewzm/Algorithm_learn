//解法一 dfs 求连通块数量
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector< vector<int>> &visit,int x,int y)
    {
        visit[x][y] =1;
        for(int i=0; i<4; ++i)
        {
            int nx = x+dx[i];
            int ny=  y+dy[i];
            if(x+dx[i]>=0 && nx<grid.size()
               && ny>=0 && ny<grid[0].size()
               && !visit[nx][ny] && grid[nx][ny]=='1')
                dfs(grid,visit,nx,ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        vector< vector<int>> visit(grid.size(), vector<int>(grid[0].size(),0));
        int cnt = 0;
        for(size_t i=0; i<grid.size(); ++i){
            for(size_t j=0; j<grid[0].size(); ++j){
                if(grid[i][j]=='1' && !visit[i][j]){
                    cnt++;
                    dfs(grid,visit,i,j);
                }
            }
        }
        return cnt;
    }
};
