    #include <bits/stdc++.h>
    #define int long long
    using namespace std;
    const int MOD = 1e9 + 7;
    
    signed main() {
        int n, x;  

        cin >> n >> x;

        vector<int> coins(n, 0);

        for (auto &x : coins) cin >> x;

        vector<int> dp(1e6, 0);
        dp[0] = 1;  

        for (int s = 1; s <= x; s++) {
            for (int j = 0; j < n; j++) {
                if (s - coins[j] >= 0) {
                    dp[s] = (dp[s] + dp[s - coins[j]]) % MOD;  
                }
            }
        }

        cout << dp[x] << endl;

        return 0;
    }
