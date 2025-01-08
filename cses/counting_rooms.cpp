#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m, rooms = 0;
 
int check(vector<vector<char>> &graph, int i, int j) {
    if(graph[i][j] == '#') return 0;
    graph[i][j] = '#';
 
    if(i-1 >= 0 && graph[i-1][j] == '.') check(graph, i-1, j);
    if(i+1 < n && graph[i+1][j] == '.') check(graph, i+1, j);
    if(j+1 < m && graph[i][j+1] == '.') check(graph, i, j+1);
    if(j-1 >= 0 && graph[i][j-1] == '.') check(graph, i, j-1);
 
    return 1;
}
 
signed main() {
 
    cin >> n >> m;
 
    vector<vector<char>> graph(n, vector<char>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rooms += check(graph, i, j);
            }
    }
 
 
    cout << rooms << endl;
}