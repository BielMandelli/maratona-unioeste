#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> ans;
vector<int> visited;

bool first;
int cur;
void dfs(int node){
    if(visited[node]) {
        cur = node+1;
        first = false;
        return;
    };
    if(!first) return;
    visited[node] = 1;

    for(auto c : g[node]){
        dfs(c);
        if(!first) break;
    }
}

void solve(){
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        g[i].push_back(x);
    }
    
    for (int i = 0; i < n; i++)
    {
        visited = vector<int>(n, 0);
        first = true;
        dfs(i);
        cout << cur << " ";
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