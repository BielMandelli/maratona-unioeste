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
    while (t--)
    {
        int x,y,z,k;
        cin >> x >> y >> z >> k;

        int ans = 0;
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if(k % (i*j)) continue;
                int c = k/(i*j);
                if(c > z) continue;
                int aux = (x - i + 1) * (y - j + 1) * (z - c + 1);
                ans = max(aux, ans);
            }
            
        }
        cout << ans << endl;
    }
    
    return 0;
}