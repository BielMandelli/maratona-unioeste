#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> g, g2;
vector<bool> visited;
vector<pair<int,int>> grp;
bool valid = true;

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;

    for(auto ch : g[node]){
        if(!visited[ch])dfs(ch);
    }
}

void dfs2(int node){
    if(visited[node]) return;
    visited[node] = true;

    for(auto ch : g2[node]){
        if(!visited[ch]) dfs2(ch);
    }
}

void solve(){
    int n,m;
    cin >> n >> m;

    g.resize(n);
    g2.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g2[y].push_back(x);
    }

    dfs(0);
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            cout << "NO" << endl << 1 << " " << i+1 << endl;
            return;
        }
    }

    visited.clear();
    visited.resize(n);

    dfs2(0);
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            cout << "NO" << endl << i+1 << " " << 1 << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}