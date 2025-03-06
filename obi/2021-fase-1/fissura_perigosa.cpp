#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;
int n, f;
vector<vector<char>> eru;

void dfs(int i, int j){
    if(eru[i][j] == '*') return;

    eru[i][j] = '*';

    if(i+1 < n && eru[i+1][j] - '0' <= f) dfs(i+1, j);
    if(j+1 < n && eru[i][j+1] - '0' <= f) dfs(i, j+1);
    if(i-1 > -1 && eru[i-1][j] - '0' <= f) dfs(i-1, j);
    if(j-1 > -1 && eru[i][j-1] - '0' <= f) dfs(i, j-1);
}

signed main(){
    fastio;
    
    cin >> n >> f;
    eru.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            eru[i][j] = s[j];
        }
    }

    if(eru[0][0] - '0' <= f) dfs(0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << eru[i][j];
        }
        cout << endl;
    }


    
}