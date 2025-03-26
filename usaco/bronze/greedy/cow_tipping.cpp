#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;
int n, ans = 0;
vector<vector<int>> c(n, vector<int>(n));

int solve(int x, int y){
    if(c[x][y]){
        for (int i = 0; i <= x; i++)
            for (int j = 0; j <= y; j++)
                c[i][j] = !c[i][j];

        return 1;
    }

    return 0;
}

signed main()
{
    fastio;
    cin >> n;
    c.resize(n, vector<int>(n));
   
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            c[i][j] = s[j] - '0';
        }
    }

    int x = n-1, y = n-1;
    while(x >= 0 && y >= 0){
        ans += solve(x, y);
        if(x != y){
            ans += solve(y, x);
        }

        if(x > 0){
            x--;
        } else{
            y--;
            x = y;
        }
    }

    cout << ans << endl;
    
    return 0;
}