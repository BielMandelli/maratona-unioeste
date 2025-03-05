#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
vector<vector<int>> graph;
vector<int> d = {1, -1};
bool valid = false;

void dfs(int i, int j){
    if(graph[i][j]) return;
    if(i == m-1 && j == n-1) {
        valid = true;
        return;
    }
    if(!graph[i][j]) graph[i][j] = 1;

    if(i+1 < m && graph[i+1][j] == 0) dfs(i+1, j);
    if(i-1 >= 0 && graph[i-1][j] == 0) dfs(i-1, j);
    if(j+1 < n && graph[i][j+1] == 0) dfs(i, j+1);
    if(j-1 >= 0 && graph[i][j-1] == 0) dfs(i, j-1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    graph.resize(m, vector<int>(n, 0));

    int x, y;
    char dir;
    for (int i = 0; i < k; i++)
    {
        cin >> y >> x >> dir;
        x--; y--;

        if(dir == 'O') for (int j = 0; j <= y; j++) graph[x][j] = 1;
        else if(dir == 'L') for (int j = y; j < n; j++) graph[x][j] = 1;
        else if(dir == 'N') for (int j = 0; j <= x; j++) graph[j][y] = 1;
        else for (int j = x; j < m; j++) graph[j][y] = 1;
    }

    dfs(0, 0);
    if(valid) cout << "S" << endl;
    else cout << "N" << endl;
    
    return 0;
}