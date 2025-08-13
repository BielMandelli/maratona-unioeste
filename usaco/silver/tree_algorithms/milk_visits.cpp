#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> c, visited;
int n,m,comp=1;
string s;

void dfs(int node){
    char type = s[node-1];
    c[node] = comp;
    for(auto ch: g[node]){
        if(s[ch-1] == type && !c[ch]) dfs(ch);
    } 
}

void solve(){
    cin >> n >> m >> s;
    
    g.resize(n+1);
    visited.resize(n+1);
    c.resize(n+1);
    
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(!c[i]){ 
            dfs(i);
            comp++;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        if(c[u] == c[v]) cout << (s[u-1] == ch);
        else cout << 1;
    }
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