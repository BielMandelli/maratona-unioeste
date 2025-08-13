#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'
int n, ans = 0;
vector<vector<int>> g;
vector<int> toLeaf, maxLength;

void dfs(int u, int p) {
  int best = 0, second = 0;
  for (int v : g[u]) if (v != p) {
    dfs(v, u);
    int val = toLeaf[v] + 1;
    if (val > best) { second = best; best = val; }
    else if (val > second) second = val;
  }
  toLeaf[u] = best;
  maxLength[u] = best + second;
  ans = max(ans, maxLength[u]);
}


void solve(){
    cin >> n;
    g.resize(n);
    toLeaf.resize(n);
    maxLength.resize(n);
    
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(0, -1);
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