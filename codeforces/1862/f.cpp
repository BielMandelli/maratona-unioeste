#include <bits/stdc++.h>
#define int long long
const int MAXX = 1e17;
using namespace std;

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int w, f, n, sumS = 0;

        cin >> w >> f >> n;

        vector<int> monsters(n);
        for (int i = 0; i < n; i++)
        {
            cin >> monsters[i];
            sumS += monsters[i];
        }
        
        vector<bool> dp(sumS+1);
        dp[0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int water = sumS; water - monsters[i] >= 0; water--) dp[water] = dp[water] or dp[water - monsters[i]];
        }

        int ans = 1e10;
        for (int i = 0; i <= sumS; i++)
        {
            if(dp[i]) ans = min(ans, max((w + i - 1) / w, (sumS - i + f - 1)/f));
            
        }
        
        cout << ans << endl;
    }

    return 0;
}