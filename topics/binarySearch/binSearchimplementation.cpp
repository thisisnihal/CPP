#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
using namespace std;
void solve()
{

	vector<int> v = {2, 3, 4, 5, 6, 7};
	int n = v.size();
	int x;
	cin >> x;

	/*
	 * Binary Search to find index of element x in array(or vector) v
	 *
	 */
	int lo = 0, hi = n - 1, mid;
	while (hi - lo > 1)
	{
		mid = (hi + lo) / 2;
		if (x > v[mid])
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	if (x == v[lo])
	{
		cout << lo << ed;
	}
	else if (x == v[hi])
	{
		cout << hi << ed;
	}
	else
	{
		cout << "Not Found" << ed;
	}
}
int main()
{
	int T = 1;
	// cin >> T;
	while (T--)
		solve();
	return 0;
}