#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, components = 0, edge = 0, cycle = 0, tree = 0, verts = 0;
 
vector<bool> visited;
vector<vector<int>> graph;
 
int dfs(int node, int parent) {
    visited[node] = true;
    verts++;
    components++;
    for (auto child: graph[node]) {
        edge++;
        if(visited[child] == false) {
            dfs(child, node);
        } else if (child != parent) {
            cycle++;
        }
    }
 
    if(node == 1) edge /= 2;
    if(verts < 3) tree += 1;
    if(cycle >= 1 && components == edge) return 1;
    return 0;
}
 
signed main() {
    cin >> n >> m;
 
    graph.resize(n + 1);
    visited.resize(n + 1, false);
 
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
 
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    int ans = 0;
 
    for (int i = 1; i <= n; ++i) {
        verts = 0;
        if(visited[i] == false) {
            edge = 0;
            ans += dfs(i, 0);
        }
    }
    
 
    if(ans == 1 && !tree) cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;
 
    return 0;
}