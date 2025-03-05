#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v, bestT = 1e9;
vector<vector<pair<int,int>>> graph;
set<pair<int, int>> visited;

void dfs(int node, int end, int price, int time){
    if(node == end){
        if(price <= v) bestT = min(bestT, time);
        return;
    }
    if(price > v or time >= bestT) return;

    for (int i = 1; i <= n; i++){
        if(graph[node][i].first != -1){
            pair<int, int> edge = {node, i};
            pair<int, int> edge2 = {i, node};

            if  (visited.count(edge) == 0) { 
                visited.insert(edge);
                visited.insert(edge2);
            
                dfs(i, end, price + graph[node][i].second, time + graph[node][i].first);

                visited.erase(edge); 
                visited.erase(edge2);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> n >> m;

    graph.resize(n+1, vector<pair<int,int>>(n+1, {-1, -1}));

    int x, y, a, b;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> a >> b;
        graph[x][y] = make_pair(a,b);
        graph[y][x] = make_pair(a,b);
    }

    int init, end;
    cin >> init >> end;

    dfs(init, end, 0, 0);

    if(bestT == 1e9) cout << -1 << endl;
    else cout << bestT << endl;

    return 0;
}