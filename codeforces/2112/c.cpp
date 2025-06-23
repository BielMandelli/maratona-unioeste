#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;

    for (int i = 2; i < n; i++)
    {
        int mx = max(a[i], a[n - 1] - a[i]);

        vector<int> prefix(a.begin(), a.begin() + i);
        // for (auto x : prefix) cout << x << " ";
        // cout << endl;
        sort(prefix.begin(), prefix.end());

        for (int j = 0; j < i - 1; j++) {
            int mn = mx - prefix[j];
            // cout << "min " << mn << endl;
            int pos = upper_bound(prefix.begin() + j + 1, prefix.begin() + i, mn) - prefix.begin();
            // cout << "pos " << pos << endl;
            ans += i - pos;
        }
    }

    cout << ans << endl;
}

signed main()
{
    bieo;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}