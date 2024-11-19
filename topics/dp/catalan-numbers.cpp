#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-07-08 19:26:46 */
using namespace std;


int cat[100];

int catalan(int n, int k) {

    if (cat[k] != -1) return cat[k];



    return catalan(n, k) * catalan(n, n-1-k);
}



int main()
{
    memset(cat, -1, sizeof(cat));
    cat[0] = cat[1] = 1;

    int n;
    cin >> n;

    unsigned long long cat = 1;
 
    // For the first number
    cout << cat << " "; // C(0)
 
    // Iterate till N
    for (unsigned long long i = 1; i <= n; i++) {
        cat *= (4 * i - 2);
        cat /= (i + 1);
        cout << cat << " ";
    }
    
    




    
    return 0;
}