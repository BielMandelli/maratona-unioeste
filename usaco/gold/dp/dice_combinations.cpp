#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if(i-j>=0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }
    
    cout << dp[n] << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}