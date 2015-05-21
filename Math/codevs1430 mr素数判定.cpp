#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int fastPower(int x, int n, int mod)
{
	int ans = 1;
	
	while (n)
	{
		if (n & 1)
		{
			ans = ans * x %mod;
		}
		x = x*x % mod;
		n >>= 1;
	}
	return ans;
}

bool check_n(int a, int n)
{
	//n is odd
	int i=1, u=n-1;
	while ((u & 1)==0)
	{
		i += 1;
		u >>= 1;
	}
	int x0 = fastPower(a,u,n);
	int x1;
	for (int j = 1; j <= i; ++j)
	{
		x1 = x0*x0 %n;
		if (x1 == 1 && x0 != 1 && x0 != n - 1)
			return false;
		
		x0 = x1;
		x1 = x0*x0 %n;
	}
	if (x1 != 1)
		return false;
	return true;
}

bool checkPrime(int n)
{
	srand((unsigned)time(0));
	
	for (int i = 0; i < 5; ++i)
	{
		int randt = rand() % (n - 1) + 1;
		if (!check_n(randt, n))
			return false;
	}
	return true;
}

int main()
{
	int n;

	cin >> n;
	if ( (n & 1) == 0 && n > 2)
		cout << "\\n";
	else{
		if (n == 2)
			cout << "\\t";
		else if (n == 1)
			cout << "\\n";
		else if (checkPrime(n))
			cout << "\\t";
		else
			cout << "\\n";
	}
}