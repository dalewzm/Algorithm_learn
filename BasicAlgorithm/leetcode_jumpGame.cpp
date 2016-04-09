//通过维护一个最右边能调到的位置
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int r = 0;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (r<i)
				break;
			if ( nums[i] + i > r)
				r = nums[i] + i;
		}
		if (r < nums.size() - 1)
			return false;
		return true;
	}
};
