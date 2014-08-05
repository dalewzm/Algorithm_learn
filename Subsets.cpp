//Subsets
//https://oj.leetcode.com/problems/subsets/
//先将集合排序，在深搜，把搜索的所有结果（包括中间）加入ans
//
//---------------------------------------------------
class Solution {
public:
	Solution()
	{
		visited = NULL;
		max = 0;
	}
	bool *visited;
	int max;
	vector<int> tmp;
	vector<vector<int>> ans;
	vector<vector<int> > subsets(vector<int> &S) {
		vector<int> voidV(0);
		ans.clear();
		ans.push_back(voidV);
		if (0 == S.size())
			return ans;
		sort(S.begin(), S.end());
		visited = new bool[S.size()+1];
		memset(visited, 0, S.size());
		max = S.size();
		dfs(0, S);
		delete[] visited;
		return ans;
	}
	void dfs(int curPos,vector<int> &s)
	{
		if (curPos < max)
		{
			for (int i = curPos; i < max; ++i)
			{
				
				if (!visited[i]){
					visited[i] = 1;
					tmp.clear();
					for (int j = 0; j < max; ++j)
					{
						if (visited[j])
							tmp.push_back(s[j]);
					}
					ans.push_back(tmp);
					dfs(i + 1, s);
					visited[i] = 0;
					
				}
				
			}
		}
	}
};
