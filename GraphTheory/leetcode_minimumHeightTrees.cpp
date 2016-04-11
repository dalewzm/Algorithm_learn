//问题实际上是找图中的最长路，然后该路径取一半上的中间节点
//每轮从叶子节点开始，往前走一步
//然后删掉他们，找到新的节点
//留在最后的，只有最长路上的节点留到最后
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	    vector<int> ret;  
	   if(n <= 0)
		    return ret;
		if( n == 1)
		 {
		     ret.push_back(0);
		     return ret;
		 }
		vector<vector<int>> newedges(n, vector<int>());
		for (int i = 0; i < edges.size(); ++i)
		{
			newedges[edges[i].first].push_back(edges[i].second);
			newedges[edges[i].second].push_back(edges[i].first);
		}
		
		queue<int> nodeQueue;
		queue<int> sonNodeQueue;
		for (int i = 0; i < n; ++i)
		{
			if (newedges[i].size() == 1)
			{
				nodeQueue.push(i);
			}
		}
		int cur = 0;
		while (n > 2){
		    n -= nodeQueue.size();
			while (!nodeQueue.empty()){
				cur = nodeQueue.front();
				nodeQueue.pop();
				int par = newedges[cur][0];
				for (auto it = newedges[par].begin(); it != newedges[par].end(); ++it){
					if (*it == cur)
					{
						newedges[par].erase(it);
						break;
					}
				}
				if (newedges[par].size() == 1)
					sonNodeQueue.push(par);
			}
			nodeQueue.swap(sonNodeQueue);
		}
		if (nodeQueue.size() == 1){
			ret.push_back(nodeQueue.front());
		}
		else{
			ret.push_back(nodeQueue.front());
			nodeQueue.pop();
			ret.push_back(nodeQueue.front());
		}
		return ret;

	}
};
