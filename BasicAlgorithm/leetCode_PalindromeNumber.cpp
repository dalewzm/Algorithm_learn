class Solution{
public:
	bool isPalindrome(int x){
		if (x < 0)
			return false;
		unsigned int b = x;
		unsigned int rev = 0;
		int t;
		while (x)
		{
			t = x % 10;
			x /= 10;
			rev = rev * 10 + t;
		}
		if (rev == b)
			return true;
		return false;
	}
};
