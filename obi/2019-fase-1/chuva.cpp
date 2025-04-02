#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
vector<vector<char>> graph;
int n, m;

void dfs(int i, int j){
    graph[i][j] = 'o';
    if(i+1 < n && graph[i+1][j] == '#'){
        if(j-1 >= 0 && graph[i][j-1] != 'o') dfs(i, j-1);
        if(j+1 < m && graph[i][j+1] != 'o') dfs(i, j+1);
    } else {
        if(i+1 < n) dfs(i+1, j);
    }
}
 
signed main()
{
    bieo;
    cin >> n >> m;
    graph.resize(n, vector<char>(m));

    int si, sj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'o'){
                si = i;
                sj = j;
            }
        }
    
    dfs(si, sj);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << graph[i][j];
        cout << endl;
    }
        
        
}