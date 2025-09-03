#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i+1 < n && a[i+1][j] != '*') dp[i+1][j] = (dp[i][j] + dp[i+1][j]) % MOD;
            if(j+1 < n && a[i][j+1] != '*') dp[i][j+1] = (dp[i][j] + dp[i][j+1]) % MOD;
        }
    }
    
    cout << ((a[0][0] == '*') ? 0 : dp[n-1][n-1]) << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}