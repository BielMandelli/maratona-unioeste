#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
int ans = 0, cur = 0;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int node){
    if(!visited[node]) {
        visited[node] = true;
        cur++;
    }
    else return;

    for (auto child : graph[node])
    {
        if(!visited[child]){
            dfs(child);
        }
    }
}   

signed main() {
    bieo;
    int n,m;
    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(n+1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            cur = 0;
            dfs(i);
            ans = max(ans, cur);
        }
    }
    
    cout << ans << endl;
        
    return 0;
}
