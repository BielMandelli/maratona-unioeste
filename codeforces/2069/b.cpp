#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> tab(n, vector<int>(m));
        unordered_map<int, int> color; 

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> tab[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (color[tab[i][j]] == 2) continue;

                if ((i + 1 < n && tab[i][j] == tab[i + 1][j]) ||
                    (j + 1 < m && tab[i][j] == tab[i][j + 1]) ||
                    (j - 1 >= 0 && tab[i][j] == tab[i][j - 1]) ||
                    (i - 1 >= 0 && tab[i][j] == tab[i - 1][j])) {
                    color[tab[i][j]] = 2;
                } else {
                    color[tab[i][j]] = 1;
                }
            }

        int ans = 0, maxColor = 0;
        for (auto p : color) {
            maxColor = max(maxColor, p.second);
            ans += p.second;
        }

        ans -= maxColor;

        cout << ans << endl;
    }

    return 0;
}