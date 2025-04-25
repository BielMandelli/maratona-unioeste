#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
const int MOD = 1000000007;

signed main() {
    bieo;
    int n, k;
    vector<vector<int>> dp(2010,vector<int>(2010));
    cin >> n >> k;

    for (int i = 1; i <= 2000; i++) dp[1][i] = 1;
    
    for (int l = 1; l <= (k-1); l++)
    {
        for (int i = 1; i <= n; i++)
        {
           for (int j = 1; j*i <= n; j++) dp[l+1][j*i] = (dp[l+1][j*i] + dp[l][i]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[k][i]) % MOD;
    
    cout << ans << endl;

    return 0;
}
