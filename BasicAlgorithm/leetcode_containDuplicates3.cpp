typedef struct Ele {
	long long int val;
	int pos;
	Ele() { val = 0, pos = 0; }
	Ele(int a, int b) :val(a), pos(b) {}
	bool operator < (const Ele& rhs)
	{
		if (val != rhs.val)
			return val < rhs.val;
		return pos < rhs.pos;
	}
}Ele;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		vector<Ele> eles;
		eles.resize(nums.size());
		if (nums.size()<=1 ||  k <= 0 || t<0)
			return false;
		for (int i = 0; i < nums.size(); ++i) {
			eles[i].val = nums[i];
			eles[i].pos = i;
		}
		sort(eles.begin(), eles.end());
		for (int i = 0; i < nums.size(); ++i)
		{
			int j = i + 1;
			while (j<nums.size() && eles[j].val - eles[i].val <= t)
			{
				if (abs(eles[j].pos - eles[i].pos) <= k)
					return true;
				++j;
			}
		}
		return false;
	}
};
