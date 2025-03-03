#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>> board;
vector<vector<array<int, 4>>> visited;
int n, m, ans = 0, stop = 0, pos;

void dfs(int i, int j, char side) {
    if(stop) return;

    pos = (side == 'U') ? 0 : (side == 'D') ? 1 : (side == 'R') ? 2 : 3;
    if(!visited[i][j][pos]) {
        bool isTrue = true;
        for (auto t : visited[i][j])
        {
            if(t) isTrue = false;
        }
        if(isTrue) ans++;
        visited[i][j][pos] = true;
    } else stop = 1;

    if(side == 'L'){
        if(j-1 >= 0 && board[i][j-1] != '#') dfs(i, j-1, 'L');
        else dfs(i, j, 'D');
    }
    else if(side == 'U'){
        if(i-1 >= 0 && board[i-1][j] != '#') dfs(i-1, j, 'U');
        else dfs(i, j, 'L');
    }
    else if(side == 'R'){
        if(j+1 < m && board[i][j+1] != '#') dfs(i, j+1, 'R');
        else dfs(i, j, 'U');
    }
    else {
        if(i+1 < n && board[i+1][j] != '#') dfs(i+1, j, 'D');
        else dfs(i, j, 'R');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    board.resize(n, vector<char>(m));
    visited.resize(n, vector<array<int, 4>>(m));

    int initI, initJ;
    char initSide;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] != '.' && board[i][j] != '#') {
                initI = i;
                initJ = j;
                initSide = board[i][j];
                board[i][j] = '.';
            }
        }
    
    dfs(initI, initJ, initSide);

    cout << ans << endl;

    return 0;
}
