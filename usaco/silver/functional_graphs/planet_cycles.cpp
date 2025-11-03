#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<int> g;        
vector<int> ans;     
vector<int> state;    

void dfs(int u) {
    if (state[u] == 2) return; 
    if (state[u] == 1) {
        int v = g[u];
        int tam = 1;
        while (v != u) {
            tam++;
            v = g[v];
        }
        v = u;
        ans[v] = tam;
        v = g[v];
        while (v != u) {
            ans[v] = tam;
            v = g[v];
        }
        state[u] = 2;
        return;
    }

    state[u] = 1;
    dfs(g[u]);
    if (ans[u] == -1) ans[u] = ans[g[u]] + 1; 
    state[u] = 2;
}

void solve() {
    int n;
    cin >> n;
    g.resize(n);
    ans.assign(n, -1);
    state.assign(n, 0);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        g[i] = x - 1;
    }

    for (int i = 0; i < n; i++) {
        if (!state[i]) dfs(i);
    }

    for (int x : ans) cout << x << " ";
    cout << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}