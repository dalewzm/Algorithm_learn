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

//解法二: 并查集解法
class Solution {
public:
	int  transPos21(int a, int b)
	{
		return dimy*a + b;
	}
	void init()
	{
		int pos = 0;
		for (int i = 0; i < dimx; ++i)
		{
			for (int j = 0; j < dimy; ++j){
				pos = transPos21(i, j);
				pre[pos] = pos;
				rank[pos] = 1;
			}
		}
	}

	void Union(int a, int b, int c, int d)
	{
		int pos1 = transPos21(a, b);
		int pos2 = transPos21(c, d);
		int x = find(pos1);
		int y = find(pos2);
		if (x != y){
			if (rank[x] < rank[y])
			{
			    assert(pre[pos2]==y);
				pre[x] = y;
			}
			else{
				pre[y] = x;
				if(rank[x]==rank[y])
				    rank[x]++;
			}
		}
	}
	int find(int p)
	{
		if (pre[p] != p)
			 pre[p] = find(pre[p]);
		return pre[p];
		//return pre[p] != p ? pre[p] = find(pre[p]): pre[p];
	}

	int numIslands(vector<vector<char>>& grid) {
		pre.clear();
		rank.clear();
		if(grid.size() == 0)
			return 0;
		dimx = grid.size();
		dimy = grid[0].size();
		pre.resize(dimx * dimy);
		rank.resize(dimx * dimy);
		init();
	   
		for (int i = 0; i < dimx; ++i){
			for (int j = 0; j < dimy; ++j){
				if (grid[i][j] == '1'){
					if (j + 1 < dimy && grid[i][j + 1] == '1')
						Union(i, j, i, j + 1);
					if (j - 1 >=0 && grid[i][j - 1] == '1')
						Union(i, j, i, j - 1);
					if (i - 1 >=0 && grid[i - 1][j] == '1')
						Union(i, j, i - 1, j);
					if (i + 1 < dimx && grid[i + 1][j] == '1')
						Union(i, j, i + 1, j);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < dimx; ++i){
			for (int j = 0; j < dimy; ++j){
				int pos = transPos21(i, j);
				if (grid[i][j]=='1' && find(pos) == pos)
					cnt++;
			}
		}
		return cnt;
	}
	vector<int> pre;
	vector<int> rank;
	int dimy;
	int dimx;
};
