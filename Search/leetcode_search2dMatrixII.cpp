//右上角开始搜索，右上角(i,j) 代表了一个矩形区域 
//(i,  0)-------(i,j)
//|               |
//|               |
//(n-1,0)------(n-1,j)
//初始化 i=o,j=m-1(nXm矩阵);
//如果tar < m[i][j],则j所在列可以抛弃
// j--;
//如果 tar > m[i][j],则i所在行可以抛弃,因为i，j已经在当前行最右端
// i++;
//总复杂度O(n+m)
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (0 == n)
			return false;
		int m = matrix[0].size();
		int i = 0, j = m - 1;
		bool find = false;
		for (; i < n && j >= 0;){
			if (matrix[i][j] == target){
				find = true;
				break;
			}
			else if (matrix[i][j]>target)
				j--;
			else
				i++;
		}
		if (find)
			return true;
		return false;
	}
};
