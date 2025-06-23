#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<pair<int, int>> edges(n - 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges[i] = {u, v};
    }

    int center = -1;
    for (int i = 1; i <= n; ++i)
    {
        if ((int)tree[i].size() == n - 1){
            center = i;
            break;
        }
    }

    if (center == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (auto [u, v] : edges)
        {
            if (u == center) cout << u << " " << v << "\n";
            else if (v == center) cout << v << " " << u << "\n";
        }
    }
}

signed main()
{
    bieo;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}