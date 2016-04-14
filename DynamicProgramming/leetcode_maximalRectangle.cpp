//cntRow[i][j] 代表i行中以j结尾的连续1的区间长度 
//               |0                 if matrix[i][j] == 0
//cntRow[i][j] = |1                 if(j==0 && matrix[i][0] == 1)
//               | cntRow[i][j-1]+1 if(matrix[i][j] == 1 && j>0)
// ans[i][j] 代表第k列 cntRow[i][k]到cntRow[j][k] 中的最小值， 1的矩形面积就是minv*(j-i+1)
// 空间复杂度O(n^2)
//时间复杂度O(n^2*m)
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size();
		if (n == 0)
			return 0;
		int m = matrix[0].size();
		if (m == 0)
			return 0;
		vector<vector<int>> cntRow(n,vector<int>(m,0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
			    if(j==0 &&matrix[i][j]!='0')
			        cntRow[i][0] = 1;
				else if (j>0 && matrix[i][j] != '0')
					cntRow[i][j] = cntRow[i][j - 1] + 1;
			}
		}
		vector< vector<int>> ans(n, vector<int>(n,0));
		int ret = 0;
		for (int k = 0; k < m; ++k)
		{
			for (int i = 0; i < n; ++i){
				int minv = cntRow[i][k];
				ans[i][i] = minv;
				for (int j = i + 1; j < n; ++j){
					if (cntRow[j][k] < minv)
					{
						minv = cntRow[j][k];
					}
					ans[i][j] = minv;
				}
			}
			for (int i = 0; i < n; ++i){
				for (int j = i; j < n; ++j)
				{
					if (ans[i][j] * (j - i + 1) > ret)
						ret = ans[i][j] * (j - i + 1);
				}
			}
		}
		return ret;

	}
};
