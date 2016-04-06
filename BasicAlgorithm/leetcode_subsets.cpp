//n个数的子集是由n-1个数的子集集合构造，每个子集后面加上第n个数
// 2 [[] [1] [2] [1 2]]
// 3  [[] [3] [1] [1 3] [2] [2 3] [1 2] [1 2 3]]
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() == 0)
		{
			vector<int> emptyVector;
			ret.push_back(emptyVector);
			return ret;
		}
		vector<int> input(nums.begin(), nums.end() - 1);
		vector<vector<int>> subs = subsets(input);
	    ret = subs;
		for (int i = 0; i < subs.size(); ++i)
		{
			input = subs[i];
			input.push_back(nums[nums.size()-1]);
			sort(input.begin(),input.end());
			ret.push_back(input);
		}
		return ret;
	}
};
