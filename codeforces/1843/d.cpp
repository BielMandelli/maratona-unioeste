#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> graph;
vector<int> leafs;
int n;

void dfs(int node, int parent) {
    if(graph[node].size() == 1 && graph[node][0] == parent){
        leafs[node] = 1;
    } else {
        for (auto child : graph[node]){
            if(child != parent){
                dfs(child, node);
                leafs[node] += leafs[child];
            }
        }
    }
}
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int q, x, y;
        cin >> n;

        leafs.resize(n+1, 0);
        graph.resize(n+1, vector<int>());

        for (int i = 0; i < n-1; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        dfs(1, 0);
        cin >> q;

        for (int i = 0; i < q; i++) {
            cin >> x >> y;

            cout << leafs[x] * leafs[y] << endl;
        }
        
        graph.clear();
        leafs.clear();
    }

    return 0;
}