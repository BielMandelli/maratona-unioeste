#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'


void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }

    set<int> cids, rids;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if(a[i][j] == mx) {
                cids.insert(j);
                rids.insert(i);
            }
        }
}

signed main()
{
    bieo;
    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}