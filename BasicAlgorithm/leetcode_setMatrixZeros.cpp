//用一个变量来储存第一列是否来清零的状况
//然后没一行行首和每一列列首 分别储存相应的行和列是否要清楚的状态
//即用一个变量存一行状态，用矩阵自身(n+m)空间储存整个矩阵状态，实现O(1)额外空间
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if (0 == n)
			return;
		int m = matrix[0].size();
		int col = 1;
		for (int i = 0; i < n; ++i){
			if (matrix[i][0] == 0){
				col = 0;
				break;
			}
		}
		for (int i = 0; i < n; ++i){
			for (int j = 1; j < m; ++j){
				if (matrix[i][j] == 0)
					matrix[0][j] = matrix[i][0] = 0;
			}

		}

		for (int i = n - 1; i >= 0; --i){
			for (int j = m - 1; j >= 1; --j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
			if (col == 0)
				matrix[i][0] = 0;
		}
	}
};
