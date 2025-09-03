#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(dp[i], dp[i-1] + abs(a[i] - a[i-1]));
        if(i-2 >= 0) dp[i] = min(dp[i], dp[i-2] + abs(a[i] - a[i-2]));
    }
    
    cout << dp[n-1] << endl;
} 

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}