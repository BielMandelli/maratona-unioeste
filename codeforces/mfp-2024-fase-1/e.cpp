#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

struct Host {
    int x, y, id;

    bool operator<(const Host &a) const {
        return tie(x, y) < tie(a.x, a.y);
    }
};

vector<Host> h;
vector<vector<int>> g;
vector<int> dsu;

double calc (Host h1, Host h2){
    int dx = h1.x - h2.x;
    int dy = h1.y - h2.y;
    return dx * dx + dy * dy;
}

void dfs(int node, int group){
    if(!dsu[node]) dsu[node] = group;
    else return;

    for(auto child : g[node]){
        dfs(child, group);
    }
}

signed main() {
    bieo;

    int n, q, d;
    cin >> n >> q >> d;

    h.resize(n);
    g.resize(n+1);
    dsu.resize(n+1);

    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> h[i].x >> h[i].y;
        h[i].id = i+1;
    }
    
    sort(h.begin(), h.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if ((h[j].x - h[i].x) > d) break; 
            if (calc(h[i], h[j]) <= d*d) {
                g[h[i].id].push_back(h[j].id);
                g[h[j].id].push_back(h[i].id);
            }
        }
    }

    for (int i = 1, j = 1; i <= n; i++)
    {
        for(auto child : g[i]){
            // cout << "pai " << i << " filho " << child << endl;
        }
    }
    
    for (int i = 1, j = 1; i <= n; i++)
    {
        if(!dsu[i]){
            dfs(i, j);
            j++;
        }
    }
    
    while(q--){
        int a,b;
        cin >> a >> b;

        // cout << dsu[a] << " " << dsu[b] << endl;
        if(dsu[a] != dsu[b]) cout << "N" << endl;
        else cout << "S" << endl;
    }
        
    return 0;
}
