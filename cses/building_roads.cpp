#include <bits/stdc++.h>
#define int long long
using namespace std;
 
vector<vector<int>> graph(2e5);
vector<bool> visited(2e5, false);
vector<int> bridges;
 
void dfs(int node) {
    visited[node] = true;
    for (auto child: graph[node]) {
        if(visited[child] == false) {
            dfs(child);
        }
    }
}
 
signed main() {
    int n,m;
    cin >> n >> m;
 
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
 
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    for (int i = 1; i <= n; ++i) {
        if(visited[i] == false) {
            bridges.push_back(i);
            dfs(i);
        }
    }
 
    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; ++i) {
        cout << bridges[i] << " " << bridges[i+1] << endl;
    }
}
