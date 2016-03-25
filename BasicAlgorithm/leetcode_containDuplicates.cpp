class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> hashTabs;
		int cnt = 0;
		for (auto i = nums.begin(); i != nums.end(); ++i) {
			if (hashTabs.find(*i) != hashTabs.end())
				return true;
			hashTabs[*i] = cnt++;
		}
		return false;
	}
};
