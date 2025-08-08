#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int n, m, wx, wy;
vector<vector<int>> g;
vector<vector<bool>> visited;
vector<vector<int>> checkpoint;
int dx[4] = {-1, 1, 0, 0}; //N,S,L,O
int dy[4] = {0, 0, 1, -1}; //N,S,L,O

void dfs(int i, int j, int d){
    visited[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        if(i+dx[k] >= n or j+dy[k] >= m or i+dx[k] < 0 or j+dy[k] < 0) continue;
        if(!visited[i+dx[k]][j+dy[k]] && abs(g[i][j] - g[i + dx[k]][j + dy[k]]) <= d) {
            dfs(i + dx[k], j + dy[k], d); 
            visited[i][j] = true;
        }
    }
}

bool check(int mid){
    visited = vector<vector<bool>>(n, vector<bool>(m));

    dfs(wx, wy, mid);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(checkpoint[i][j] && !visited[i][j]) return false;
    
    return true;
}

void solve(){
    cin >> n >> m;
    g.resize(n, vector<int>(m));
    checkpoint.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> checkpoint[i][j];
            if(i == 0) {wx = i; wy = j;}
        }
    
    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    
    cout << l << endl;
}

signed main()
{
    // bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}