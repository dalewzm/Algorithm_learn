class Solution {
public:
	void swap(int &a, int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	void init()
	{
		par.clear();
		rank.clear();
		par.resize(n, 0);
		rank.resize(n, 0);
		for(int i=0; i<n; ++i)
		 {par[i] = i;
		 rank[i] = 1;
		 }

	}
	void un(int a, int b)
	{
		int x = find(a);
		int y = find(b);
		if (x != y){
			if (rank[x] < rank[y])
			{
				par[x] = y;
			}
			else{
				par[y] = x;
				if (rank[x] == rank[y])
					rank[x]++;
			}
		}
	}
	int find(int p)
	{
		if (par[p] != p)
			par[p] = find(par[p]);
		return par[p];
	}

	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> hashTab;
		n = nums.size();
		
		for (int i = 0; i < n; ++i)
		{
			if (hashTab.find(nums[i]) == hashTab.end())
				hashTab[nums[i]] = i;
			else{
				swap(nums[i], nums[--n]);
				i--;
			}
		}

		init();

		for (int i = 0; i <  n; ++i)
		{
			if (hashTab.count(nums[i] + 1)>0)
			{
				un(i, hashTab[nums[i] + 1]);
			}
		}
		for (int i = 0; i < n; ++i)
			rank[i] = 0;
		for (int i = 0; i < n; ++i){
			rank[find(i)]++;
		}
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			if (rank[i] > ret)
				ret = rank[i];
		}
		return ret;

	}

	vector<int> par;
	vector<int> rank;
	int n;
};
