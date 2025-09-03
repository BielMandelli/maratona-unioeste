#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

void solve(){
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> dp(s+1, 0);

    dp[0] = 1;

    for (auto c : a)
    {
        for(int i = 1; i<= s; i++){
            if(i-c >= 0) {
                dp[i] = (dp[i] + dp[i-c]) % MOD; 
            }
        }
    }
    
    cout << dp[s] << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}