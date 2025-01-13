#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
 
signed main() {
    int N;  

    cin >> N;

    vector<int> dp(N + 1, 0);  
    dp[0] = 1;  

    for (int s = 1; s <= N; s++) {
        for (int x = 1; x <= 6; x++) {
            if (s - x >= 0) {
                dp[s] = (dp[s] + dp[s - x]) % MOD;  
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
