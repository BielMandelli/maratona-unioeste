#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> e(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> e[i][j];
    
    int p, x, y, ans = 0;
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        cin >> x >> y;
        if(e[x-1][y-1] > 0){
            e[x-1][y-1]--;
            ans++;
        } 
    }

    cout << ans << endl;

    return 0;
}