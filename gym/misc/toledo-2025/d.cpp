#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

vector<vector<int>> g;
vector<int> visited;
int n, c, s;
bool can = true;

void dfs(int u, int parent, int f, int cur){
    if(visited[u]) {
        if(visited[u] != cur) can = false;
        return;
    }
    
    visited[u] = true;
    if(!f) return;

    for(auto ch : g[u]){
        if(ch != parent && f) dfs(ch, u, f-1, cur);
    }
}

void solve(){
    cin >> n >> c >> s;
    g.resize(n+1);
    visited.resize(n+1);

    for (int i = 0; i < c; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<int,int>> sol(s);
    
    for (int i = 0; i < s; i++) {
        if(!can) break;
        cin >> sol[i].first >> sol[i].second;
        dfs(sol[i].first, -1, sol[i].second, sol[i].first);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) can = false;
    }
    
    cout << (can ? "Sim" : "Nao") << endl;
}

signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}