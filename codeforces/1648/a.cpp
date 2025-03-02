#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;

    cin >> n >> m;
    vector<vector<int>> x(1e5+1), y(1e5+1);
    set<int> colors;

    int c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            x[c].push_back(i);
            y[c].push_back(j);
            colors.insert(c);
        }
    }
    
    int ans = 0;

    for (auto color : colors)
    {
        sort(x[color].begin(), x[color].end());
        sort(y[color].begin(), y[color].end());

        int qntd = x[color].size() - 1;
        for(int j = x[color].size()-1; j >= 0; j--){
            ans += x[color][j] * qntd;
            qntd -= 2;
        }

        qntd = y[color].size() - 1;
        for(int j = y[color].size()-1; j >= 0; j--){
            ans += y[color][j] * qntd;
            qntd -= 2;
        }
    }

    cout << ans << endl;
    
    return 0;
}