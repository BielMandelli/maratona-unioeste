#include <bits/stdc++.h>
#define int long long
using namespace std;
int m,n;
bool valid = true;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> teams;

void dfs(int node, int parent){
    visited[node] = true;
    for (auto &child : graph[node]){
        if(!visited[child]){
            teams[child] = !teams[node];
            dfs(child, node);
        } else if(teams[node] == teams[child]) {
            valid = false;
        }
    }
}

signed main() {
    cin >> n >> m;

    graph.resize(n+1);
    visited.resize(n+1, false);
    teams.resize(n+1, 0);

    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int sts = 1;
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]){
            teams[i] = !sts;
            dfs(i, 0);
            sts = !sts;
        }
    }
    
    if(valid){
        for (int i = 1; i <= n; i++)
        {
            cout << teams[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}