#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n, W;
    cin >> n >> W;

    int k = n/2 - 1; 

    vector<pair<int, int>> e;

    for (int i = 0; i < n; i++)
    {
        int w, q;
        w = (W >= 5000 ? i : 1e4 - i);
        q = (i <= k ? k-i : i);
        e.push_back({w,q});
    }

    for (auto [w, q] : e) cout << w << ' ' << q << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}