#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> odd, visited;
vector<pair<int,int>> ans;
int n, m, timer = 1;

void dfs(int node, int parent){
    visited[node] = timer++;
    for(auto ch : g[node]){
        if(ch != parent){
            if(!visited[ch]){
                dfs(ch, node);
                if(odd[ch]) {
                    ans.push_back({ch, node});
                    odd[ch] = 0;
                } else {
                    ans.push_back({node, ch});
                    odd[node] ^= 1;
                }
            } else if(visited[node] > visited[ch]){
                ans.push_back({node, ch});
                odd[node] ^= 1;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1);
    odd.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++)
        if(!visited[i]) dfs(i, 0);
    
    int sum = 0;
    for(auto x : odd) sum += x; 
    if(sum) cout << "IMPOSSIBLE" << endl;
    else for(auto [u,v] : ans) cout << u << " " << v << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}