#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<double> p(n, 0);
    for (auto &x : p) cin >> x;

    vector<double> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j >= 0; j--)
        {
            dp[j] = p[i] * dp[j-1] + (1 - p[i]) * dp[j];
        }
    }

    
    double ans = 0.0;

    for (int i = (n+1)/2; i <= n ; i++)
    {
        ans += dp[i];
    }
    
    cout << setprecision(13) << fixed;
    cout << ans << endl;

    return 0;
}