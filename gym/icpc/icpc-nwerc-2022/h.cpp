#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'
int n;
const int MAX = 2e5+5;
vector<vector<int>> g(MAX);
vector<int> depth(MAX), req(MAX);

int calcDepth(int v, int parent){
    int maxd = 0;
    for(auto ch : g[v]){
        if(ch != parent){
            maxd = max(maxd ,calcDepth(ch, v));
        }
    }

    depth[v] = maxd+1;
    return depth[v];
}

void dfs(int v, int parent, int reqH) {
    req[v] = min(depth[v], reqH);

    vector<int> children;
    for (auto ch : g[v]) if (ch != parent) children.push_back(ch);
    
    if (children.size() == 2) {
        int l = children[0], r = children[1];

        dfs(l, v, min({depth[l], depth[r] + 1, req[v] - 1}));
        dfs(r, v, min({depth[r], depth[l] + 1, req[v] - 1}));
    } else if (children.size() == 1){
        int ch = children[0];
        dfs(ch, v, min(depth[ch], req[v] - 1));
    }
}

int remove(int v, int parent) {
    int ans = 0;
    bool isLeaf = true;
    for (auto ch : g[v]) {
        if (ch != parent) {
            isLeaf = false;
            ans += remove(ch, v);
        }
    }
    if (isLeaf && req[v] <= 0) return 1;
    return ans;
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    calcDepth(1, -1);
    dfs(1, -1, depth[1]);

    for(int i = 1; i <=n; i++) cout << req[i] << " == " << i << endl;

    int ans = remove(1, -1);
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