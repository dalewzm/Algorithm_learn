//从友上角开始检索
//目标比matrix[i][cols-1]大就往i++，这样就一直确定了哪一行
//确定了行，在确定对应的列，往左走
//优化方向：确定行和列采用二分
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		if (rows == 0)
			return false;
		int cols = matrix[0].size();
		int row = 0, col = cols - 1;
		bool find = false;
		while (row < rows && row >= 0 && col < cols && col >= 0){
			if (matrix[row][col] == target)
			{
				find = true;
				break;
			}
			else if (matrix[row][col] < target){
				if (col==cols -1)
					row++;
				else
					break;
			}
			else{
				col--;
			}
		}
		if (find)
			return true;
		return false;
	}
};
