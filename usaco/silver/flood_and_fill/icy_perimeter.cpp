#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int n;
vector<vector<char>> g;
vector<vector<bool>> visited;
int dx[4] = {-1, 1, 0, 0}; //N,S,L,O
int dy[4] = {0, 0, 1, -1}; //N,S,L,O

int perimeter, area;
void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = true;
    area++;
    int sides = 4;
    for (int k = 0; k < 4; k++)
    {
        if(i+dx[k] >= n or j+dy[k] >= n or i+dx[k] < 0 or j+dy[k] < 0) continue;
        if(g[i + dx[k]][j + dy[k]] == '#') {
            sides--;
            dfs(i + dx[k], j + dy[k]); 
        }
    }
    perimeter += sides;
}

void solve(){
    cin >> n;
    g.resize(n, vector<char>(n));
    visited.resize(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    
    int ansperimeter = 0, ansarea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            perimeter = 0, area = 0;
            if(g[i][j] != '.') dfs(i, j);
            if(area == ansarea) ansperimeter = min(perimeter, ansperimeter);
            else if(area > ansarea) {ansarea = area; ansperimeter = perimeter;}
        }
    }
    
    cout << ansarea << " " << ansperimeter << endl;
}

signed main()
{
    // bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}