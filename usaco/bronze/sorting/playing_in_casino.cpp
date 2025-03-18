#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }
        }

        int ans = 0, sum, cur = 0;
        for (int i = 0; i < m; i++)
        {
            sum = 0;
            vector<int> temp;

            for (int j = 0; j < n; j++)
            {
                sum += c[j][i];
                temp.push_back(c[j][i]);
            }

            cur = 0;
            sort(temp.begin(), temp.end());
            for (int j = 0; j < n; j++)
            {
                cur += temp[j];
                ans += abs((sum - cur) - (n - 1 - j) * temp[j]);
            }
        }
        
        cout << ans << endl;
    }

    
    return 0;
}