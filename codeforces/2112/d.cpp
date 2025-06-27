#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> tree;
vector<bool> visited;
set<pair<int,int>> ans;

void dfs(int node, bool dir){
    visited[node] = true;
    for(auto child : tree[node]){
        if(visited[child]) continue;

        if(dir) ans.insert({child, node});
        else ans.insert({node, child});

        dfs(child, !dir);
    }
}

void solve()
{
    tree.clear();
    visited.clear();
    int n;
    cin >> n;
    tree.resize(n);
    visited.resize(n);
    // for (int i = 0; i < n; ++i) tree[i].clear();

    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;

        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int r = 0;
    while (r < n && tree[r].size() != 2) r++;

    if(r >= n) {
        cout << "NO" << endl;
        return;
    }

    ans.clear();
    ans.insert({r, tree[r][0]});
	ans.insert({tree[r][1], r});
    visited[r] = true;

    dfs(tree[r][0], true);
	dfs(tree[r][1], false);

    cout << "YES" << endl;
    for(auto [u, v] : ans) cout << u+1 << " " << v+1 << endl;

}

signed main()
{
    bieo;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}