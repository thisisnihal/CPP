#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-18 16:54:11 */
using namespace std;


// check again.. is it working?

const int N = 1e6+10;
const int M = 1e9+7;
long long fact[N];

void precompute() {
    fact[0] =1;
    for (int i =1; i < N; i++)
        fact[i] = (fact[i-1]*1LL*i) % M;
}
int binexp(int a, int b, int M) {
    int ans = 1;
    while(b) {
        if (b&1) ans = (ans * 1LL * a) % M;
        a = (a*1LL*a)%M;
        b >>= 1;
    }
    return ans;
}
int main()
{
    precompute();
    int q;
    cin >> q;
    while(q--) {
        int n, r;
        cin >> n >> r;
        long long num = fact[n];
        long long den = (fact[n-r] * 1LL * fact[r]) % M;
        long long ncr = num * binexp(den, M-2, M);
        cout << ncr << ed;
    }
    return 0;
}



/*



// QUESTION

https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count

// SOLUTION


#include <bits/stdc++.h>
using namespace std;












int binexp(int a, int b, int m) {
    int ans = 1;
    while(b) {
        if (b&1) ans = (ans * 1LL * a) % m;
        a = (a*1LL*a) % m;
        b >>= 1;
    }
    return ans;
}

const int M = 1e9+7;

int main(){
	int MAX = 1e5+10;
	int fact[MAX];
	fact[0] = 1;
	for (int i = 1; i < MAX; i++)
		fact[i] = (fact[i-1] * 1LL * i) % M;
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		int num = (fact[n] * 1LL * fact[k]) % M;
		int den = (fact[k-n] * 1LL * fact[n]) % M;
		int ans = (num * 1LL * binexp(den, M-2, M)) % M;
		cout << ans << endl;
	}
}


*/