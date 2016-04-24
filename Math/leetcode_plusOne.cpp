//高精度加法简易模拟版

//更高效解法，不需要翻转两次，如果需要增加位数，必定是999这种形式，结果是1000,首位置1，后面补0即可
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ret(digits);
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (ret[i] == 9)
			{
				ret[i] = 0;
			}
			else{
			    ret[i]++;
				return ret;
			}
		}
		ret[0] = 1;
		ret.push_back(0);
		return ret;
	}
};
