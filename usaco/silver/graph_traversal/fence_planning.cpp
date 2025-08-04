#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<pair<int,int>> p;
vector<int> visited;
int ans = 1e9;
pair<int,int> px, py;

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;

    px.first = min(p[node].first , px.first);
    px.second = max(p[node].first , px.second);

    py.first = min(p[node].second , py.first);
    py.second = max(p[node].second , py.second);

    for (auto ch : g[node]){
        if(!visited[ch]){
            dfs(ch);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    p.resize(n);
    
    for(auto &x : p) cin >> x.first >> x.second;

    g.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 0; i < n; i++) {
        if(!visited[i]){
            px = {1e9, 0};
            py = {1e9, 0};
            dfs(i);

            int b = px.second - px.first;
            int h = py.second - py.first;
            ans = min(2*(h+b), ans);
        }
    }
    
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