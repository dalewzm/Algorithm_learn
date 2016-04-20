//每次处理最外层
//用左上点和右下点代表最外层
//然后左上点 往右下移
class Solution {
    public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<int> ret;
		if (n == 0)
			return ret;
		int m = matrix[0].size();
		int stx = 0, sty = 0;
		int edx = n - 1, edy = m - 1;
		
		while (stx <= edx && sty<=edy){
			for (int i = sty; i <= edy; ++i)
				ret.push_back(matrix[stx][i]);
			for (int i = stx+1; i <= edx; ++i)
				ret.push_back(matrix[i][edy]);
			if(edx>stx)
			for (int i = edy - 1; i >= sty; --i)
				ret.push_back(matrix[edx][i]);
			if(edy>sty)
			for (int i = edx - 1; i > sty; --i)
				ret.push_back(matrix[i][sty]);
			stx++;
			sty++;
			edx--;
			edy--;
		}
		return ret;
	}
};