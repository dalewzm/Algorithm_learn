//递归在上一部基础上再末尾增加01，10，01，10，此份可以改进，n==1由n=0来构造，少一个判断
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ret;
			if (n <= 0) {
			ret.push_back(0);
			return ret;
		}
		if (n == 1)
		{
			ret.push_back(0);
			ret.push_back(1);
			return ret;
		}
		int add = 0;
		vector<int> last = grayCode(n - 1);
		for (int i = 0; i < last.size(); ++i)
		{
			int origin = last[i];
			ret.push_back( (origin << 1) + add);
			ret.push_back((origin << 1) + 1 - add);
			add = 1 - add;
		}
		return ret;

	}
};
