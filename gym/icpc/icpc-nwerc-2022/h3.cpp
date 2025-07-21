#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'
int n;
const int MAX = 2e5+5;
vector<vector<int>> g(MAX);

int ans;

vector<int> dfs(int v, int p) {
    vector<int> l, r;
    int cnt = 0;

    for (int u : g[v]) {
        if (u == p) continue;
        if (cnt == 0) l = dfs(u, v);
        else if (cnt == 1) r = dfs(u, v);
        cnt++;
    }

    vector<int> merge;
    if (l.size() > r.size()) swap(l, r);
    merge.push_back(1); 

    for (int i = 0; i < r.size(); ++i) {
        if(i <= l.size()){
            int x = r[i];
            if (i < l.size()) x += l[i];
            merge.push_back(x);
        } else ans += r[i];
    }

    return merge;
}

void solve() {
    int n; cin >> n;
    ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);

    cout << ans << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}
