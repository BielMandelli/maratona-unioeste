#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
#define int long long
using namespace std;

signed main() {
    int n,k;
    cin >> n >> k;

    vector<int> dp(n+1, 0);
    vector<int> base(n+1, 0);

    base[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        base[i] = (2*base[i-1])%MOD;
    }

    for (int i = 1; i <= n; i++)
    {
        if(i < k) dp[i] = base[i];
        else if(i == k) dp[i] = base[i] - 1;
        else {
            for (int j = 1; j <= k; j++)
            {
                dp[i] = (dp[i]+dp[i-j])%MOD;
            }
        }
    }
    
    cout << dp[n] << endl;

    return 0; 
}