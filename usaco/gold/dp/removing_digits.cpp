#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);

    dp[n] = 0;

    for (int i = n; i > 0; i--)
    {   
        if(i!=n && dp[i] == 1e9) continue;
        int cur = i;
        while(cur > 0){
            int digit = cur%10;
            dp[i-digit] = min(dp[i-digit], dp[i]+1);
            // cout << dp[i-digit] << endl;
            cur /= 10;
        }
    }
    
    cout << dp[0] << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}