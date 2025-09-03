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

    vector<int> dp(s+1, 1e9);

    dp[0] = 0;

    for (int i = 1; i <= s; i++)
    {
        for(auto c : a){
            if(i-c >= 0) dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    
    cout << (dp[s] == 1e9 ? -1 : dp[s]) << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}