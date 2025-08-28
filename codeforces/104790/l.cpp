#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

vector<vector<int>> g, g2;
vector<int> ord, comp;
vector<bool> v1, v2;

void dfs(int v) {
    if(v1[v]) return;
    v1[v] = true;
    for (auto u : g[v]) dfs(u);
    ord.push_back(v);
}

int cur = 0;
void dfs2(int v) {
    if(v2[v]) return;
    v2[v] = true;
    for (auto u : g2[v]) dfs2(u);
    comp[v] = cur;
}

signed main() {
    bieo;
    int n,m;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);
    v1.resize(n);
    v2.resize(n);
    comp.resize(n);
    
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g2[a].push_back(b); 
        g[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++) dfs(i);
    
    reverse(ord.begin(), ord.end());
    
    for (int i = 0; i < ord.size(); i++)
    {
        if(!v2[ord[i]]) cur++;
        dfs2(ord[i]);
    }
    
    int ans = 0;
    vector<int> cnt(cur);
    
    for (int i = 0; i < n; i++)
    {
        for (auto x : g[i])
        {
            if(comp[x] != comp[i]) cnt[comp[i]-1]++;
        }
    }
    
    for(auto c : cnt) ans += (c == 0);
    
    cout << ans << endl;

    return 0;
}
