#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
// #define int long long
#define endl '\n'

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for(auto &c : h) cin >> c;
    for(auto &c : s) cin >> c;

    vector<vector<int>> dp(n+1, vector<int> (x+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(h[i-1] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-h[i-1]] + s[i-1]);
        }
    }
    
    cout << dp[n][x] << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}