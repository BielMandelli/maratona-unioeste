#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main() {
    bieo;
    int n, m, k;
    cin >> n >> m >> k;

    set<int> special;
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        special.insert(x);
    }

    int ans = 1e14;

    for (auto [u, v, w] : edges) {
        if ((special.count(u) && !special.count(v)) || (!special.count(u) && special.count(v))) {
            ans = min(ans, w);
        }
    }

    if (ans == 1e14) cout << -1 << endl; 
    else cout << ans << endl;

    return 0;
}
