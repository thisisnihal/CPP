long long f(int x, vector<int>& coins) {
//     if (x == 0) return 1;
//     if (dp[x] != -1) return 1;
//     long long ways = 0;
//     for (int coin : coins)
//     {   
//         if (x-coin >= 0) ways += f(x-coin, coins);
//     }

//     return dp[x] = ways % M;
// }