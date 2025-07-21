#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(auto &x : a) cin >> x.first >> x.second;

    sort(a.begin(), a.end());
    int ans = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        time += a[i].first;
        ans += a[i].second - time;
    }
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}