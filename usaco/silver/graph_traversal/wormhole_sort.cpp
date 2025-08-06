#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<pair<int,int>>> g;
vector<int> visited;

bool isOrder(vector<int> &p){
    for (int i = 0; i < (int)p.size(); i++) if(i+1 != p[i]) return false;
    return true;
}

void dfs(int u, int k, int grp){
    visited[u] = grp;
    for(auto ch : g[u]){
        auto [v, w] = ch;
        if(visited[v] == 0 && w >= k) dfs(v, k , grp);
    }
}

bool check(vector<int> &p, int k){
    int n = p.size();
    visited.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        if(visited[i] != 0) continue;
        dfs(i, k, i+1);
    }

    for (int i = 0; i < n; i++) if(visited[p[i]-1] != visited[i]) return false;
    return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto &x : p) cin >> x;

    g.assign(n, {});
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        mx = max(w, mx);
    }

    if(isOrder(p)) {
        cout << -1 << endl;
        return;
    }

    int l = 1, r = mx, mid;
    while (l < r) {
        mid = (l + r + 1) / 2; 
        if (check(p, mid)) {
            l = mid;      
        } else {
            r = mid - 1;  
        }
    }   
    
    cout << l << endl;
}

signed main()
{
    bieo;
    int t=1;
    while (t--) solve();
    return 0;
}
