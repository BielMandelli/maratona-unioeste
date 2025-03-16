#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;
vector<vector<int>> graph;
vector<bool> visited(1e5, false);

void dfs(int parent, int node){
    if(!visited[node]) visited[node] = true;

    for (auto child : graph[node]){
        if(!visited[child]){
            dfs(node, child);
        }
    }
}

signed main(){
    fastio;
    int n;
    cin >> n;

    graph.resize(n+1);
    
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        graph[i].push_back(p[i]);
        graph[p[i]].push_back(i);
    }
    
    int tree = 0;
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            dfs(0, i);
            tree++;
        }
    }
    
    cout << tree << endl;

    return 0;
} 