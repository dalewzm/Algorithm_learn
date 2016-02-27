//Binarysearch
class Solution {
public:
	bool isAns(long long r, long long x)
	{
		if (r*r<=x && (r + 1)*(r + 1)>x)
			return true;
		return false;
	}
	int mySqrt(int x) {
		if (x <= 0)
			return 0;
			long tar = x;
		long long  low = 0,high= x;
		long long mid = low + (high - low) / 2;
		while (!isAns(mid, tar))
		{
			if ((mid + 1)*(mid + 1) <= tar)
			{
				low = mid+1;
			}
			else{
				high = mid-1;
			}
			mid = low + (high - low) / 2;
		}
		return mid;
	}
};
